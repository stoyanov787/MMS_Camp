typedef struct Queue{
    int* head;
    int* tail;
    size_t index_head;
    size_t index_tail;
    size_t size;
    size_t capacity;
}Queue;

Queue* init(size_t max_capacity);
int push(Queue* queue, int element);
int pop(Queue* queue);
void print_queue(Queue queue);
