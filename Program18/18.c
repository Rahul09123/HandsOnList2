/*
============================================================================
Name : 18.c
Author : Rahul Raman
Description : Write a program to find out total number of directories on the pwd. 
                execute ls -l | grep ^d | wc ? Use only dup2.
Date: 29th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int fd1[2], fd2[2];

    pipe(fd1);
    pipe(fd2);

    if (!fork()) //child 1
    {
        dup2(fd1[1], 1); 
        close(fd1[0]);
        close(fd2[0]);
        close(fd2[1]);
        execl("/bin/ls", "/bin/ls", "-l", NULL);
    }
    else
    {
        if (!fork()) //child 2
        {
            dup2(fd1[0], 0); 
            dup2(fd2[1], 1); 
            close(fd1[1]);
            close(fd2[0]);
            execl("/bin/grep", "/bin/grep", "^d", NULL);
        }
        else
        { //parent
            dup2(fd2[0], 0);
            close(fd2[1]);
            close(fd1[0]);
            close(fd1[1]);
            execl("/bin/wc", "/bin/wc", "-l", NULL);
        }
    }

    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program18$ ./18.out
0
*/