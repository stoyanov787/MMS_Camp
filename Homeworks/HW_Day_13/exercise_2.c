#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define COUNT 10
#define REL_TOL 0.01

typedef struct Book{
    char title[150];
    char author[100];
    unsigned int pages;
    double price; 
}Book;

typedef struct Node{
    Book data;
    struct Node* next;
}Node;

int cmp_title(const void* a, const void* b){
    return strcmp(((Node*)a)->data.title, ((Node*)b)->data.title);
}

void push_front(Node** head, Book data){
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node *head){
    while(head != NULL){
        printf("%s %s %u %.2lf\n", head->data.title, head->data.author, head->data.pages, head->data.price);
        head = head->next;
    }
}

void sort(Node *head){
    Node* temp = head;
    for(int i = 0; i < COUNT; i++){
        for(int j = 0; j < COUNT; j++){
            if(head->next != NULL){
                if(cmp_title(head, head->next) > 0){
                    Book temp = head->data;
                    head->data = head->next->data;
                    head->next->data = temp;
                }
            }
            head = head->next;
        }
        head = temp;
    }
}

int main(void){
    Node *head = NULL;
    Book book;
    srand(time(NULL));
    for(int i = 0; i < COUNT; i++){
        int title_len = (rand() % 10) + 10;
        for(int j = 0; j < title_len; j++){
            if(rand() % 2 == 0){
                book.title[j] = (rand() % (('Z' - 'A') + 1)) + 'A';
            }else{
                book.title[j] = (rand() % (('z' - 'a') + 1)) + 'a';
            }
        }
        book.title[title_len] = '\0';

        int author_len = (rand() % 10) + 10;
        for(int j = 0; j < author_len; j++){
            if(rand() % 2 == 0){
                book.author[j] = (rand() % (('Z' - 'A') + 1)) + 'A';
            }else{
                book.author[j] = (rand() % (('z' - 'a') + 1)) + 'a';
            }
        }
        book.author[author_len] = '\0';

        book.pages = (rand() % ((2000 - 5) + 1)) + 5;

        book.price = ((rand() % ((1000 - 1) + 1)) + 1) * 1.00;

        push_front(&head, book);
    }

    Node *temp = head;
    sort(head);
    print_list(head);

    return 0;
}