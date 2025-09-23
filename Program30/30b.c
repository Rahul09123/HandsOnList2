/*
========================================================================================================
Name : 30b.c
Author : Rahul Raman
Description : Write a program to create a shared memory. 
                b. attach with O_RDONLY and check whether you are able to overwrite. 
Date: 21 Sept, 2025
========================================================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>

int main() {

    key_t key = ftok(".", 'a');

    int shmid = shmget(key, 1024, IPC_CREAT | 0666);

    char *data = shmat(shmid, NULL, 0);

    printf("Enter the text to be put in the shared memory: ");
    scanf("%[^\n]s", data);

    printf("Written successful: %s\n", data);
    shmdt(data);

    return 0;
}
/*
========================================================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program30$ gcc 30b.c -o ./30b
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program30$ ./30b
Enter the text to be put in the shared memory: Text inside the shared memory
Written successful: Text inside the shared memory
========================================================================================================
*/