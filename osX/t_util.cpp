#include <pthread.h>
#include <assert.h>

void Pthread_mutex_lock(pthread_mutex_t *mutex){
    int rc = pthread_mutex_lock(mutex);
    assert(rc==0);
}

void Pthread_mutex_unlock(pthread_mutex_t *mutex){
    int rc = pthread_mutex_unlock(mutex);
    assert(rc==0);
}