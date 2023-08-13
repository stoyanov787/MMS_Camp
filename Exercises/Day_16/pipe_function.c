#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/errno.h>

int main(void){
    int fd[2];

    if(pipe(fd) == -1){
        printf("Error! Cannot open pipe\n");
        return 1;
    }

    int pid = fork();

    if(pid == -1){
        printf("Error with fork\n");
        return 2;
    }
    
    if(pid == 0){
        close(fd[0]);
        int num1;
        printf("Enter number: ");
        scanf("%d", &num1);
        if(write(fd[1], &num1, sizeof(num1)) == -1){
            printf("Error with writing\n");
            return 3;
        }
        close(fd[1]);
    }else{
        close(fd[1]);
        int num2;
        if(read(fd[0], &num2, sizeof(num2)) == -1){
            printf("Error with reading\n");
            return 4;
        }
        printf("Read from child: %d\n", num2);
        num2 *= 10;
        printf("The result is: %d\n", num2);
        close(fd[0]);
    }


    return 0;
}