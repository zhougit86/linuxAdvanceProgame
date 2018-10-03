#include <iostream>
#include <string>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#include <stropts.h>
#include <stdlib.h>

using namespace std;
char buf[100000];

void set_fl(int fd,int flags){
    int val;
    if ((val = fcntl(fd,F_GETFL,0))<0)
        cout << "fcntl err"<<endl;

    val |= flags;

    if (fcntl(fd,F_SETFL,val) < 0)
        cout << "fcntl set errd" <<endl;
}

void clr_fl(int fd,int flags){
    int val;
    if ((val = fcntl(fd,F_GETFL,0))<0)
        cout << "fcntl err"<<endl;

    val &= ~flags;

    if (fcntl(fd,F_SETFL,val) < 0)
        cout << "fcntl set errd" <<endl;
}

int main(int argc,char *argv[]){
    int ntowrite;
    fd_set rset, wset;
    // ntowrite = read(STDIN_FILENO,buf,sizeof(buf));

    set_fl(STDOUT_FILENO,O_NONBLOCK);

    FD_ZERO(&rset);  
    FD_SET(STDOUT_FILENO, &rset);

    struct timeval tval;
    tval.tv_sec = 0;  
    tval.tv_usec = 0;

    select(4, &rset, NULL, NULL, &tval);

    cout << "got a signal" <<endl;
}