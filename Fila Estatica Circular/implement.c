#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void create_queue(Queue* queue) {
    queue->begin = 0;
    queue->end = 0;
    queue->size = 0;
}

int queue_is_empty(Queue *queue){
    return queue->size == 0;
}

int queue_is_full(Queue *queue){
    return queue->size == N;
}

int queue_size(Queue *queue){
    return queue->size;
}

void insert_item(Queue *queue, int item){
    if (queue_is_full(queue)) {
        return;
    }
    queue->data[queue->end] = item;
    queue->end = (queue->end + 1) % N;
    queue->size++;
    printf("\nValor %d adicionado.\n", item);
}

int remove_item(Queue *queue){
    if (queue_is_empty(queue)) {
        return -1;
    }
    int removed_item = queue->data[queue->begin];
    queue->begin = (queue->begin + 1) % N;
    queue->size--;
    return removed_item;
}

int consult_first(Queue *queue){
    if (queue_is_empty(queue)) {
        return -1;
    }
    return queue->data[queue->begin];
}

void print_queue(Queue *queue){
    if (queue_is_empty(queue)) {
        printf("\nFila: [ ] (vazia)\n");
        return;
    }
    
    printf("\n--- ESTADO ATUAL DA FILA ---\n");
    printf("Indices: Inicio=%d | Fim=%d | Quantidade=%d\n", queue->begin, queue->end, queue->size);
    printf("Fila: [ ");
    
    int current_ind = queue->begin;
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->data[current_ind]);
        current_ind = (current_ind + 1) % N;
    }
    printf("]\n---------------------------\n");
}
