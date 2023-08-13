#include <stdio.h>
#include "my_math.h"

int main(void){
    double number = 5.00;
    printf("The square of %.2lf is %.2lf\n", number, square(number));
    printf("The cube of %.2lf is %.2lf\n", number, cube(number));

    return 0;
}