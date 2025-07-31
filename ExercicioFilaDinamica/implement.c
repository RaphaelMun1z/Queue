#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

Queue* initialize_queue(){
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    if(queue == NULL) {
        printf("Erro ao alocar memoria para a fila.\n");
        return NULL;
    }
    
    queue->begin = NULL;
    queue->end = NULL;
    
    return queue;
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

void send_message(Queue* queue, Message msg){
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada.\n");
        return;
    }
    
    No* new_no = (No*) malloc(sizeof(No));
    if(new_no == NULL){
        printf("Erro ao alocar memoria para o Nó.\n");
        return;
    }
    
    new_no->msg = msg;
    new_no->next = NULL;
    
    if(queue->begin == NULL){
        queue->begin = new_no;
    } else {
        queue->end->next = new_no;
    }
    
    queue->end = new_no;
}

void delete_message_by_position(Queue* queue, int target_position) {
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada.\n");
        return;
    }
    
    if(queue_is_empty(queue)) {
        printf("Não há mensagens.\n");
        return;
    }
    
    if(target_position == 0){
        queue->begin = queue->begin->next;
        printf("Mensagem deletada.\n");
        return;
    }
    
    No* prev_no = queue->begin;
    int current_position = 1;
    while(prev_no->next != NULL){
        if(current_position == target_position){
            No* target_no_to_delete = prev_no->next;
            prev_no->next = target_no_to_delete->next;
            printf("Mensagem deletada.\n");
            return;
        }
        current_position++;
        prev_no = prev_no->next;
    }
    
    printf("Mensagem na posição especificada não foi encontrada.\n");
}

void view_messages(Queue* queue){
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada.\n");
        return;
    }
    
    if(queue_is_empty(queue)) {
        printf("Não há mensagens.\n");
        return;
    }
    
    No* current = queue->begin;
    while(current != NULL){
        printf("\n________________________________\n");
        printf("~ %s\n", current->msg.sender_name);
        printf("\t'%s'\n", current->msg.content);
        current = current->next;
    }
    printf("________________________________\n");
}

void consult_and_remove_first_message(Queue* queue){
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada.\n");
        return;
    }
    
    if(queue_is_empty(queue)) {
        printf("Não há mensagens.\n");
        return;
    }
    
    Message first_msg = queue->begin->msg;
    printf("\n________________________________\n");
    printf("~ %s\n", first_msg.sender_name);
    printf("\t'%s'\n", first_msg.content);
    printf("________________________________\n");
    
    delete_message_by_position(queue, 0);
}

void search_messages_by_sender(Queue* queue, char sender_name[100]){
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada.\n");
        return;
    }
    
    if(queue_is_empty(queue)) {
        printf("Não há mensagens.\n");
        return;
    }
    
    int found = 0;
    No* current = queue->begin;
    while(current != NULL){
        if(strcmp(current->msg.sender_name, sender_name) == 0){
            printf("\n________________________________\n");
            printf("~ %s\n", current->msg.sender_name);
            printf("\t'%s'\n", current->msg.content);
            printf("________________________________\n");
            found++;
        }
        current = current->next;
    }
    
    if(found == 0){
        printf("Nenhuma mensagem encontrada do remetente informado.\n");
    } else {
        printf("Total de mensagens encontradas: %d\n", found);
    }
}

int count_total_messages(Queue* queue){
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada.\n");
        return 0;
    }
    
    if(queue_is_empty(queue)) {
        printf("Não há mensagens.\n");
        return 0;
    }
    
    int found = 0;
    No* current = queue->begin;
    while(current != NULL){
        found++;
        current = current->next;
    }
    
    return found;
}

void exit_and_free_memory(Queue* queue){
    if(!queue_exists(queue)) {
        printf("A fila não foi inicializada.\n");
        return;
    }

    No* current = queue->begin;
    while(current != NULL){
        No* no_to_delete = current;
        current = current->next;
        free(no_to_delete);
    }
}