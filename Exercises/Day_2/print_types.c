#include <stdio.h>

int main(void){
    char my_char = 'a';
    int my_int = 36;
    float my_float = 3.14;
    double my_double = 3.14159265359;
    _Bool my_bool = 1;
    
    printf("Char: %c\n", my_char);
    printf("Int: %d\n", my_int);
    printf("Float: %.2f\n", my_float);
    printf("Double: %lf\n", my_double);
    printf("Bool: %d\n", my_bool);
    
    return 0;
}

