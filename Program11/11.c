/*
========================================================================================================
Name : 11.c
Author : Rahul Raman
Description : Write a program to ignore a SIGINT signal then 
            reset the default action of the SIGINT signal - use sigaction system call.
Date: 27 Sept, 2025
========================================================================================================
*/

#include <bits/sigaction.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

int main(){
    struct sigaction act;
    
    memset(&act, 0, sizeof(act));
    act.sa_handler = SIG_IGN;
    printf("Ignoring SIGINT\n");
    sigaction(SIGINT, &act, NULL);
    sleep(5);
    
    memset(&act, 0, sizeof(act));
    act.sa_handler = SIG_DFL;
    printf("\nDefault of SIGINT\n");
    sigaction(SIGINT, &act, NULL);
    sleep(5);
    
    return(0);
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program11$ gcc 11.c 
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program11$ ./a.out 
Ignoring SIGINT

Default of SIGINT
*/