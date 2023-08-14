#include <stdio.h>
#include <stdlib.h>
#include "my_stack.h"
#define MAX_LEN 10

Stack* init(size_t max_capacity){
    Stack* new_stack = malloc(sizeof(Stack));;
    new_stack->size = 0;
    new_stack->capacity = MAX_LEN;
    new_stack->data = malloc(sizeof(int) * new_stack->capacity);
    return new_stack;
}

int push(Stack* stack, int element){
    if(stack->size + 1 >= stack->capacity){
        printf("Stack is full\n");
        return -1;
    }
    stack->data[stack->size++] = element;
    return 0;
}

int pop(Stack* stack){
    if(stack->size == 0){
        printf("The stack is empty\n");
        return -1;
    } 
    stack->size--;
    return 0;
}

void print_stack(Stack* stack){
    for(int i = 0; i < stack->size; i++){
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}
