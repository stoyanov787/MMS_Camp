#include <stdio.h>
#include <stdint.h>

void print_bits(uint32_t* maskArr, size_t nitems){
    for(int i = 0; i < nitems; i++){
        for(int j = 31; j >= 0; j--){
            printf("%d", !!(maskArr[i] & (1 << j)));
        }
        printf("\n");
    }
}

int clearBits(uint32_t* maskArr, size_t nitems, size_t bit_index){
    for(int i = 0; i < nitems; i++){
        maskArr[i] &= (~(1U << bit_index));
    }
    return 0;
}

int setBits(uint32_t* maskArr, size_t nitems, size_t bit_index){
    for(int i = 0; i < nitems; i++){
        maskArr[i] |= (1U << bit_index);
    }
    return 0;
}

int checkBits(uint32_t* maskArr, size_t len, size_t bit_index){
    if(len == 1) return !!(maskArr[0] & (1 << bit_index));
    int bit = !!(maskArr[0] & (1 << bit_index));
    for(int i = 1; i < len; i++){
        if(bit != (!!(maskArr[i] & (1 << bit_index)))) return -1;
    }
    return bit;
}

int main(void){
    uint32_t arr[] = {3, 2, 4, 8};
    print_bits(arr, 4);
    clearBits(arr, 4, 1);
    printf("\n");
    print_bits(arr, 4);
    setBits(arr, 4, 1);
    printf("\n");
    print_bits(arr, 4);
    printf("\n10th bit is %d\n", checkBits(arr, 4, 10));

    return 0;
}