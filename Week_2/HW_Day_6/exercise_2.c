#include <stdio.h>
#include <stdint.h>
#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT8 5
#define TUINT16 6
#define TUINT32 7
#define TUINT64 8

void printValue(const void* valuePtr, uint8_t flag){
    switch(flag){
        case 1:
            printf("Value: %d\n", *(int*)valuePtr);
            break;
        case 2:
            printf("Value: %c\n", *(char*)valuePtr);
            break;
        case 3:
            printf("Value: %lf\n", *(double*)valuePtr);
            break;
        case 4:
            printf("Value: %f\n", *(float*)valuePtr);
            break;
        case 5:
            printf("Value: %u\n", *(uint8_t*)valuePtr);
            break;
        case 6:
            printf("Value: %hu\n", *(uint16_t*)valuePtr);
            break;
        case 7:
            printf("Value: %u\n", *(uint32_t*)valuePtr);
            break;
        case 8:
            printf("Value: %lu\n", *(uint64_t*)valuePtr);
            break;
    }
}

int main(void){
    int a = 5;
    printValue(&a, TINT);

    double b = 3.14159;
    printValue(&b, TDOUBLE);

    char c = 'A';
    printValue(&c, TCHAR);
    
    return 0;
}