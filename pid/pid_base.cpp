#include <stdio.h>

// pid_t的类型
#include <sys/types.h>
// 操作 pid
#include <unistd.h>

int main(int argc , char* argv[]){
    printf("my pid %d\n",getpid());
    printf("my ppid %d\n",getppid());

    return 0;
}