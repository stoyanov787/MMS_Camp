#include <stdio.h>

// Function to convert fahrenheit to celsius
double fahrenheit_to_celsius(double fahrenheit){
    return (fahrenheit - 32) * 5 / 9;
}

int main(void){
    double fahrenheit;
    printf("Enter fahrenheit: ");
    scanf("%lf", &fahrenheit);

    printf("%.2lf fahrenheit is equal to %.2lf celsius\n", fahrenheit, fahrenheit_to_celsius(fahrenheit));

    return 0;
}