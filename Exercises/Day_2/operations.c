#include <stdio.h>

int main(void){
    int x = 10;
    int y = 20;
    int z;
    z = x + y;
    printf("The sum of x and y is: %d\n", z);
    z = x - y;
    printf("The difference between x and y is: %d\n", z);
    z = x * y;
    printf("The product of x and y is: %d\n", z);
    z = x / y;
    printf("The quotient of y divided by x is: %d\n", z);
    z = y % x;
    printf("The remainder of y divided by x is: %d\n", z);

    return 0;
}