#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void initialize_list(CircularList *list) {
    list->tail = NULL;
    list->size = 0;
}

int is_empty(CircularList *list) {
    return list->tail == NULL;
}

void insert_at_begin(CircularList *list, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    new_node->item = value;
    
    if (is_empty(list)) {
        list->tail = new_node;
        new_node->next = new_node;
    } else {
        new_node->next = list->tail->next;
        list->tail->next = new_node;
    }
    list->size++;
}

void insert_at_end(CircularList *list, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    new_node->item = value;
    
    if (is_empty(list)) {
        new_node->next = new_node;
        list->tail = new_node;
    } else {
        new_node->next = list->tail->next;
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

void print_list(CircularList *list) {
    if (is_empty(list)) {
        printf("\nLista: [ ] (vazia)\n");
        return;
    }
    
    printf("\n--- LISTA CIRCULAR (Tamanho: %d) ---\n", list->size);
    Node* current = list->tail->next;
    
    printf("Lista: [ ");
    do {
        printf("%d ", current->item);
        current = current->next;
    } while (current != list->tail->next);
    
    printf("]\n");
    printf("(O ultimo no (%d) aponta de volta para o primeiro (%d))\n", list->tail->item, list->tail->next->item);
    printf("----------------------------------\n");
}

int remove_item(CircularList *list, int value) {
    if (is_empty(list)) return 0;
    
    Node* current = list->tail->next;
    Node* previous = list->tail;
    
    for (int ii = 0; ii < list->size; ii++) {
        if (current->item == value) {
            if (list->size == 1) {
                initialize_list(list);
            } else if (current == list->tail->next) {
                previous->next = current->next;
            } else if (current == list->tail) {
                previous->next = current->next;
                list->tail = previous;
            } else {
                previous->next = current->next;
            }
            
            free(current);
            list->size--;
            return 1;
        }
        previous = current;
        current = current->next;
    }
    
    return 0;
}

void destroy_list(CircularList *list) {
    if (is_empty(list)) return;
    
    Node* current = list->tail->next;
    Node* next_node;
    
    list->tail->next = NULL; 
    
    while(current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    
    initialize_list(list);
}