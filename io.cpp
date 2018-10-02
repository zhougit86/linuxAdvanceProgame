#include <iostream>
#include <string>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

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

main(void){
    int ntowrite, nwrite;
    char *ptr;

    ntowrite = read(STDIN_FILENO,buf,sizeof(buf));
    fprintf(stderr,"read %d bytes\n",ntowrite);

    set_fl(STDOUT_FILENO,O_NONBLOCK);

    for (ptr = buf ; ntowrite > 0;){
        errno = 0;
        nwrite = write(STDOUT_FILENO,ptr,ntowrite);
        fprintf(stderr,"nwrite = %d, errno = %d\n\n",nwrite,errno);
        if (nwrite > 0){
            ptr += nwrite;
            ntowrite -= nwrite;
        }
    }
    clr_fl(STDOUT_FILENO,O_NONBLOCK);
    exit(0);

}