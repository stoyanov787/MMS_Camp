#include <stdio.h>
#include <math.h>

int main(void) {
    int number = 347;
    int base = 10;
    int result = 0;
    int placeValue = 0;
    while (number > 0){
        int digit = number % base;
        result += digit * pow(base, placeValue);
        placeValue++;
        number /= base;
    }
    printf("%d\n", result);

    return 0;
}