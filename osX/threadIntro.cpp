#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;

void *mythread(void *arg){
    cout << (char *)arg <<endl;
    return NULL;
}

int main(int argc, char *argv[]){
    pthread_t p1,p2;

    int rc;

    cout <<"main: begin" <<endl;


    rc = pthread_create(&p1,NULL,mythread,"A");
    rc = pthread_create(&p2,NULL,mythread,"B");

    rc=pthread_join(p1,NULL);
    rc=pthread_join(p2,NULL);
    cout <<"main: end"<<endl;
    return 0;
}