#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef struct MyTime{
    int year : 11;
    int month : 4;
    int day : 5;
    int hour : 5;
    int minutes : 6;
    int seconds : 6;
}MyTime;

int isLeapYear(MyTime t){
    return (t.year % 400 == 0) || ((t.year % 4 == 0) && (t.year % 100 != 0));
}

int totalDaysInYear(MyTime t){
    return 365 + isLeapYear(t);
}

void printMonth(MyTime t){
    switch(t.month){
        case 1: 
            printf("January\n");
            break;
        case 2: 
            printf("February\n");
            break;
        case 3: 
            printf("March\n");
            break;
        case 4: 
            printf("April\n");
            break;
        case 5: 
            printf("May\n");
            break;
        case 6: 
            printf("June\n");
            break;
        case 7: 
            printf("July\n");
            break;
        case 8: 
            printf("August\n");
            break;
        case 9: 
            printf("September\n");
            break;
        case 10: 
            printf("October\n");
            break;
        case 11: 
            printf("November\n");
            break;
        case 12: 
            printf("December\n");
            break;    
    }
}

int secondsPassed(MyTime t){
    unsigned long long seconds = 0;
    seconds += (t.year - 1970) * 365 * 24 * 60 * 60;
    seconds += t.month * 31 * 24 * 60 * 60;
    seconds += t.hour;
    seconds += t.seconds;
    printf("%ld\n", time(NULL));
}



int main(void){
    MyTime t = {2023, 5, 10, 2, 55, 43};
    printf("Size: %ld\n", sizeof(t));
    if(isLeapYear(t)) printf("Leap year\n");
    else printf("Not leap year\n");
    printf("Total days in year: %d\n", totalDaysInYear(t));
    printMonth(t);

    return 0;
}