#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <sys/fcntl.h>
#include <sys/stat.h>

int main(void){
    if(mkfifo("my_fifo", 07777) == -1){
        printf("Cannot create FIFO file\n");
        return 1;
    }

    printf("Opening...\n");
    int fd = open("my_fifo", O_WRONLY);
    printf("Opened!\n");

    char value = 'a';
    if(write(fd, &value, sizeof(value)) == -1){
        printf("Problem with writing\n");
        return 2;
    }
    printf("Written\n");

    close(fd);
    printf("Closed\n");

    return 0;
}