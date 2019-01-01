#include <sys/epoll.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    cout<<"haha"<<endl;


    int epollfd = epoll_create(5);
    cout<<epollfd<<endl;
    if(epollfd < 0){
        perr_exit("epoll_create err");
    }
    return 0;
}