#include <stdio.h>

int main(void){
    int age = 25;
    int weight = 60;
    if(age >= 18 && weight < 100){
        printf("You are eligible to donate blood.\n");
    }
    else if(age < 18 || weight >= 100) {
        printf("You are not eligible to donate blood.\n");
    }
    else if(!(age < 18) ){
    printf("You are old enough to vote.\n");
    }

    return 0;
}