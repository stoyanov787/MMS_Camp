#include <stdio.h>
#define DEBUG

int main(void){
    // check if DEBUG is defined
    #ifdef DEBUG
    printf("Debug mode is on\n");
    #else
    printf("Debug mode is off\n");
    #endif

    return 0;
}