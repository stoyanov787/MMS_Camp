#include <stdio.h>

// Function to find the average of three numbers
double average(double num1, double num2, double num3){
    return (num1 + num2 + num3) / 3;
}

int main(void){
    double num1, num2, num3;
    printf("Enter number 1: ");
    scanf("%lf", &num1);
    printf("Enter number 2: ");
    scanf("%lf", &num2);
    printf("Enter number 3: ");
    scanf("%lf", &num3);
    printf("The average is: %.2lf\n", average(num1, num2, num3));

    return 0;
}