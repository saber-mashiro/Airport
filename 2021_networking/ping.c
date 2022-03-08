#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/time.h>
#include <string.h>
#include <netdb.h>
#include <pthread.h>
#define PACKAGE_MAX 5
#define UCHAR unsigned char
#define USHORT unsigned short
#define UINT unsigned int

//icmp询问报文
#define ICMP_ECHO 8                     //发送Ping请求时的ICMP报文类型 回送请求
#define ICMP_ECHOREPLY 0                //接收Ping回复时的ICMP报文类型 回送回答
#define ICMP_SIZE (sizeof(struct icmp)) //传送icmp报文数据校验的长度
#define BUF_SIZE 1024

int count = 0;
float total = 0;
char buf[BUF_SIZE] = {0};
int ttl_count[PACKAGE_MAX + 1];
float rrt_count[PACKAGE_MAX + 1];
int cmp(const void *a , const void *b){return *(float *)a - *(float *)b;}

// ICMP报文结构
struct icmp
{
    UCHAR type;               // 类型
    UCHAR code;               // 代码
    USHORT checksum;          // 校验和
    USHORT id;                // 标识符
    USHORT seq;               // 序号
    struct timeval timestamp; // 时间戳
};

//校验和
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

//icmp封包
void icmp_pack(struct icmp *icmphdr, int seq)
{
    icmphdr->type = ICMP_ECHO; //回送请求
    icmphdr->code = 0;
    icmphdr->checksum = 0; //校验和先置零
    icmphdr->seq = seq;    //序列号
    icmphdr->id = getpid();
    gettimeofday(&icmphdr->timestamp, 0);
    icmphdr->checksum = checkSum((USHORT *)icmphdr, ICMP_SIZE); //校验和计算
}

// struct ip
// {
// #if __BYTE_ORDER == __LITTLE_ENDIAN
//     unsigned int ip_hl:4;               /* header length */
//     unsigned int ip_v:4;                /* version */
// #endif
// #if __BYTE_ORDER == __BIG_ENDIAN
//     unsigned int ip_v:4;                /* version */
//     unsigned int ip_hl:4;               /* header length */
// #endif
//     u_int8_t ip_tos;                    /* type of service */
//     u_short ip_len;                     /* total length */
//     u_short ip_id;                      /* identification */
//     u_short ip_off;                     /* fragment offset field */
// #define IP_RF 0x8000                    /* reserved fragment flag */
// #define IP_DF 0x4000                    /* dont fragment flag */
// #define IP_MF 0x2000                    /* more fragments flag */
// #define IP_OFFMASK 0x1fff               /* mask for fragmenting bits */
//     u_int8_t ip_ttl;                    /* time to live */
//     u_int8_t ip_p;                      /* protocol */
//     u_short ip_sum;                     /* checksum */
//     struct in_addr ip_src, ip_dst;      /* source and dest address */
// };

//时间计算
float timeDiff(struct timeval *begin, struct timeval *end)
{
    int diff;
    // 先计算两个时间点相差多少微秒
    diff = (end->tv_sec - begin->tv_sec) * 1000000 + (end->tv_usec - begin->tv_usec);

    // 转化为毫秒返回
    return (float)(diff / 1000);
}

//icmp解包
int icmp_unpack(char *buf, int len, char *addr)
{
    int iphead_len;     //ip头部长度
    float rtt;          // 记录往返时间
    struct timeval end; // 记录接收报文的时间戳
    struct ip *ip = (struct ip *)buf;
    iphead_len = ip->ip_hl * 4;
    struct icmp *icmp = (struct icmp *)(buf + iphead_len);
    len -= iphead_len;

    if (len < 8) //判断长度是否是icmp包长度12
    {
        printf("ICMP packets length is less than 8 \n"); //错误输出
        return -1;
    }
    
    //判断该包是icmp回送回答包且是我们发出去的包
    if (icmp->type != ICMP_ECHOREPLY || icmp->id != getpid())
    {
        printf("ICMP packets are not send by us \n"); //错误输出
        return -1;
    }

    //记录往返时间
    gettimeofday(&end, 0);
    rtt = timeDiff(&icmp->timestamp, &end);

    //打印icmp数据
    printf("%d bytes from %s : icmp_seq=%u ttl=%d rtt=%fms \n", len, addr, icmp->seq, ip->ip_ttl, rtt);
    rrt_count[count++] = rtt;
    total += rtt;
    return 0;
}

int main(int argc, char *argv[])
{
    struct hostent *host;    //判断是否是域名和ip地址
    struct icmp sendicmp;    //发送报文
    struct sockaddr_in from; //发送
    struct sockaddr_in to;   //接受
    struct timeval begin_out,end_out;// 超时变量
    int fromlen = 0;         //发送报文
    int sockfd;              //原始套接字
    int send_time = 0;       //发送次数
    int received_time = 0;   //接受次数
    int n;
    in_addr_t inaddr; //一般为32位的unsigned int

    memset(&from, 0, sizeof(struct sockaddr_in));
    memset(&to, 0, sizeof(struct sockaddr_in));

    //判断是否输入了地址
    if (argc < 2)
    {
        printf("use : %s hostname/IP address \n", argv[0]);
        return -1;
    }
    // 生成原始套接字
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1)
    {
        printf("socket() error \n");
        return -1;
    }
    // 设置目的地址信息
    to.sin_family = AF_INET;
    // 判断是域名还是ip地址
    if (inaddr = inet_addr(argv[1]) == INADDR_NONE)
    {
        // 是域名
        if ((host = gethostbyname(argv[1])) == NULL)
        {
            printf("gethostbyname() error \n");
            return -1;
        }
        to.sin_addr = *(struct in_addr *)host->h_addr_list[0];
    }
    else
    {
        // 是ip地址
        to.sin_addr.s_addr = inaddr;
    }
    // 输出域名ip地址信息
    printf("ping %s (%s) : %d bytes of data.\n", argv[1], inet_ntoa(to.sin_addr), (int)ICMP_SIZE);

    //循环发送报文、接收报文
    for (int i = 0; i < PACKAGE_MAX; i++)
    {
        send_time++; // 发送次数加1
        memset(&sendicmp, 0, ICMP_SIZE);
        icmp_pack(&sendicmp, send_time);
        // 发送报文
        if (sendto(sockfd, &sendicmp, ICMP_SIZE, 0, (struct sockaddr *)&to, sizeof(to)) == -1)
        {
            printf("sendto() error \n");
            continue;
        }
        // 接收报文
        if ((n = recvfrom(sockfd, buf, BUF_SIZE, 0, (struct sockaddr *)&from, &fromlen)) < 0)
        {
            printf("recvform() error \n");
            continue;
        }
        received_time++; // 接收次数加1
        //判断是否解包失败
        if (icmp_unpack(buf, n, inet_ntoa(from.sin_addr)) == -1)
        {
            printf("unpack() error \n");
        }
        sleep(1);
    }

    // 输出统计信息
    printf("---  %s ping statistics ---\n", argv[1]);
    printf("%d packets transmitted, %d received, %%%d packet loss\n", send_time, received_time,
           (send_time - received_time) / send_time * 100);
    qsort(rrt_count,PACKAGE_MAX,sizeof(rrt_count[0]),cmp);
    printf("maxrrt = %.2fms,  minrrt = %.2fms,  arg = %.2fms\n",rrt_count[PACKAGE_MAX-1],rrt_count[0],total/(float)PACKAGE_MAX);
    return 0;
}
