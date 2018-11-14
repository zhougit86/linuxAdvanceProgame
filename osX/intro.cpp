#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

int smain(int argc, char* argv[]){
    char *str = argv[1];
    while(1){
        sleep(1000);
        cout <<str<<endl;
    }
    return 0;
}