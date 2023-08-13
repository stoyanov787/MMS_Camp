#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 10

int is_valid_operation(char symbol){
    return symbol == '+' || symbol == '*' || symbol == '-';
}

int calculator(char* str){
    int first, second;
    first = atoi(str);
    while((*str) != ' ')str++;
    second = atoi(str);

    if(!first || !second){
        perror("Invalid input");
        exit(-1);
    }

    while(!is_valid_operation(*str))str++;

    char number[LEN + strlen(str)];
    switch(*str){
            case '+': 
                sprintf(number, "%d", first + second);
                break;
            case '*': 
                sprintf(number, "%d", first * second);
                break;
            case '-': 
                sprintf(number, "%d", first - second);
                break;
    }

    if((*(++str)) == '\0') return atoi(number);
    strcat(number, str);
    return calculator(number);

}


int main(void){
    printf("Input: 1 2 + 3 * 5 -\n");
    printf("Output: %d\n", calculator("1 2 + 3 * 5 -"));
    return 0;
}