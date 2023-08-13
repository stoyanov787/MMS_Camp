#include <stdio.h>
#include <stdint.h>
#define BYTE_SIZE 8

typedef union Double_bits{
    double num_double;
    uint64_t num_int;
}Double_bits;


void print_bits(double num){
    Double_bits bits;
    bits.num_double = num;
    for(int i = (sizeof(num) * BYTE_SIZE) - 1; i >= 0; i--){
        printf("%d", !!((bits.num_int) & (1ULL << i)));
    }
    printf("\n");
}

void print_double_parts(double num){
    Double_bits bits;
    bits.num_double = num;
    uint16_t sign = 0, exponent = 0, mantisa = 0;
    int ex_cnt = 10, m_cnt = 51;
    for(int i = (sizeof(num) * BYTE_SIZE) - 1; i >= 0; i--){
        if(i == 63){
            sign = !!((bits.num_int) & (1ULL << i));
        }else if(i <= 62 && i >= 52){
            exponent |= ((uint64_t)(!!((bits.num_int) & (1ULL << i)))) << ex_cnt;
            ex_cnt--;
        }else{
            mantisa |= ((uint64_t)(!!((bits.num_int) & (1ULL << i)))) << m_cnt;
            m_cnt--;
        }
    }
    printf("Sign: %d\nExponent: %d\nMantisa: %d\n", sign, exponent, mantisa);
}

int main(void){
    double num = -16;
    print_bits(num);
    print_double_parts(num);

    return 0;
}