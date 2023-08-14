#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
        *head = new_node;
        return;
    } 

    Node* temp = (*head);
    for(; temp->next != NULL; temp = temp->next);
    
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

    *head = new_node;
}

void pop_front(Node** head){
    Node* temp = (*head);
    *head = (*head)->next;
    free(temp);
}

void delete(Node** head){
    while(*head != NULL){
        Node* temp = (*head);
        *head = (*head)->next;
        free(temp);
    }
    printf("\n");
}