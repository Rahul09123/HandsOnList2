/*
===========================================================================================================================
Name : 21a.c
Author : Rahul Raman
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 30th Sept, 2025.
===========================================================================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main(){
    //creating 2 fifo
    mkfifo("myfifo1",0666);
    mkfifo("myfifo2",0666);

    int fd1 ,fd2;
    char buf[50];

    printf("Process 1 Started \n");

    while(1){
        fd1 = open("myfifo1",O_WRONLY);
        printf("Enter the text:\n");
        fgets(buf,sizeof(buf),stdin);
        write(fd1,buf,strlen(buf)+1);
        close(fd1);

        fd2 = open("myfifo2",O_RDONLY);
        read(fd2,buf,sizeof(buf));
        printf("Process 2: %s",buf);
        close(fd2);

    }

    return 0;
}

/*
Output:
Terminal 1:
asus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program21$ ./21a
Process 1 Started 
Enter the text:
Hello
Process 2: hi
Enter the text:
^Z
[2]+  Stopped                 ./21a

Terminal 2:
sus@asus-TUF-Gaming-FX505DT-FX505DT:~/Desktop/MT2025100(Rahul Raman)/HandsOnList2/Program21$ ./21b
Process 2 Started 
Message from Process 1 :Hello

Enter a Message for Process 1
hi
^Z
[2]+  Stopped                 ./21b


*/