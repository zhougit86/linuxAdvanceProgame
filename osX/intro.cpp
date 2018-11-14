#include <iostream>
#include <stdlib.h>
#include <sys/time.h>

using namespace std;

int main(int argc, char* argv[]){
    char *str = argv[1];
    while(1){
        Spin(1);
        cout <<str<<endl;
    }
    return 0;
}