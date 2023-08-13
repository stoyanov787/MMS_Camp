#include <stdio.h>
#include <stdarg.h>
#include <time.h>

int printf_time(const char *format, ...){
    va_list args;

    va_start(args, format);

    time_t t;
    time(&t);
    printf("%s", ctime(&t));
 
    while(*format != '\0'){
        if(*format == 'd'){
            int num = va_arg(args, int);
            printf("%d ", num);
        }
        format++;
    }
    printf("\n");
   
    va_end(args);
 
    return 0;
}

int main(void){
    printf_time("%d %d", 10, 20);
    return 0;
}