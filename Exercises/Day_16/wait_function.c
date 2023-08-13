#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    int pid = fork();
    int n;

    if(!pid){
        n = 1;
        // printf("Child\n");
    }else{
        n = 6;
        // printf("Parent\n");
    }

    if(pid != 0) wait(NULL);

    for(int i = n; i < n + 5; i++){
        printf("%d ", i);
        fflush(stdout);
    }
    if(pid != 0) printf("\n");

    return 0;
}