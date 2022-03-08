#include <arpa/inet.h> 
#include <signal.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define LISTENQ 1024 
#define MAXLINE 1024  
#define RIO_BUFSIZE 1024  //IO缓存区大小

// Robust I/O结构
typedef struct
{
    int rio_fd;                //与缓冲区绑定的文件描述符的编号
    int rio_cnt;               //缓冲区中还未读取的字节数
    char *rio_bufptr;          //当前下一个未读取字符的地址
    char rio_buf[RIO_BUFSIZE]; // 内部缓冲区
} rio_t;

typedef struct sockaddr SA; //定义通用接受各种类型的套接字 将 sockaddr_in 结构强制转换成通用 sockaddr 结构

//size_t一般用来表示一种计数，比如有多少东西被拷贝等。例如：sizeof操作符的结果类型是size_t，该类型保证能容纳实现所建立的最大对象的字节大小。 它的意义大致是“适于计量内存中可容纳的数据项目个数的无符号整数类型”。所以，它在数组下标和内存管理函数之类的地方广泛使用。
//ssize_t:这个数据类型用来表示可以被执行读写操作的数据块的大小.它和size_t类似,但必需是signed.意即：它表示的是sign size_t类型的。

//http请求
typedef struct
{
    char filename[512]; //文件名
    off_t offset;  //支持的范围
    size_t end;  
} http_request;

// MIME结构
typedef struct
{
    const char *extension; //文件拓展名
    const char *mime_type; //类型
} mime_map;

mime_map meme_types[] = {
    {".css", "text/css"},
    {".gif", "image/gif"},
    {".htm", "text/html"},
    {".html", "text/html"},
    {".jpeg", "image/jpeg"},
    {".jpg", "image/jpeg"},
    {".ico", "image/x-icon"},
    {".js",  "application/javascript"},
    {".pdf", "application/pdf"},
    {".mp4", "video/mp4"},
    {".png", "image/png"},
    {".svg", "image/svg+xml"},
    {".zip", "application/zip"},
    {".xml", "text/xml"},
    {NULL, NULL},
};

char *default_mime_type = "text/plain"; //设置默认拓展类型

//rio读取缓存区初始化
void rio_readinitb(rio_t *rp, int fd)
{
    rp->rio_fd = fd;    //套接字
    rp->rio_cnt = 0;    //内部缓存区剩余未被读取的字节数
    rp->rio_bufptr = rp->rio_buf; //buf指针
}

//rio写入，手动刷新缓存区
ssize_t rio_writen(int fd, void *usrbuf, size_t n)
{
    size_t nleft = n;
    ssize_t nwritten;
    char *bufp = usrbuf;

    while (nleft > 0)
    {
        if ((nwritten = write(fd, bufp, nleft)) <= 0)
        {
            if (errno == EINTR)     //信号中断返回
                nwritten = 0;       //再次调用writen写入
            else
                return -1;          //该错误没有由于writen造成
        }
        nleft -= nwritten;
        bufp += nwritten;
    }
    return n;
}

//rio_read 从用户的内部缓存区传送最小min(n, rio_cnt)字节，n是用户请求的字节数，cnt是内部缓存区剩余未被读取的字节数，如果内部缓存区为空，重新调用read来填充
static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n)
{
    int cnt;
    while (rp->rio_cnt <= 0)
    { //如果缓存区为空，重新填充
        rp->rio_cnt = read(rp->rio_fd, rp->rio_buf,
                           sizeof(rp->rio_buf));
        if (rp->rio_cnt < 0)
        {
            if (errno != EINTR)     //信号中断返回
                return -1;
        }
        else if (rp->rio_cnt == 0)  //EOF
            return 0;
        else
            rp->rio_bufptr = rp->rio_buf; //重置缓存区指针
    }
    //从用户的内部缓存区复制最小的字节
    cnt = n;
    if (rp->rio_cnt < n)
        cnt = rp->rio_cnt;
    memcpy(usrbuf, rp->rio_bufptr, cnt);
    rp->rio_bufptr += cnt;
    rp->rio_cnt -= cnt;
    return cnt;
}

//rio_readlineb 稳定读取已缓存的文本行,一次从缓冲区/文件读取一行数据
ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen)
{
    int n, rc;
    char c, *bufp = usrbuf;

    for (n = 1; n < maxlen; n++)////n代表已接收字符的数量
    {
        if ((rc = rio_read(rp, &c, 1)) == 1)
        {
            *bufp++ = c;
            if (c == '\n')
                break;
        }
        else if (rc == 0)//没有接收到数据
        {
            if (n == 1)
                return 0; //如果第一次循环就没接收到数据，则代表无数据可接收
            else
                break; //数据已经读取过了
        }
        else
            return -1; 
    }
    *bufp = 0;
    return n;
}

//format_size 读取文件的大小计算
void format_size(char *buf, struct stat *stat)
{
    if (S_ISDIR(stat->st_mode))
    {
        sprintf(buf, "%s", "[DIR]");
    }
    else
    {
        off_t size = stat->st_size;
        if (size < 1024)
        {
            sprintf(buf, "%lu", size);
        }
        else if (size < 1024 * 1024)
        {
            sprintf(buf, "%.1fK", (double)size / 1024);
        }
        else if (size < 1024 * 1024 * 1024)
        {
            sprintf(buf, "%.1fM", (double)size / 1024 / 1024);
        }
        else
        {
            sprintf(buf, "%.1fG", (double)size / 1024 / 1024 / 1024);
        }
    }
}

//handle_directory_request 处理目录请求
void handle_directory_request(int out_fd, int dir_fd, char *filename)
{
    char buf[MAXLINE], m_time[32], size[16];
    struct stat statbuf;
    sprintf(buf, "HTTP/1.1 200 OK\r\n%s%s%s%s%s",
            "Content-Type: text/html\r\n\r\n",
            "<html><head><style>",
            "body{font-family: monospace; font-size: 13px;}",
            "td {padding: 1.5px 6px;}",
            "</style></head><body><table>\n");
    rio_writen(out_fd, buf, strlen(buf));
    DIR *d = fdopendir(dir_fd);//打开文件目录,返回指向目录的结构体
    struct dirent *dp;
    int ffd;
    while ((dp = readdir(d)) != NULL)//调用readdir读取目录下的所有文件，返回结构体
    {
        if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
        {
            continue;
        }
        if ((ffd = openat(dir_fd, dp->d_name, O_RDONLY)) == -1)//openat只需要每个线程在初始化时打开一个目录后就可以以openat在“当前目录”操作文件了
        {
            perror(dp->d_name);
            continue;
        }
        fstat(ffd, &statbuf);//返回文件相关目录
        strftime(m_time, sizeof(m_time),"%Y-%m-%d %H:%M", localtime(&statbuf.st_mtime));//localtime获取系统时间 转化为想要的str格式
        format_size(size, &statbuf);//文件大小计算
        if (S_ISREG(statbuf.st_mode) || S_ISDIR(statbuf.st_mode))//普通文件或者文件夹
        {
            char *d = S_ISDIR(statbuf.st_mode) ? "/" : "";
            sprintf(buf, "<tr><td><a href=\"%s%s\">%s%s</a></td><td>%s</td><td>%s</td></tr>\n",dp->d_name, d, dp->d_name, d, m_time, size);//tr 行标签 td 单元格标签
            rio_writen(out_fd, buf, strlen(buf));
        }
        close(ffd);
    }
    sprintf(buf, "</table></body></html>");
    rio_writen(out_fd, buf, strlen(buf));
    closedir(d);//关闭目录句柄
}

//获取文件类型
static const char *get_mime_type(char *filename)
{
    char *dot = strrchr(filename, '.');//返回从字符串中的'.'起，一直到字符串结束的所有字符
    if (dot)
    { //找到.之后出现的后缀名
        mime_map *map = meme_types;
        while (map->extension)
        {
            if (strcmp(map->extension, dot) == 0)
            {
                return map->mime_type;
            }
            map++;
        }
    }
    return default_mime_type;
}

//套接字 open_listenfd 服务器创建一个监听描述符，准备好接收连接请求
int open_listenfd(int port)
{
    int listenfd, optval = 1;
    struct sockaddr_in serveraddr;

    //创建一个套接字描述符
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return -1;

    //从绑定中消除“地址已在使用中”错误。
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR,//SOL_SOCKET:level   SO_REUSEADDR，打开或关闭地址复用功能。当option_value不等于0时，打开，否则，关闭。它实际所做的工作是置sock->sk->sk_reuse为1或0。
                   (const void *)&optval, sizeof(int)) < 0)
        return -1;

    // 6 是tcp协议号，加快传输
    if (setsockopt(listenfd, 6, TCP_CORK,//开启时，内核将阻塞不完整的报文，当关闭此选项时，发送阻塞的报文
                   (const void *)&optval, sizeof(int)) < 0)
        return -1;

    //listenfd 是所有要在此主机的任何IP地址上移植的请求的终结点
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);//监听所有地址
    serveraddr.sin_port = htons((unsigned short)port);
    if (bind(listenfd, (SA *)&serveraddr, sizeof(serveraddr)) < 0)//-1失败 0成功 一个服务器进程需要绑定一个众所周知的地址或端口以等待客户来连接
        return -1;

    //监听套接字，准备接受连接请求
    if (listen(listenfd, LISTENQ) < 0)//将套接字( sockfd )变成被动的连接监听套接字,将该套接字和套接字对应的连接队列长度告诉 Linux 内核
        return -1;
    return listenfd; //返回一个监听描述符
}

//url解码
void url_decode(char *src, char *dest, int max)
{
    char *p = src;
    char code[3] = {0};
    while (*p && --max)
    {
        if (*p == '%')
        {
            memcpy(code, ++p, 2);
            *dest++ = (char)strtoul(code, NULL, 16);
            p += 2;
        }
        else
        {
            *dest++ = *p++;
        }
    }
    *dest = '\0';
}

//请求解析
void parse_request(int fd, http_request *req)
{
    rio_t rio;
    char buf[MAXLINE], method[MAXLINE], url[MAXLINE];
    req->offset = 0;
    req->end = 0; //默认为0

    rio_readinitb(&rio, fd);
    rio_readlineb(&rio, buf, MAXLINE);
    sscanf(buf, "%s %s", method, url); 
    while (buf[0] != '\n' && buf[1] != '\n')
    { // \n 或者 \r\n 的情况
        rio_readlineb(&rio, buf, MAXLINE);
        if (buf[0] == 'R' && buf[1] == 'a' && buf[2] == 'n')
        {
            sscanf(buf, "Range: bytes=%lu-%lu", &req->offset, &req->end);
            if (req->end != 0)
                req->end++;
        }
    }
    char *filename = url;
    if (url[0] == '/')
    {
        filename = url + 1;
        int length = strlen(filename);
        if (length == 0)
        {
            filename = ".";
        }
        else
        {
            for (int i = 0; i < length; ++i)
            {
                if (filename[i] == '?')
                {
                    filename[i] = '\0';
                    break;
                }
            }
        }
    }
    url_decode(filename, req->filename, MAXLINE);
}


void log_access(int status, struct sockaddr_in *c_addr, http_request *req)
{
    printf("%s:%d %d - %s\n", inet_ntoa(c_addr->sin_addr),//返回点分十进制的字符串在静态内存中的指针
           ntohs(c_addr->sin_port), status, req->filename);//端口 http标识 文件名
}

//404 not found
void client_error(int fd, int status, char *msg, char *longmsg)
{
    char buf[MAXLINE];
    sprintf(buf, "HTTP/1.1 %d %s\r\n", status, msg);
    sprintf(buf + strlen(buf),
            "Content-length: %lu\r\n\r\n", strlen(longmsg));
    sprintf(buf + strlen(buf), "%s", longmsg);
    rio_writen(fd, buf, strlen(buf));
}

//服务器
void serve_static(int out_fd, int in_fd, http_request *req, size_t total_size)
{
    char buf[256];
    if (req->offset > 0) //处理部分请求206
    {
        sprintf(buf, "HTTP/1.1 206 Partial\r\n");
        sprintf(buf + strlen(buf), "Content-Range: bytes %lu-%lu/%lu\r\n",req->offset, req->end, total_size);
    }
    else // 成功200
    {
        sprintf(buf, "HTTP/1.1 200 OK\r\nAccept-Ranges: bytes\r\n");
    }
    sprintf(buf + strlen(buf), "Cache-Control: no-cache\r\n");
    sprintf(buf + strlen(buf), "Content-length: %lu\r\n",req->end - req->offset);
    sprintf(buf + strlen(buf), "Content-type: %s\r\n\r\n",get_mime_type(req->filename));

    rio_writen(out_fd, buf, strlen(buf));
    off_t offset = req->offset; //复制
    while (offset < req->end)
    {
        if (sendfile(out_fd, in_fd, &offset, req->end - req->offset) <= 0) //sendfile零拷贝
        {
            break;
        }
        printf("offset: %d \n\n", offset);
        close(out_fd);
        break;
    }
}

//线程工作函数
void process(int fd, struct sockaddr_in *clientaddr)
{
    printf("accept request, fd is %d, pid is %d\n", fd, getpid());
    http_request req;
    parse_request(fd, &req);

    struct stat sbuf;
    int status = 200;//请求已成功，请求的响应头或数据体将随此响应返回
    int ffd = open(req.filename, O_RDONLY, 0);//只读模式打开目录
    if (ffd <= 0)//如果没能找到文件返回-1
    {
        status = 404; //请求失败，请求的资源在服务器上找不到。
        char *msg = "404 not found";
        client_error(fd, status, "Not found", msg); //写入404notfound
    }
    else
    {
        fstat(ffd, &sbuf);//是用来返回"相关文件状态信息"
        if (S_ISREG(sbuf.st_mode))//文件是一个普通文件
        {
            if (req.end == 0)
            {
                req.end = sbuf.st_size; //返回文件大小
            }
            if (req.offset > 0)
            {
                status = 206; //	服务器已经成功处理了部分 GET 请求
            }
            serve_static(fd, ffd, &req, sbuf.st_size);
        }
        else if (S_ISDIR(sbuf.st_mode))//文件是一个目录
        {
            status = 200;
            handle_directory_request(fd, ffd, req.filename);
        }
        else
        {
            status = 400; //由于包含语法错误，当前请求无法被服务器理解
            char *msg = "Unknow Error";
            client_error(fd, status, "Error", msg);
        }
        close(ffd);
    }
    log_access(status, clientaddr, &req);
}


int main(int argc, char **argv)
{
    struct sockaddr_in clientaddr;
    int default_port = 8080,listenfd,connfd;
    char buf[256];
    char *path = getcwd(buf, 256); //获取路径
    socklen_t clientlen = sizeof clientaddr;
    if (argc == 2)
    {
        if (argv[1][0] >= '0' && argv[1][0] <= '9')
        {
            default_port = atoi(argv[1]);
        }
        else
        {
            path = argv[1];
            if (chdir(argv[1]) != 0)
            {
                perror(argv[1]);
                exit(1);
            }
        }
    }
    else if (argc == 3)
    {
        default_port = atoi(argv[2]);
        path = argv[1];
        if (chdir(argv[1]) != 0)
        {
            perror(argv[1]);
            exit(1);
        }
    }

    listenfd = open_listenfd(default_port);//监听描述符
    if (listenfd > 0) //成功返回描述符，错误返回-1
    {
        printf("listen on port %d, fd is %d\n", default_port, listenfd);
    }
    else
    {
        perror("ERROR");
        exit(listenfd);
    }

    //终止信号，如果浏览器终止请求，则结束进程
    signal(SIGPIPE, SIG_IGN);

    // for (int i = 0; i < 10; i++)
    // {
    //     int pid = fork();//通过系统调用创建一个与原来进程几乎完全相同的进程
    //     if (pid == 0) //子进程 返回0
    //     { 
    //         while (1)
    //         {
    //             connfd = accept(listenfd, (SA *)&clientaddr, &clientlen);
    //             process(connfd, &clientaddr);
    //             close(connfd);
    //         }
    //     }
    //     else if (pid > 0) //父进程 返回新创建子进程的进程ID
    //     { 
    //         printf("child pid is %d\n", pid);
    //     }
    //     else // 错误则返回一个负数
    //     {
    //         perror("fork");
    //     }
    // }

    while (1)
    {
        connfd = accept(listenfd, (SA *)&clientaddr, &clientlen);
        process(connfd, &clientaddr);
        close(connfd);
    }

    return 0;
}