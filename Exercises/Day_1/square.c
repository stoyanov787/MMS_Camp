#include <stdio.h>

// Function to square a number
int square(int num){
    return num * num;
}

int main(void){
    int number = 10;
    printf("The suare of %d is %d\n", number, square(number));

    return 0;
}