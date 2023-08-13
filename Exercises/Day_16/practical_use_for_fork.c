#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/errno.h>

int main(void){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int start = 0, end = arr_size - 1, mid = arr_size / 2;

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
        int sum1 = 0;
        for(int i = 0; i < mid; i++){
            sum1 += arr[i];
        }
        if(write(fd[1], &sum1, sizeof(sum1)) == -1){
            printf("Error with writing\n");
            return 3;
        }
        close(fd[1]);
    }else{
        close(fd[1]);
        int sum2 = 0;
        for(int i = mid; i <= end; i++){
            sum2 += arr[i];
        }
        if(read(fd[0], &sum2, sizeof(sum2)) == -1){
            printf("Error with reading\n");
            return 4;
        }
        printf("Sum 1: %d\n", sum2);

        close(fd[0]);
    }


    return 0;
}