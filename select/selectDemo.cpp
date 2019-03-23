#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    fd_set rd;
    struct timeval tv;
    int err;

    char sBuf[50];
    

    FD_ZERO(&rd);
    FD_SET(0, & rd);

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    err = select(1, &rd,NULL,NULL,&tv);

    if(err){
        int iCount=read(STDIN_FILENO, sBuf, 50);
        cout << sBuf << endl;
    }else{
        cout << "got nothing" <<endl;
    }
    
    

    return 0;
}