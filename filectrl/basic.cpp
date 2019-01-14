#include <fcntl.h>
#include <stdio.h>
// 打开的option
#include <sys/types.h>
// 读写权限
#include <sys/stat.h>
// 关闭文件
#include <unistd.h>

int main(int argc , char* argv[]){

    mode_t f_attrib;
    f_attrib = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;  
    int fd = open("./haha",O_RDWR | O_CREAT | O_TRUNC, f_attrib );

    write(fd,"333",3);
    write(fd,"22",2);
    write(fd,"1",1);

    close(fd);
    return 0;
}