#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define COUNT 10
#define REL_TOL 0.01

typedef struct Book{
    char title[150];
    char author[100];
    unsigned int pages;
    double price; 
}Book;

int cmp_title(const void* a, const void* b){
    return strcmp(((Book*)a)->title, ((Book*)b)->title);
}

int cmp_author(const void* a, const void* b){
    return strcmp(((Book*)a)->author, ((Book*)b)->author);
}

int cmp_pages(const void* a, const void* b){
    return ((Book*)a)->pages - ((Book*)b)->pages;
}

int cmp_price(const void* a, const void* b){
    if((abs(((Book*)a)->price - ((Book*)b)->price)) < REL_TOL){
        return 1;
    }
    else if(((Book*)a)->price < ((Book*)b)->price){
        return -1;
    }else{
        return 1;
    }
}

void print_book(Book books[COUNT]){
    for(int i = 0; i < COUNT; i++){
        printf("%s %s %u %.2lf\n", books[i].title, books[i].author, books[i].pages, books[i].price);
    }
}

int main(void){
    Book books[COUNT];
    srand(time(NULL));
    for(int i = 0; i < COUNT; i++){
        int title_len = (rand() % 10) + 10;
        for(int j = 0; j < title_len; j++){
            if(rand() % 2 == 0){
                books[i].title[j] = (rand() % (('Z' - 'A') + 1)) + 'A';
            }else{
                books[i].title[j] = (rand() % (('z' - 'a') + 1)) + 'a';
            }
        }
        books[i].title[title_len] = '\0';

        int author_len = (rand() % 10) + 10;
        for(int j = 0; j < author_len; j++){
            if(rand() % 2 == 0){
                books[i].author[j] = (rand() % (('Z' - 'A') + 1)) + 'A';
            }else{
                books[i].author[j] = (rand() % (('z' - 'a') + 1)) + 'a';
            }
        }
        books[i].author[author_len] = '\0';

        books[i].pages = (rand() % ((2000 - 5) + 1)) + 5;

        books[i].price = ((rand() % ((1000 - 1) + 1)) + 1) * 1.00;
    }

    qsort(books, COUNT, sizeof(Book), cmp_title);
    print_book(books);

    return 0;
}