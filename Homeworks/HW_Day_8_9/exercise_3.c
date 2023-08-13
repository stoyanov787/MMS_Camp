#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct Point {
    double x;
    double y;
    double z;
} Point;

typedef struct Human {
    double weight_kg;
    uint16_t height_cm;
} Human;

typedef union Bits{
    float x;
    int y;
}Bits;

int compare_int(const void* a, const void* b){
    if(*((uint64_t*)a) == *((uint64_t*)b)) return 0;
    if(*((uint64_t*)a) > *((uint64_t*)b)) return -1;
    else return 1;
}

int compare_point(const void* a, const void* b){
    double a_distance = sqrt(pow(((Point*)a)->x, 2) + pow(((Point*)a)->y, 2) + pow(((Point*)a)->z, 2));
    double b_distance = sqrt(pow(((Point*)b)->x, 2) + pow(((Point*)b)->y, 2) + pow(((Point*)b)->z, 2));

    if(a_distance == b_distance) return 0;
    if(a_distance > b_distance) return -1;
    else return 1;
}

int compare_human(const void* a, const void* b){
    double a_body_mass_index = ((Human*)a)->weight_kg / ((((Human*)a)->height_cm / 100.00) * (((Human*)a)->height_cm / 100.00));
    double b_body_mass_index = ((Human*)b)->weight_kg / ((((Human*)b)->height_cm / 100.00) * (((Human*)b)->height_cm / 100.00));

    if(a_body_mass_index == b_body_mass_index) return 0;
    if(a_body_mass_index > b_body_mass_index) return -1;
    else return 1;
}

int compare_float(const void* a, const void* b){
    Bits a_bits, b_bits;
    a_bits.x = (*((float*)a));
    b_bits.x = (*((float*)b));
    int a_bits_count = 0, b_bits_count = 0;

    for(int i = 0; i < sizeof(float) * 8; i++){
        a_bits_count += !!(a_bits.y & (1 << i));
        b_bits_count += !!(b_bits.y & (1 << i));
    }

    if(a_bits_count == b_bits_count) return 0;
    if(a_bits_count > b_bits_count) return -1;
    else return 1;
}

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*)){
    void* max = arr;
    for(int i = 1; i < n; i++){
        if(cmp(max, arr + i) == 1){
            max = arr + (i * elem_s);
        }
    }
    return max;
}

int main(void){
    uint64_t arr[] = {1, 2, 3, 4, 5, 6};
    uint64_t* max = (uint64_t*)findMax(arr, 6, sizeof(uint64_t), compare_int);
    printf("Max is %ld\n", *max);

    Human humans[2];
    humans[0].weight_kg = humans[0].height_cm = 100;
    humans[0].weight_kg = humans[0].height_cm = 200;
    Human* max_humans = (Human*)findMax(humans, 2, sizeof(Human), compare_human);
    printf("Max body mass index is %.2lf, %d\n", max_humans->weight_kg, max_humans->height_cm);

    Point points[2];
    points[0].x = points[0].y = points[0].z = 3;
    points[1].x = points[1].y = points[1].z = 2;
    Point* max_points = (Point*)findMax(points, 2, sizeof(Point), compare_point);
    printf("Max distance is %.2lf, %.2lf, %.2lf\n", max_points->x, max_points->y, max_points->z);

    float arr_floats[] = {0, 2, 4, 16, 256, 0};
    float* max_bits = (float*)findMax(arr_floats, 6, sizeof(float), compare_float);
    printf("Max bits 1 has in %.2f\n", *max_bits);

    return 0;
}