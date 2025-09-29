/*
========================================================================================================
Name : 7.c
Author : Rahul Raman
Description : Write a simple program to print the created thread ids.
Date: 29 Sept, 2025
========================================================================================================
*/
#include <pthread.h>
#include <stdio.h>


void show_thread(void)
{
    
    printf("Thread : %ld\n", pthread_self());

}

int main()
{
    pthread_t th1, th2, th3;

    pthread_create(&th1, NULL, (void *)show_thread, NULL);
    pthread_create(&th2, NULL, (void *)show_thread, NULL);
    pthread_create(&th3, NULL, (void *)show_thread, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);
    return 0;
}
/*
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program7$ gcc 7.c -o 7.out
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program7$ ./7.out
Thread : 139801061750464
Thread : 139801053357760
Thread : 139800917046976
*/