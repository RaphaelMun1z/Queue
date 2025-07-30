#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void initialize_queue(Queue *queue) {
    for(int ii = 0; ii < N; ii++) {
        queue->data[ii] = 0;
    }
    queue->end = 0;
}

int queue_is_empty(Queue *queue) {
    return queue->end == 0;
}

int queue_is_full(Queue *queue) {
    return queue->end == N;
}

int insert_item(Queue *queue, int item) {
    if(queue_is_full(queue)) {
        printf("Fila está cheia.\n");
        return 0;
    }

    queue->data[queue->end] = item;
    queue->end++;
    return 1;
}

int remove_item(Queue *queue) {
    if(queue_is_empty(queue)) {
        printf("Fila está vazia.\n");
        return 0;
    }

    int removed_data = queue->data[0];
    for(int ii = 0; ii < queue->end - 1; ii++) {
        queue->data[ii] = queue->data[ii + 1];
    }

    queue->end--;
    return removed_data;
}

void print_queue(Queue *queue) {
    if(queue_is_empty(queue)) {
        printf("Fila está vazia.\n");
        return;
    }

    printf("\nFila: \n");
    for(int ii = 0; ii < queue->end; ii++) {
        printf("[%d°]: %d\n", ii+1, queue->data[ii]);
    }
    printf("\n");
}

void select_item(Queue *queue, int position) {
    if(queue_is_empty(queue)) {
        printf("Fila está vazia.\n");
        return;
    }

    for(int ii = 0; ii < queue->end; ii++) {
        if(position == ii) {
            int item = queue->data[ii];
            printf("Item %d encontrado na posição %d.\n", item, position);
            return;
        }
    }
    printf("Posição %d não foi encontrada na fila.\n", position);
}

int get_queue_size(Queue *queue){
    return queue->end;
}