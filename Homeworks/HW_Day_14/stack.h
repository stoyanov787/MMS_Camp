#ifndef CHECK
#define CHECK 1

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void print_list(Node *head);
void push_back(Node** head, int data);
void pop_back(Node* head);
void push_front(Node** head, int data);
void pop_front(Node** head);
void delete(Node** head);

#endif