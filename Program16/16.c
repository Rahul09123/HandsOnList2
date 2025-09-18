/*
============================================================================
Name : 16.c
Author : Rahul Raman
Description : Write a program to send and receive data from parent to child vice versa. Use two way
                communication.
Date: 11th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(){
    int fd1[2]; //1st pipe
    int fd2[2]; //2nd pipe
    pipe(fd1);
    pipe(fd2);
    char buffer1[100];
    char buffer2[100];

    if(!fork()){
        close(fd1[0]);
        close(fd2[1]);
        write(fd1[1],"hello From Child\n",17); //sending from child to parent
        read(fd2[0],buffer1,sizeof(buffer1));
        printf("from parent to child : %s\n",buffer1);

    }else{
        close(fd1[1]);
        close(fd2[0]);
        write(fd2[1] ,"Hello from parent\n",19); //sending from parent to child
        read(fd1[0],buffer2,sizeof(buffer2));
        printf("from child to parent : %s\n" ,buffer2);
        sleep(1);
    }
    return 0;
}
/*
============================================================================
Output:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/HandsOnList2/Program16$ cc h16a.c
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/HandsOnList2/Program16$ ./a.out
from child to parent : hello From Child
from parent to child : Hello from parent
============================================================================

*/