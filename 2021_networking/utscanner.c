#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <pthread.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

#define port_max 65536

struct ip *ipp;                            //ip
struct icmp *icmpp;                        //icmp
int ports[port_max];                       //端口
int port_low = 0;                          //起始端口
int port_high = 100;                       //结束端口
char ipaddr[100] = "127.0.0.1";            //ip地址

void udpsend(int fd , int port , struct sockaddr_in servaddr)
{
    char buf[1024];
    if(sendto(fd,buf,sizeof(buf),0,(struct sockaddr*)&servaddr , sizeof(servaddr))<0)
    {
        perror("**********sendto failed**********");
    }
}

int udprecv(int fd)
{
    struct timeval poll;
    poll.tv_sec = 1;
    poll.tv_usec = 0;
    int iplen;
    char buf[1024];

    fd_set fds;
    while(1)
    {
        FD_ZERO(&fds);
        FD_SET(fd,&fds);
        
        if(select(fd+1,&fds,NULL,NULL,&poll)>0) //select会更新fd_set
        {
            recvfrom(fd,&buf,sizeof(buf),0x0,NULL,NULL);
        }
        else if(!FD_ISSET(fd,&fds))
        {
            return 1;
        }
        else{
            perror("*********recv failed**********");
        }

        ipp = (struct ip *)buf;
        iplen = ipp->ip_hl << 2;

        icmpp = (struct icmp*)(buf+iplen);

        if((icmpp->icmp_type == ICMP_UNREACH) && (icmpp->icmp_code == ICMP_UNREACH_PORT))
            return 0;
    }
}

int udp_scan(int portnum ,struct sockaddr_in servaddr)
{
    int sendfd , recvfd;
    struct servent* appl_name;
    if((sendfd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP))<0)
    {
        perror("*******socket udp failed*******");
        exit(-1);
    }
    if((recvfd = socket(AF_INET,SOCK_RAW,IPPROTO_ICMP))<0)
    {
        perror("*******socket icmp failed*******");
        exit(-1);
    }

    udpsend(sendfd,portnum,servaddr);
    if(udprecv(recvfd) == 1)
    {
        appl_name = getservbyport(htons(portnum),"udp");
        if(appl_name != NULL)
        {
            return 1;
        }
    }
    close(sendfd);
    close(recvfd);
    return 0;
}

void *scan_port(void* portptr)
{
    int port_id = *((int *)portptr);
    
    struct sockaddr_in servaddr;
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port_id);
    servaddr.sin_addr.s_addr = inet_addr(ipaddr);

    int sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(sockfd < 0) 
    {
        perror("Error encountered when creating socket endpoint.");
        exit(-1);
    }
    int port_status = connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    close(sockfd);
    if(port_status < 0)
    {
        //udp scan
        if(udp_scan(port_id,servaddr)==1)
        {
            port_status = 1;
        }
    }
    if(port_status>=0)
        printf("%d Open , Protocal : %s\n", port_id , port_status == 1 ? "UDP" : "TCP");
    return 0;
}
    

int main(int argc , const char *argv[])
{
    if(argc < 2)
    {
        printf("Error\n");
        printf("Format: ./scan <ip> <portlow> <porthigh> <whether show only open>\n");
    }
    else if(argc < 3)
    {
        strcpy(ipaddr,argv[1]);
        printf("Warning: No PORT , Default: from 0 to 100\n");
    }
    else if(argc < 4)
    {
        strcpy(ipaddr,argv[1]);
        port_low = atoi(argv[2]);
        printf("Warning:No port_high , Default : 100");
        if(port_low > port_high) port_high = port_low+100;
    }
    else
    {
        strcpy(ipaddr,argv[1]);
        port_low = atoi(argv[2]);
        port_high = atoi(argv[3]);
        if(port_low > port_high)
        {
            printf("Port_low is higher! Default: port_high = port_low + 100\n");
            port_high = port_low+100;
        }
        else if(port_high >= port_max)
        {
            printf("Limitied!Port is higher than 65535\n");
            port_high = 65535;
        }
        else if(port_high - port_low >= 500)
        {
            printf("It will take some time to scan!\n");
        }
    }

    printf("IP address : %s\n",ipaddr);
    pthread_t scan_thread[port_high+1];
    int port_num[port_high+1];
    printf("Scaning From %d to %d : \n",port_low,port_high);
    for(int i = 0 ; i <= port_high-port_low ; i++)
    {
        port_num[i] = i + port_low;
        pthread_create(&scan_thread[i],NULL,scan_port,&port_num[i]);
    }
    for(int j = port_low ; j <= port_high ; j++)
    {
        pthread_join(scan_thread[j],NULL);
    }
    //print_ports();
    return 0;
}