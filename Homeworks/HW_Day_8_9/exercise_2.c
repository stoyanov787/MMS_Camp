#include <stdio.h>
#include <stdlib.h>

int compare_int(const void* a, const void* b){
    if(*((int*)a) == *((int*)b)) return 0;
    if(*((int*)a) > *((int*)b)) return -1;
    else return 1;
}

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*)){
    void* max = arr;
    for(int i = 1; i < n; i++){
        if(compare_int(max, arr + i) == 1){
            max = arr + (i * elem_s);
        }
    }
    return max;
}

int main(void){
    int arr[] = {1, 2, 3, 4, 5, 6};

    int* max = (int*)findMax(arr, 6, sizeof(int), compare_int);
    
    printf("Max is %d\n", *max);
    
    return 0;
}