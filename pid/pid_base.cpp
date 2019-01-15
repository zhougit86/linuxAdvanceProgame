#include <stdio.h>

// pid_t的类型
#include <sys/types.h>
// 操作 pid
#include <unistd.h>

int main(int argc , char* argv[]){
    
    printf("got input %s\n",argv[1]);
    printf("my pid %d\n",getpid());
    // printf("my ppid %d\n",getppid());

    char *args[] = {"/bin/ls",NULL};
    execve("/bin/ls",args,NULL);

    return 0;
}