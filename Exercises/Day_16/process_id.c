#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    int pid = fork();

   if(!pid){
        printf("Sleep 5 seconds\n");
        sleep(5);
    }

    printf("Current pid: %d, Parrent pid: %d\n", getpid(), getppid());

    if(pid != 0) wait(NULL);


    return 0;
}