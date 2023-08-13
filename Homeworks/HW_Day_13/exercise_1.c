#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

void print_list(Node *head){
    while(head != NULL){

        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void push_back(Node** head, int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL){
        new_node->prev = NULL;
        *head = new_node;
        return;
    } 

    Node* temp = (*head);
    for(; temp->next != NULL; temp = temp->next);
    
    new_node->prev = temp;
    temp->next = new_node;
}

void pop_back(Node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    if(head->next == NULL){
        head = NULL;
    }

    for(; head->next->next != NULL; head = head->next);
    
    free(head->next);
    head->next = NULL;
}

void push_front(Node** head, int data){
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;

    (*head)->prev = new_node;
    *head = new_node;
}

void pop_front(Node** head){
    Node* temp = (*head);
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}

void delete(Node** head){
    while(*head != NULL){
        Node* temp = (*head);
        *head = (*head)->next;
        free(temp);
        temp = NULL;
    }
    printf("\n");
}

int main(void){
    Node *a = NULL;
    
    push_back(&a, 1);
    print_list(a);
    push_back(&a, 13);
    print_list(a);
    push_back(&a, 115);
    print_list(a);
    
    pop_front(&a);
    print_list(a);
    pop_front(&a);
    print_list(a);
    delete(&a);
    print_list(a);

    return 0;
}