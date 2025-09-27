/*
===========================================================================================================================
Name : 2.c
Author : Rahul Raman
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 24th Sept, 2025.
===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void lim(int resource, const char *resource_name) {
    struct rlimit limit;

    if (getrlimit(resource, &limit) == 0) 
    {
        printf("%s:\n", resource_name);
        printf("  soft limit: %ld\n", limit.rlim_cur);
        printf("  hard limit: %ld\n", limit.rlim_max);
    } 
}

int main() {

    lim(RLIMIT_CPU, "CPU time limit");
    lim(RLIMIT_FSIZE, "File size limit");
    lim(RLIMIT_STACK, "Stack size limit");
    lim(RLIMIT_NOFILE, "Number of open files limit");
    lim(RLIMIT_NPROC, "Number of processes limit");

    return 0;
}
/*
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program2$ gcc 2.c -o 2.out
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program2$ ./2.out
CPU time limit:
  soft limit: -1
  hard limit: -1
File size limit:
  soft limit: -1
  hard limit: -1
Stack size limit:
  soft limit: 8388608
  hard limit: -1
Number of open files limit:
  soft limit: 1048576
  hard limit: 1048576
Number of processes limit:
  soft limit: 28927
  hard limit: 28927
*/