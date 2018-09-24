#include <iostream>
#include <string>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

// #define PrintDecimal(x) printf(#x" = %d\n",x)

using namespace std;

int main(){

    cout << "hello world " <<endl;
    write(STDOUT_FILENO,"hello\n",6);
    int fd = open("test.txt",O_RDWR|O_CREAT);
    write(fd,"abcdefg\n",8);
    write(fd,"abcedfg\n",8);
    close(fd);


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

    return 0;
}