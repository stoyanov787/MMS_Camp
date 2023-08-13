#include <stdio.h>
#define REL_TOL 0.01 // Relevant tolerance

double my_abs(double num){
    if(num < 0) return -num;
    return num;
}

double cube_root(double num){
    for(double i = num / 2; i <= num;){
        if(my_abs((i * i * i) - num) <= REL_TOL){
            return i;
        }
        if((i * i * i) < num) i += (num - i) / 2;
        else i -= (num - i) / 2;
    }
    return 0;
}

int main(void){
    double num = 27;

    printf("%.2lf\n", cube_root(num));

    return 0;
}