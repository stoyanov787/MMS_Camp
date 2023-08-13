#include <stdio.h>
#include <unistd.h>

int main(void){
    // int pid = fork();
    //int pid2 = fork();
    // printf("Hello world!, %d\n", pid);

    //sleep(5);
    /*
    if(!pid2){
        printf("Hello from child process with id %d\n", pid2);
    }else{
        printf("Hello from main process with id %d\n", pid2);
    }
    */
    /*
    if(!pid){
        printf("Hello from child process with id %d\n", pid);
    }else{
        printf("Hello from main process with id %d\n", pid);
    }
    */

    int pid1 = fork();
    if(!pid1){
        int pid2 = fork();
        // sleep(3);
        printf("Hello after second fork pid2 id %d\n", pid2);
    }else{
        // sleep(3);
        printf("Hello from main process with pid1 id %d\n", pid1);
    }


    return 0;
}