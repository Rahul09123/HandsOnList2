/*
========================================================================================================
Name : 30d.c
Author : Rahul Raman
Description : Write a program to create a shared memory. 
                d. remove the shared memory
Date: 21 Sept, 2025
========================================================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(){

    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, 0);

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        printf("Delete is unsuccessful\n");
    }
    else
    {
        printf("Deleted successfully\n");
    }

    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program30$ gcc 30d.c -o ./30d
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program30$ ./30d
Deleted successfully
*/