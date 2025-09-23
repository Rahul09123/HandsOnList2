/*
========================================================================================================
Name : 30c.c
Author : Rahul Raman
Description : Write a program to create a shared memory. 
                 c. detach the shared memory
Date: 21 Sept, 2025
========================================================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(){

    key_t key = ftok(".", 'a');

    int shmid = shmget(key, 1024, IPC_CREAT | 0666);

    char *data = shmat(shmid, (void *)0, 0);

    printf("Detaching... \n");

    shmdt(data);

    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program30$ gcc 30c.c -o ./30c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program30$ ./30c
Detaching... 
*/