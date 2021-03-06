#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc , char* argv[]){
    int result = -1;

    int fd[2],nbytes;
    pid_t pid;
    const char string[] = "thank god";
    char readbuffer[80];

    int *write_fd = &fd[1];
    int *read_fd = &fd[0];

    pipe(fd);

    pid = fork();

    if ( 0 == pid ){
        close(*read_fd);
        result = write(*write_fd,string,strlen(string));

        printf("child send bytes: %d\n",result);

        return 0;
    }else{
        close(*write_fd);
        nbytes = read(*read_fd,readbuffer,sizeof(readbuffer));

        printf("parent got bytes: %d\n",nbytes);

        printf("got date : %s\n",readbuffer);
    }

    return 0;
}