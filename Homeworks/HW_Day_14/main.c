#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void enstack(Node** head, int data){
    push_front(head, data);
}

void destack(Node** head){
    pop_front(head);
}

int main(void){
    Node *head = NULL;
    
    enstack(&head, 6);
    print_list(head);
    enstack(&head, 7);
    print_list(head);
    enstack(&head, 230);
    
    print_list(head);
    destack(&head);
    print_list(head);
    destack(&head);
    print_list(head);
    delete(&head);
    print_list(head);

    return 0;
}
