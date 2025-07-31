#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void initialize_list(SinglyLinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int is_empty(SinglyLinkedList *list) {
    return list->head == NULL;
}

void insert_at_begin(SinglyLinkedList *list, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    new_node->item = value;
    new_node->next = list->head; 
    list->head = new_node;     
    
    if (list->tail == NULL) {
        list->tail = new_node;
    }
    list->size++;
}

void insert_at_end(SinglyLinkedList *list, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    new_node->item = value;
    new_node->next = NULL;
    
    if (is_empty(list)) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

void print_list(SinglyLinkedList *list) {
    if (is_empty(list)) {
        printf("\nLista: [ ] (vazia)\n");
        return;
    }
    
    printf("\n--- LISTA ENCADEADA SIMPLES (Tamanho: %d) ---\n", list->size);
    Node* current = list->head;
    
    printf("Lista: [ ");
    while (current != NULL) {
        printf("%d ", current->item);
        current = current->next;
    }
    printf("]\n------------------------------------------\n");
}

int remove_item(SinglyLinkedList *list, int value) {
    Node* current = list->head;
    Node* previous = NULL;
    
    while (current != NULL && current->item != value) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        return 0;
    }
    
    if (previous == NULL) {
        list->head = current->next;
    } 
    else {
        previous->next = current->next;
    }
    
    if (current == list->tail) {
        list->tail = previous;
    }
    
    free(current);
    list->size--;
    return 1;
}

void destroy_list(SinglyLinkedList *list) {
    Node* current = list->head;
    Node* next_node;
    
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    
    initialize_list(list);
}