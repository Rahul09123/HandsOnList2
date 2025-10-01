/*
========================================================================================================
Name : 32c.c
Author : Rahul Raman
Description :   Write a program to implement semaphore to protect any critical section.
                c. protect multiple pseudo resources ( may be two) using counting semaphore
Date: 1 Oct., 2025
========================================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int NUM_THREADS = 3;

sem_t resource_semaphore;

void* use_resource(long tid){
    
    printf("Thread %d is waiting to access a resource.\n", tid);
    
    sem_wait(&resource_semaphore);

    printf("Thread %d has acquired a resource.\n", tid);
    
    sleep(2);

    printf("Thread %d is releasing the resource.\n", tid);

    sem_post(&resource_semaphore);

    return NULL;
}

int main() {

    sem_init(&resource_semaphore, 0, 2);

    pthread_t threads[NUM_THREADS];

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, use_resource, (void*)i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program32$ ./32c
Thread 0 is waiting to access a resource.
Thread 0 has acquired a resource.
Thread 1 is waiting to access a resource.
Thread 1 has acquired a resource.
Thread 2 is waiting to access a resource.
Thread 0 is releasing the resource.
Thread 1 is releasing the resource.
Thread 2 has acquired a resource.
Thread 2 is releasing the resource.
*/