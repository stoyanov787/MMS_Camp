#include <stdio.h>
#include <stdlib.h>
#include "my_queue.h"
#define MAX_LEN 10

Queue* init(size_t max_capacity){
    Queue* new_queue = malloc(sizeof(Queue));
    new_queue->size = 0;
    new_queue->capacity = MAX_LEN;
    new_queue->index_head = 0;
    new_queue->index_tail = 0;
    new_queue->head = malloc(sizeof(int) * new_queue->capacity);
    new_queue->tail = malloc(sizeof(int));
    new_queue->tail = new_queue->head;
    return new_queue;
}

int push(Queue* queue, int element){
    if(queue->size + 1 >= queue->capacity){
        printf("Queue is full\n");
        return -1;
    }
    if(queue->head < queue->tail || queue->size == 0){
        queue->head[queue->size++] = element;
        if(queue->size != 1 && queue->index_tail + 1 < queue->capacity){
            queue->tail++;
            queue->index_tail++;
        } 
        else if(queue->size != 1){
            queue->index_tail -= queue->capacity;
            queue->tail -= queue->capacity;
        }
    }else{
        queue->tail[queue->size++] = element;
        queue->index_tail++;
    }
    
    return 0;
}

int pop(Queue* queue){
    if(queue->size == 0){
        printf("The queue is empty\n");
        return -1;
    }

    if(queue->index_head == queue->index_tail){
        queue->head -= queue->index_head;
        queue->tail -= queue->index_tail;
        queue->index_head = queue->index_tail = 0;
    }
    if(queue->index_head + 1 < queue->capacity){
        queue->index_head++;
        queue->head++;
    }else{
        queue->index_head -= queue->capacity;
        queue->head -= queue->capacity;
    }

    queue->size--;
    return 0;
}

void print_queue(Queue queue){
    if(queue.index_head <= queue.index_tail){
        for(int i = 0; i <= queue.index_tail; i++){
            printf("%d ", queue.head[i]);
        }
        printf("\n");
    }else{
        for(int i = queue.index_head; i < queue.capacity; i++){
            printf("%d ", queue.head[i]);
        }
        for(int i = 0; i < queue.index_tail; i++){
            printf("%d ", queue.tail[i]);
        }
        printf("\n");
    }
}
