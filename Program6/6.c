/*
========================================================================================================
Name : 6.c
Author : Rahul Raman
Description : Write a simple program to create three threads.
Date: 21 Sept, 2025
========================================================================================================
*/

#include <stdio.h>
#include <string.h>
#include <pthread.h>

void* foo(void* p){

    int threadID = *((int*)p);
    printf("Thread %d is under execution\n", threadID);
    return NULL;
}

int main(){

  pthread_t id[3];

  int id1 = 1;
  int id2 = 2;
  int id3 = 3;
  
  pthread_create(&id[0], NULL, foo, &id1);
  pthread_create(&id[1], NULL, foo, &id2); 
  pthread_create(&id[2], NULL, foo, &id3);
  
  pthread_join(id[0], NULL);
  pthread_join(id[1], NULL);
  pthread_join(id[3], NULL);
  
  return 0;
}
/*
========================================================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program6$ cc 6.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program6$ ./a.out
Thread 1 is under execution
Thread 2 is under execution
Thread 3 is under execution
Segmentation fault (core dumped)
========================================================================================================
*/

