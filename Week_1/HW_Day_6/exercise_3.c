#include <stdio.h>

int isPositive(int num){
    return num >= 0;
}

int addOne(int num){
    return num + 1;
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

    filter_and_map(arr, 8, isPositive, addOne, dest, &new_size);

    for(int i =0; i < new_size; i++){
        printf("%d ", dest[i]);
    }
    printf("\n");

    return 0;
}