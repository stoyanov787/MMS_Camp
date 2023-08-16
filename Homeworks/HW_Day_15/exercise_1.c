#include <stdio.h>
#include <stdlib.h>

void print_file(char* file_name){
    size_t str_len = 100;
    char *str = malloc(sizeof(char) * str_len);

    FILE* file = fopen(file_name, "r");
    while(getline(&str, &str_len, file) != -1){
        printf("%s", str);
    }
    free(str);
    fclose(file);
}

void cat(int argc, char* argv[]){
    if(argc == 1){
        size_t str_len = 100;
        char *str = malloc(sizeof(char) * str_len);

        while(getline(&str, &str_len, stdin) != -1){
            printf("%s", str);
        }
        free(str);
        
    }else if(argc == 2){
        print_file(argv[1]);
    }else{
        for(int i = 1; i < argc; i++){
            print_file(argv[i]);
        }
    }
}

int main(int argc, char* argv[]){
    cat(argc, argv);

    return 0;
}