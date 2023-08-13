#include <stdio.h>

// Function to find the sum of two numbers
int sum(int num1, int num2){
    return num1 + num2;
}

int main(void){
    int num1, num2;
    printf("Enter number 1: ");
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);
    printf("The sum is: %d\n", sum(num1, num2));

    return 0;
}