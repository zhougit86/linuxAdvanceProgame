#include <sys/epoll.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdlib.h


#include <iostream>

using namespace std;

void addfd(int epollfd, int fd, int enable_et)
{
        struct epoll_event event;
        // EPOLLIN :表示对应的文件描述符可以读(包括对端SOCKET正常关闭)
        // POLLOUT:表示对应的文件描述符可以写
        // EPOLLPRI:表示对应的文件描述符有紧急的数据可读(这里应该表示有带外数据到来)
        // EPOLLERR:表示对应的文件描述符发生错误
        // EPOLLHUP:表示对应的文件描述符被挂断;
        // EPOLLET: 将EPOLL设为边缘触发(Edge Triggered)模式,这是相对于水平触发(Level Triggered)来说的
        // EPOLLONESHOT:只监听一次事件,当监听完这次事件之后,如果还需要继续监听这个socket的话,需要再次把这个socket加入到EPOLL队列里
        event.data.fd = fd;
        event.events = EPOLLIN;
        if(enable_et){
                //边缘触发
                event.events |= EPOLLET;
        }
        //第二个参数可以是EPOLL_CTL_MOD，EPOLL_CTL_DEL
        epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
//      setnonblocking(fd);
}

int start_ser(char *ipaddr, char *port)
{
    //sock_stream代表是tcp，SOCK_DGRAM代表是udp
        int sock = socket(AF_INET, SOCK_DGRAM, 0);

        struct sockaddr_in serveraddr;
        //从sys/type而来的
        bzero(&serveraddr, sizeof(serveraddr));
        serveraddr.sin_family = AF_INET;
        serveraddr.sin_port = htons(atoi(port));
        inet_pton(AF_INET, ipaddr, &serveraddr.sin_addr);

        bind(sock, (struct sockaddr *)&serveraddr, sizeof(serveraddr));


        //128最大能处理的连接数，来自socket.h
        listen(sock, 128);

        return sock;
}


int main(int argc, char* argv[]){
    cout<<"haha"<<endl;
    cout<<argv[1]<<endl;
    cout<<argv[2]<<endl;
    
    int listenfd = start_ser(argv[1], argv[2]);
    int epollfd = epoll_create(5);
    cout<<epollfd<<endl;
    if(epollfd < 0){
        return 1;
    }
    return 0;
}