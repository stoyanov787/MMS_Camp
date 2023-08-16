#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_str(const void *a, const void *b){
    return strcmp((char*)a, (char*)b);
}

int main(int argc, char* argv[]){
    if(!(argc > 1)){
        perror("Not enough arguments");
        exit(-1);
    }
    qsort(++argv, argc - 1, sizeof(argv[1]), cmp_str);

    char file_name[100];
    printf("Enter file name: ");
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "r");
    if(file != NULL){
        fclose(file);
        perror("File already exists");
        exit(-1);
    }
    file = fopen(file_name, "w");

    for(int i = 0; i < argc - 1; i++){
        fprintf(file, "%s\n", argv[i]);
    }
    fclose(file);

    return 0;
}