#include <stdio.h>

int is_even(int num){
    return num % 2 == 0;
}

int square(int num){
    return num * num;
}

int is_prime(int num){
    if(num <= 1) return 0;
    for(int i = 2; i < num; i++){
        if(num % i == 0) return 0;
    }

    return 1;
}

int bits_count(int num){
    int len = sizeof(num) * 8;
    int count = 0;
    for(int i = 0; i < len; i++){
        count += !!(num & (1 << i));
    }
    return count;
}

int isPositive(int num){
    return num >= 0;
}

int addOne(int a){
    return a + 1;
}

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int),
int (*map_f)(int), int dest[], size_t* dest_cnt){
    *dest_cnt = 0;
    for(int i = 0; i < n; i++){
        if(filter_f(arr[i])){
            dest[(*dest_cnt)++] = map_f(arr[i]);
        } 
    }
}

int main(void){
    int arr[8] = {1, 2, 3, 4, -1, -2, 11, -100};
    int dest[10];
    size_t new_size;

    filter_and_map(arr, 8, isPositive, bits_count, dest, &new_size);

    for(int i = 0 ; i < new_size; i++){
        printf("%d ", dest[i]);
    }
    printf("\n");

    return 0;
}