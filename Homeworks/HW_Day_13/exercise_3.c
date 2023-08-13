#include <stdio.h>
#include <stdint.h>
#define MAX(x, y, z) (x > y && x > z ? x : y > x && y > z ? y : z)
#define MIN(x, y, z) (x < y && x < z ? x : y < x && y < z ? y : z)
#define SETBIT(mask, bit) (mask |= (1 << bit))
#define CLEARBIT(mask, bit) (mask &= ~(1 << bit))
#define CHECKBIT(mask, bit) (!!(mask & (1 << bit)))
#define INVERSEBIT(mask, bit) (CHECKBIT(mask, bit) ? CLEARBIT(mask, bit) : SETBIT(mask, bit))
#define SWAP(a, b) int temp = b; b = a, a = temp

int main(void){
    int x = 8, y = 10, z = 9;
    printf("Numbers are: %d %d %d\n", x, y, z);
    printf("Max is %d\n", MAX(x, y, z));
    printf("Min is %d\n", MIN(x, y, z));

    uint8_t a = 1;
    printf("%d with %d bit 1 is ", a, 1);
    printf("%d\n", SETBIT(a, 1));
    printf("With cleared bit is %d\n", CLEARBIT(a, 1));
    printf("Check 1 bit is %d\n", CHECKBIT(a, 1));
    printf("With inversed bit is %d\n", INVERSEBIT(a, 1));
    
    printf("%d and %d swaped are ", x, y);
    SWAP(x, y);
    printf("%d and %d\n", x, y);


    return 0;
}