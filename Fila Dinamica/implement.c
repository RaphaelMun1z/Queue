#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

Queue* initialize_queue() {
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));
    if(new_queue == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        return NULL;
    }
    
    new_queue->begin = NULL;
    new_queue->end = NULL;
    
    return new_queue;
}

int queue_exists(Queue *queue) {
    return queue != NULL;
}

int queue_is_empty(Queue *queue) {
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada.\n");
        return -1;
    }
    return queue->begin == NULL;
}

int insert_item(Queue *queue, int item) {
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada, não é possível inserir.\n");
        return 0;
    }
    
    No* novo_no = (No*) malloc(sizeof(No));
    if(novo_no == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        return 0;
    }
    
    novo_no->item = item;
    novo_no->next = NULL;
    
    if(queue->begin == NULL){
        queue->begin = novo_no;
    }else{
        queue->end->next = novo_no;
    }
    queue->end = novo_no;
}

int remove_item(Queue *queue) {
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada, não é possível remover.\n");
        return 0;
    }
    
    No* begin_no = queue->begin;
    if(queue_is_empty(queue)) {
        printf("A fila está vazia, não é possível remover.\n");
        return 0;
    }
    
    queue->begin = begin_no->next;
    begin_no->next = NULL;
    int item = begin_no->item;
    free(begin_no);
    
    if(queue->begin == NULL)
    queue->end = NULL;
    
    return item;
}

void select_item(Queue *queue, int position) {
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada, não é possível consultar.\n");
        return;
    }
    
    if(queue_is_empty(queue)) {
        printf("A fila está vazia, não é possível consultar.\n");
        return;
    }
    
    No* current = queue->begin;
    int currentPosition = 0;
    while(current != NULL) {
        if(currentPosition == position) {
            printf("Item encontrado: %d\n", current->item);
            return;
        }
        current = current->next;
    }
    
    printf("Posição não encontrada na fila.\n");
}

int get_queue_size(Queue *queue){
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada, não é possível obter o tamanho.\n");
        return -1;
    }
    
    if(queue_is_empty(queue)) {
        return 0;
    }
    
    int size = 0;
    No* current = queue->begin;
    while(current != NULL) {
        size++;
        current = current->next;
    }
    
    return size;
}

void print_queue(Queue *queue) {
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada, não é possível imprimir.\n");
        return;
    }
    
    if(queue_is_empty(queue)) {
        printf("A fila está vazia, não é possível imprimir.\n");
        return;
    }
    
    No* current = queue->begin;
    printf("\nFila: \n");
    while(current != NULL) {
        printf("%d\n", current->item);
        current = current->next;
    }
}