#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    int n;
    printf("n: ");
    scanf("%d", &n);

    double *arr = malloc(sizeof(double) * n);
    if(arr == NULL){
        perror("Unable to allocate memory");
        exit(-1);
    }

    for(int i = 0; i < n; i++){
        arr[i] = (rand() % 101) / 100.;
    }

    int m;
    printf("m: ");
    scanf("%d", &m);

    arr = realloc(arr, sizeof(double) * (n + m));
    if(arr == NULL){
        perror("Unable to allocate memory");
        exit(-1);
    }

    for(int i = n; i < n + m; i++){
        arr[i] = ((rand() % 101) + 100) / 100.;
    }

    int p;
    printf("p: ");
    scanf("%d", &p);

    arr = realloc(arr, sizeof(double) * (n + m + p));
    if(arr == NULL){
        perror("Unable to allocate memory");
        exit(-1);
    }

    for(int i = n + m; i < n + m + p; i++){
        arr[i] = ((rand() % 101) + 200) / 100.;
    }

    for(int i = 0; i < n + m + p; i++){
        printf("%.2lf ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}