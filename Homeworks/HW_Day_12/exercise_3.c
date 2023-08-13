#include <stdio.h>
#include <stdarg.h>
#include <time.h>

int my_printf(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);

    int cnt = 0;
 
    while(*fmt != '\0'){
        if(*fmt == '%'){
            fmt++;
            switch(*fmt){
                case 'd': 
                    printf("%d", va_arg(args, int));
                    break;
                case 'f': 
                    printf("%f", va_arg(args, double));
                    break;
                case 'c': 
                    printf("%c", va_arg(args, int));
                    break;
            }
        }else{
            putc(*fmt, stdout);
        }
        cnt++;
        fmt++;
    }
   
    va_end(args);
 
    return cnt;
}

int main(void){
    my_printf("Hello %d and %f and %c\n", 10, 3.14, 'A');
    return 0;
}