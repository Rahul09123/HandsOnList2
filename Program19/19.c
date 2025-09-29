/*
============================================================================
Name : 19.c
Author : Rahul Raman
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 29th Sep, 2025.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    char name[50];
    printf("Enter the name of fifo file: ");
    scanf("%s", name);

    int ch;
    printf("Choose an option:\n1.) mknod system call\n2.) mkfifo system call\n=> ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("Using mknod .\n");
        mknod(name, __S_IFIFO | 0744, 0);
        printf("FIFO file created using mknod\n");
        break;
    case 2:
        printf("Using mkfifo .\n");
        mkfifo(name, 0744);
        printf("FIFO file created using mkfifo\n");
        break;

    default:
        printf("Invalid choice\n");
        break;
    }

    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program19$ gcc 19.c -o ./19.out
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program19$ ./19.out
Enter the name of fifo file: myFifo
Choose an option:
1.) mknod system call
2.) mkfifo system call
=> 2
Using mkfifo .
FIFO file created using mkfifo
*/