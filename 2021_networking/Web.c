#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int default_port = 8080;
int createlistenfd()
{
    int fd = socket(AF_INET , SOCK_STREAM , 0);
    
    //地址复用
    int n = 1;
    setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&n,4);

    //填充地址结构体
    struct sockaddr_in sin;
    bzero(&sin , sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(default_port);
    sin.sin_addr.s_addr = INADDR_ANY;//任意地址
    
    //绑定
    int r = bind(fd,(struct sockaddr*)&sin,sizeof(sin));
    if(r == -1)
    {
        perror("bind error");
        exit(-1);
    }

    //开始监听
    int lr = listen(fd,5);
    if(lr == -1)
    {
        perror("listen error");
        exit(-1);
    }

    return fd;
}

void work(int fd , char *s)
{
    //分析客户端所需的文件名
    char filename[100] = {0};

    sscanf(s,"GET /%s",filename);
    printf("请求的文件名是：%s",filename);

    if(strcmp(filename,"HTTP/1.1")==0)
    {
        memset(filename,0,sizeof(filename));
        strcpy(filename,"web.html");
    }
    else if(strcmp(filename,"web.html")!=0)
    {
        memset(filename,0,sizeof(filename));
        strcpy(filename,"404.html");
    }
    

    //解析mime类型
    char *mime;
    if(strstr(filename,".html"))
    {
        mime = "text/html";
    }
    else if(strstr(filename,".jpg"))
    {
        mime = "image/jpeg";
    }

    //构建响应头，发给客户端
    char response[100] = {0};
    sprintf(response,"HTTP/1.1 200 OK\r\nContent-Type:%s\r\n\r\n",mime);
    write(fd,response,sizeof(response));

    //发具体的文件数据
    int filefd = open(filename,O_RDONLY);
    while(1)
    {
        bzero(response,sizeof(response));
        int rlen = read(filefd,response,100);
        if(rlen > 0)
        {
            write(fd,response,rlen);
        }
        else break;
    }
}


int main(int argc, char **argv)
{
    if (argc == 2)
    {
        default_port = atoi(argv[1]);
    }
    //创建监听套接字
    printf("创建监听套接字\n");
    int sockfd = createlistenfd();
    printf("创建监听套接字成功\n");
    //得到客户链接
    struct sockaddr_in caddr;
    int len = sizeof(caddr);
    while(1)
    {
        printf("等待用户连接\n");
        int fd = accept(sockfd , (struct sockaddr*)&caddr , &len);
        printf("用户已连接\n");
        char buffer[1024] = {0};
        int rlen = read(fd,buffer,sizeof(buffer));
        if(rlen <= 0)
        {
            perror("receive error");
            exit(-1);
        }
        printf("客户端请求：%s\n",buffer);
        sleep(1);
        work(fd , buffer);
        close(fd);
    }
    close(sockfd);
    return 0;
}