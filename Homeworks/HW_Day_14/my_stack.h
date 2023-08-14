typedef struct Stack{
    int* data;
    size_t size;
    size_t capacity;
}Stack;

Stack* init(size_t max_capacity);
int push(Stack* stack, int element);
int pop(Stack* stack);
void print_stack(Stack* stack);
