#include <stdio.h>
#include <math.h>

int main(void) {
    int number = 10;
    int base = 2;
    int result = 0;
    int placeValue = 0;
    while (number > 0){
        int digit = number % base;
        result += digit * pow(10, placeValue);
        placeValue++;
        number /= base;
    }
    printf("%d\n", result);

    return 0;
}