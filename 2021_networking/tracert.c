#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>

#define UCHAR unsigned char
#define USHORT unsigned short
#define UINT unsigned int

#define TRACE_RESULT_TIMEOUT -3
#define TRACE_RESULT_TIMEEXCEED -2
#define TRACE_RESULT_UNREACH -1

#define EXIT_ERR 1

#define BUFSIZE 1025
#define ICMP_HLEN 8
#define TRUE 1
#define FALSE 0

/* troptions默认值 */
#define DFLOPT_MAXTTL 30
#define DFLOPT_NQUERIES 3
#define DFLOPT_WAITTIME 3

/* troptions结构定义 */
struct troptions
{
    int tro_maxttl;   /* -m */
    int tro_nqueries; /* -q */
    int tro_waittime; /* -w */
};

/* 全局变量 */
struct troptions troptions;

USHORT sport;                //源端端口和目的端端口
struct sockaddr_in destaddr; //目的端套接字地址结构
char *hostname;              //目的端主机名

USHORT dport = 32768 + 666;
char sendbuf[BUFSIZE], recvbuf[BUFSIZE]; //发送缓冲区和接收缓冲区
int datalen;
int icmpdatalen = 56;
int alarm_flag; //闹钟标记

void trace_icmp(void);
int trace_recv_icmp(int sockfd, int seq, struct timeval *tv, struct sockaddr *addr, socklen_t *addrlen);

/*
 *  套接字地址结构地址部分转字符串
 *      若成功，返回转换后的字符串，若出错，返回NULL
 */
char *sock_ntop_host(const struct sockaddr *addr, socklen_t addrlen)
{
    static char str[64];

    switch (addr->sa_family)
    {
    case AF_INET: //ipv4
    {
        struct sockaddr_in *sin = (struct sockaddr_in *)addr;
        if (inet_ntop(AF_INET, &sin->sin_addr, str, sizeof(str)) == NULL)
            return NULL;
        break;
    }

    case AF_INET6: //ipv6
    {
        struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *)addr;
        if (inet_ntop(AF_INET6, &sin6->sin6_addr, str, sizeof(str)) == NULL)
            return NULL;
        break;
    }
    }

    return str;
}

/*
 *  比较两个套接字地址结构是否相同
 *      若相同，返回0
 */
int sock_addr_cmp(const struct sockaddr *sa1, const struct sockaddr *sa2, socklen_t salen)
{
    if (sa1->sa_family != sa2->sa_family)
        return -1;

    switch (sa1->sa_family)
    {
    case AF_INET:
        return memcmp(&((struct sockaddr_in *)sa1)->sin_addr,&((struct sockaddr_in *)sa2)->sin_addr,sizeof(struct in_addr));

    case AF_INET6:
        return memcmp(&((struct sockaddr_in6 *)sa1)->sin6_addr,&((struct sockaddr_in6 *)sa2)->sin6_addr,sizeof(struct in6_addr));
    }
    return -1;
}

/*
 *  计算检验和
 */
USHORT checkSum(USHORT *addr, int len)
{
    int sum = 0;
    //处理icmp报头二进制数据，以两个字节的单位累加
    while (len > 1)
    {
        sum += *addr++;
        len -= 2;
    }
    //判断 icmp报头是奇数的话，把这个字节看作是2字节的高字节，然后低位置零，累加进sum
    if (len == 1)
    {
        sum += *(USHORT *)addr;
    }
    // 将32位的高16位与低16位相加(二进制反码求和)
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);

    return (USHORT)~sum;
}

//时间计算
float timeDiff(struct timeval *begin, struct timeval *end)
{
    int diff;
    // 先计算两个时间点相差多少微秒
    diff = (end->tv_sec - begin->tv_sec) * 1000000 + (end->tv_usec - begin->tv_usec);

    // 转化为毫秒返回
    return (float)(diff / 1000);
}

/*
 *  SIGALRM信号处理函数
 */
void sig_alrm(int signo)
{
    alarm_flag = TRUE;
    return;
}

//icmp封包
void icmp_pack(struct icmp *icmphdr, int seq, struct timeval *begin)
{
    icmphdr->icmp_type = ICMP_ECHO;
    icmphdr->icmp_code = 0;
    icmphdr->icmp_id = htons(getpid());
    icmphdr->icmp_seq = htons(seq);
    memset(icmphdr->icmp_data, 0xa5, icmpdatalen);
    memcpy(icmphdr->icmp_data, &begin, sizeof(struct timeval));
    size_t len = ICMP_HLEN + icmpdatalen;
    icmphdr->icmp_cksum = 0;
    icmphdr->icmp_cksum = checkSum((USHORT *)icmphdr, len);
}

void trace_icmp(void)
{
    int sockfd;
    struct sockaddr addr, lastaddr;
    socklen_t addrlen;

    float rtt;
    int icmpdatalen, seq, ttl, query, code, ndone;
    struct timeval tvsend, tvrecv;
    struct icmp *icmp;
    size_t len = 64;

    /* 建立一个基于ICMP的套接字用于发送和接收ICMP消息 */
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        perror("scoket error");
        exit(EXIT_ERR);
    }
    setuid(getuid()); //获取root权限

    printf("traceroute to %s (%s), %d hops max \n", hostname, inet_ntoa(destaddr.sin_addr), troptions.tro_maxttl);
    seq = 0;
    ndone = 0;
    for (ttl = 1; ttl <= troptions.tro_maxttl && ndone == 0; ttl++)
    {
        setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(int));

        printf("%3d", ttl);
        fflush(stdout);

        bzero(&lastaddr, sizeof(lastaddr));
        for (query = 0; query < troptions.tro_nqueries; query++)
        {
            seq++;

            gettimeofday(&tvsend, NULL);

            /* 构建ICMP回显请求消息 */
            icmp = (struct icmp *)sendbuf;
            icmp_pack(icmp, seq, &tvsend);

            if (sendto(sockfd, sendbuf, len, 0, (struct sockaddr *)&destaddr, sizeof(destaddr)) < 0)
            {
                perror("sendto error");
                exit(EXIT_ERR);
            }

            /* 处理回应结果 */
            code = trace_recv_icmp(sockfd, seq, &tvrecv, &addr, &addrlen);
            if (code == TRACE_RESULT_TIMEOUT)
            {
                printf("\t*");
            }
            else
            {
                char str[NI_MAXHOST]; //NI_MAXHOST为宏定义，值为1025
                if (sock_addr_cmp(&lastaddr, &addr, addrlen) != 0)
                {
                    if (getnameinfo(&addr, addrlen, str, sizeof(str), NULL, 0, 0) == 0)
                        printf("\t%s", sock_ntop_host(&addr, addrlen));
                    else
                        printf("\t%s", sock_ntop_host(&addr, addrlen));
                    memcpy(&lastaddr, &addr, addrlen);
                }
                rtt = timeDiff(&tvsend, &tvrecv);
                printf("\t%.2f ms", rtt);
                if (code == TRACE_RESULT_UNREACH)
                    ndone++;
            }
        }
        printf("\n");
    }
}

int trace_recv_icmp(int sockfd, int seq, struct timeval *tv, struct sockaddr *addr, socklen_t *addrlen)
{
    struct ip *ip1, *ip2;
    struct icmp *icmp, *icmp2;
    int iphlen1, iphlen2, icmplen, ret, n;
    struct sigaction act;//检查或修改与指定信号相关联的处理动作

    /* 设置SIGALRM信号处理函数 */
    sigemptyset(&act.sa_mask);
    act.sa_handler = sig_alrm;
    act.sa_flags = 0;
    sigaction(SIGALRM, &act, NULL);

    alarm(troptions.tro_waittime);

    alarm_flag = FALSE;
    while (1)
    {
        if (alarm_flag)
        {
            ret = TRACE_RESULT_TIMEOUT;
            break;
        }

        n = recvfrom(sockfd, recvbuf, sizeof(recvbuf), 0, addr, addrlen);
        if (n < 0)
        {
            if (errno == EINTR)
                continue;
            else
            {
                perror("recvform() error \n");
                exit(EXIT_ERR);
            }
        }

        /* 处理接收到的数据 */
        ip1 = (struct ip *)recvbuf;
        iphlen1 = ip1->ip_hl << 2;

        icmp = (struct icmp *)(recvbuf + iphlen1);
        if ((icmplen = n - iphlen1) < ICMP_HLEN)
            continue;

        if (icmp->icmp_type == ICMP_TIMXCEED && icmp->icmp_code == ICMP_TIMXCEED_INTRANS)
        {

            if (icmplen < ICMP_HLEN + sizeof(struct ip))
                continue;

            ip2 = (struct ip *)(recvbuf + iphlen1 + ICMP_HLEN);
            iphlen2 = ip2->ip_hl << 2;

            if (icmplen < ICMP_HLEN + iphlen2 + ICMP_HLEN)
                continue;

            icmp2 = (struct icmp *)(recvbuf + iphlen1 + ICMP_HLEN + iphlen2);
            if (icmp2->icmp_type == ICMP_ECHO && icmp2->icmp_code == 0 && icmp2->icmp_id == htons(getpid()) && icmp2->icmp_seq == htons(seq))
            {
                ret = TRACE_RESULT_TIMEEXCEED;
                break;
            }
        }
        else if (icmp->icmp_type == ICMP_ECHOREPLY)
        {

            if (icmp->icmp_id == htons(getpid()) && icmp->icmp_seq == htons(seq))
            {
                ret = TRACE_RESULT_UNREACH;
                break;
            }
        }
    }
    alarm(0);
    gettimeofday(tv, NULL);

    return ret;
}

int main(int argc, char *argv[])
{
    char c;
    struct hostent *hostent;
    in_addr_t saddr; //un 32位long
    /* 设置默认选项 */
    troptions.tro_maxttl = DFLOPT_MAXTTL;
    troptions.tro_nqueries = DFLOPT_NQUERIES;
    troptions.tro_waittime = DFLOPT_WAITTIME;

    if (argc < 2)
    {
        fprintf(stderr, "usage tracert [hostname]/[IP] \n");
        exit(EXIT_ERR);
    }
    hostname = argv[optind];

    /* 处理用户输入，并构建一个目的端套接字地址结构 */
    if ((saddr = inet_addr(hostname)) == INADDR_NONE)
    {
        if ((hostent = gethostbyname(hostname)) == NULL)
        {
            fprintf(stderr, "unknow host %s \n", hostname);
            exit(EXIT_ERR);
        }
        memmove(&saddr, hostent->h_addr, hostent->h_length);
    }
    bzero(&destaddr, sizeof(destaddr));//将内存块destaddr的字节清零
    destaddr.sin_family = AF_INET; //ipv4地址协议
    destaddr.sin_addr.s_addr = saddr; //ip
    trace_icmp();
    return 0;
}
