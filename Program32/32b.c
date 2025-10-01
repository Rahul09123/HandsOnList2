/*
========================================================================================================
Name : 32b.c
Author : Rahul Raman
Description :   Write a program to implement semaphore to protect any critical section.
                b. protect shared memory from concurrent write access
Date: 1 Oct., 2025
========================================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int NUM_THREADS = 3;

int shared_memory = 0;

sem_t semaphore;

void* write_to_shared_memory(int tid) {

    printf("Thread %d is waiting to write to shared memory.\n", tid);

    sem_wait(&semaphore);

    int temp = shared_memory;
    printf("Thread %d reads shared memory: %d\n", tid, temp);
    
    sleep(1);

    temp += 10;  
    shared_memory = temp;
    printf("Thread %d writes to shared memory: %d\n", tid, shared_memory);

    sem_post(&semaphore);

    return NULL;
}

int main() {

    sem_init(&semaphore, 0, 1);

    pthread_t threads[NUM_THREADS];

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, write_to_shared_memory, (void*)i);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);

    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program32$ ./32b
Thread 0 is waiting to write to shared memory.
Thread 0 reads shared memory: 0
Thread 2 is waiting to write to shared memory.
Thread 1 is waiting to write to shared memory.
Thread 0 writes to shared memory: 10
Thread 2 reads shared memory: 10
Thread 2 writes to shared memory: 20
Thread 1 reads shared memory: 20
Thread 1 writes to shared memory: 30

*/