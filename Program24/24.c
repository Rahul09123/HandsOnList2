/*
========================================================================================================
Name : Q24.c
Author : Rahul Raman
Description : Write a program to create a message queue and print the key and message queue id.
Date: 20 Sept, 2025.
========================================================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    printf("Key: %d, ID: %d\n", key, msqid);
    return(0);
}
/*
========================================================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program24$ ./a.out
Key: 1627724368, ID: 0

========================================================================================================
*/