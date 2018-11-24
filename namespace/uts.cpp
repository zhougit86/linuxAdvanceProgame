#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <sched.h>

#define NOT_OK_EXIT(code, msg); {if(code == -1){perror(msg); exit(-1);} }

using namespace std;

int main(int argc , char* argv[]){
    cout << "hello" <<endl;

    char* hostname;

    cout << gethostname(hostname,100) <<endl;

    
}