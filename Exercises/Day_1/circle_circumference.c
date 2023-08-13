#include <stdio.h>
#define PI 3.14

// Function to find the circumference of a circle
double circumference(double radius){
    return 2 * radius * PI;
}

int main(void){
    double radius = 8;
    printf("The circumference of a circle with radius %.2lf is %.2lf\n", radius, circumference(radius));

    return 0;
}