#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]){
    // char *str = argv[1];
    // while(1){
    //     sleep(1);
    //     cout <<str<<endl;
    // }

    int* p = malloc(sizeof(int));
    printf("%p\n",p);

    return 0;
}