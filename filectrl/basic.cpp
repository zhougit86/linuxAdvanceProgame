#include <fcntl.h>
#include <stdio.h>
// 打开的option
#include <sys/types.h>
// 读写权限
#include <sys/stat.h>
// 关闭文件,lseek都在这个库当中
#include <unistd.h>
//操作fcntl的状态

int main(int argc , char* argv[]){

    mode_t f_attrib;
    f_attrib = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;  
    int fd = open("./haha",O_RDWR | O_CREAT | O_TRUNC, f_attrib );

    write(fd,"333",3);
    write(fd,"22",2);
    write(fd,"1",1);

    //成功
    printf("%d\n", lseek(fd,0,SEEK_CUR));
    //成功
    printf("%d\n", lseek(fd,1,SEEK_CUR));
    //失败
    printf("%d\n", lseek(fd,-21,SEEK_SET));


    struct stat st;
    fstat(fd, &st);

    printf("size: %d\n",st.st_size);
    printf("user: %d\n",st.st_uid);

    printf("file state: %d\n",fcntl(fd,F_GETFL));


    close(fd);

    

    return 0;
}