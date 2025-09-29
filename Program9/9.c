 /*
========================================================================================================
Name : 9.c
Author : Rahul Raman
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
Date: 29 Sept, 2025
========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(){

    printf("ignoring SIGINT signal. \n");
    signal(SIGINT, SIG_IGN);
    // CTRL + C is ignored.
    sleep(5);
    printf("\nDefault action of SIGINT signal. \n");
    signal(SIGINT, SIG_DFL);
    // CTRL + C is no longer ignored.
    sleep(5);

    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program9$ ./9.out
ignoring SIGINT signal. 

Default action of SIGINT signal. 
*/