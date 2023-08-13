#include <stdio.h>
#include <stdint.h>

void swapBytes(uint16_t* word){
    uint8_t left, right;
    for(int i = 0, j = 8; i < 8; i++, j++){
        left = !!((*word) & (1U << i));
        right = !!((*word) & (1U << j));
        if(left) (*word) |= (1U << j);
        else (*word) &= ~(1U << j);
        if(right) (*word) |= (1U << i);
        else (*word) &= ~(1U << i);
    }
}

void print_bits(uint16_t word){
    for(int i = 15; i >= 0; i--){
        printf("%d", !!((word) & (1U << i)));
    }
    printf("\n");
}

int main(void){
    uint16_t word = 0b1101111100000000;
    print_bits(word);
    swapBytes(&word);
    print_bits(word);


    return 0;
}