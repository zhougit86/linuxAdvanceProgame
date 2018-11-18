#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include "t_util.h"

using namespace std;

int static volatile globalNumber = 0;
pthread_mutex_t static lock;

void *mythread(void *arg){
    int aa = 0;
    for(int i=0;i<5000;i++){
        Pthread_mutex_lock(&lock);
        globalNumber++;
        Pthread_mutex_unlock(&lock);
        aa+=1;
    }
    cout<< aa<<endl;

    *(int *)arg = aa;

    // cout << (char *)arg <<endl;
    return NULL;
}

int main(int argc, char *argv[]){
    pthread_t p1,p2;

    int rc;
    pthread_mutex_init(&lock,NULL);

    cout <<"main: begin" <<endl;
    int a,b;

    rc = pthread_create(&p1,NULL,mythread,(void *)&a);
    rc = pthread_create(&p2,NULL,mythread,(void *)&b);

    rc=pthread_join(p1,NULL);
    rc=pthread_join(p2,NULL);
    cout<<b<<endl;
    cout <<"main: end"<<endl;
    cout<<a<<endl;
    cout<<globalNumber<<endl;
    return 0;
}
