#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_digit(char symbol){
    return symbol >= '0' && symbol <= '9';
}

int is_valid_operation(char symbol){
    return symbol == '+' || symbol == '*' || symbol == '^';
}

int calculator(char* str){
    if(is_digit(*str)) return atoi(str);

    str++;
    str[strlen(str) - 1] = '\0';

    int len = 0;
    char* temp = malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(temp, str);
    
    if(is_digit(*str)){
        for(temp++; is_digit(*temp); temp++, len++);
        int number = atoi(str);

        switch(*temp){
            case '+': return number + calculator(++temp);
            case '*': return number * calculator(++temp);
            case '^': return pow(number, calculator(++temp));
        }
    }
    else{
        for(; (*temp) != ')'; temp++, len++);

        for(; !is_valid_operation(*temp); temp++, len++);

        str[len] = '\0';

        switch(*temp){
            case '+': return calculator(str) + calculator(++temp);
            case '*': return calculator(str) * calculator(++temp);
            case '^': return pow(calculator(str), calculator(++temp));
        }
    }
}

int main(void){
    char arr[] = "((5+(3+(4+2)))+(2^10))";

    printf("%d\n", calculator(arr));

    return 0;
}