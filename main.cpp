#include <iostream>
#include <string>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

// #define PrintDecimal(x) printf(#x" = %d\n",x)

using namespace std;

static void 
sig_user(int signo){
    if (signo == SIGUSR1){
        cout << "user1" <<endl;
    }else{
        cout << "user2" << endl;
    }
    return;
}

static void 
sig_alarm(int signo){
    if (signo == SIGALRM){
        cout << "got a timeout alarm" <<endl;
    }
    return;
}

int main(){

    // cout << "hello world " <<endl;
    // write(STDOUT_FILENO,"hello\n",6);
    // int fd = open("test.txt",O_RDWR|O_CREAT);
    // write(fd,"abcdefg\n",8);
    // write(fd,"abcedfg\n",8);
    // close(fd);


    // fd = open("test.txt",O_RDONLY);
    // FILE *ff = fdopen(fd,"rb");
    // char buf[9];
    // fgets(buf,100,ff);
    // cout<<buf<<endl;
    // cout << 8 <<endl;
    // fgets(buf,100,ff);
    // cout<<buf<<endl;

    // char readResult[5];
    // fd = open("test.txt",O_RDONLY);
    // read(fd,readResult,5);
    // cout << readResult <<endl;

    // PrintDecimal(9/3);
    // int a[10] , i;
    // int *p = &a[0];

    // for (i=0;i<10;i++){
    //     a[i] = i*i;
    // }

    // for (i=0;i<10;i++){
    //     cout << *p++ << endl;
    // }




    // pid_t pid;
    // if ( (pid = fork() ) !=0){
        
    //     int status;
    //     waitpid(pid,&status,0);
    //     cout << status <<endl;
    //     cout << "i am p "<< getpgrp() <<endl;
    // }else{
    //     printf("i am c, the pid is %d\n",pid);
    //     // char argv[][] = {"ls", "-al", "/etc/passwd", (char*) 0};
    //     execl("/bin/ls", "-ls","/etc",(char *)0);
    // }

    signal(SIGUSR1,sig_user);
    signal(SIGUSR2,sig_user);
    signal(SIGALRM,sig_alarm);
    alarm(1);
    
    for (;;)
        pause();


    return 0;
}