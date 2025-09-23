/*
========================================================================================================
Name : 30a.c
Author : Rahul Raman
Description : Write a program to create a shared memory. 
                a. write some data to the shared memory
Date: 21 Sept, 2025
========================================================================================================
*/

#include <stdio.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main()
{
    key_t key = ftok(".", 'a'); //generate a unique key
    int shmid = shmget(key, 1024, IPC_CREAT | 0666); //creates a new shared memory  
    char *data = shmat(shmid, (void *)0, 0);
    printf("Enter text to put in shared memory: ");
    scanf("%[^\n]s", data);
    printf("Write successful\n");
    
    return 0;
}
/*
Output:
========================================================================================================
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program30$ cc 30a.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program30$ ./a.out
Enter text to put in shared memory: Hello 
Write successful               
========================================================================================================
*/