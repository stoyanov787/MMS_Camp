#include <stdio.h>
#include <stdlib.h>

int main(void){
    int b = 5;
    void *a = &b;


    printf("%p\n", a);
    a++;
    printf("%p\n", a);

    return 0;
}