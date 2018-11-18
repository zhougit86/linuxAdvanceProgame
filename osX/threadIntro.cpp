#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;

void *mythread(void *arg){
    int a = 0;
    for(int i=0;i<5000;i++){
        a+=1;
    }
    cout<< a<<endl;

    *(int *)arg = a;

    // cout << (char *)arg <<endl;
    // return NULL;
}

int main(int argc, char *argv[]){
    pthread_t p1,p2;

    int rc;

    cout <<"main: begin" <<endl;
    int *a,*b;

    rc = pthread_create(&p1,NULL,mythread,(void *)a);
    rc = pthread_create(&p2,NULL,mythread,(void *)b);

    rc=pthread_join(p1,NULL);
    rc=pthread_join(p2,NULL);
    cout<<*a<<*b<<endl;
    cout <<"main: end"<<endl;
    return 0;
}
