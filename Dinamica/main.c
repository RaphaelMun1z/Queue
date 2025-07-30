#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

void print_menu();
void verify_option(int option);
void press_enter_to_continue();

Queue* queue = NULL;

int main(){
    int option;
    
    do{
        print_menu();
        
        printf("Escolha uma opcao: ");
        scanf("%d", &option);
        
        verify_option(option);
    } while(option != 0);
    
    return 0;
}

void print_menu() {
    printf("\n_____________MENU_____________\n");
    printf("[0] Sair\n");
    printf("[1] Criar Lista\n");
    printf("[2] Inserir\n");
    printf("[3] Remover\n");
    printf("[4] Consultar Por Posição\n");
    printf("[5] Consultar Tamanho\n");
    printf("[6] Verifica se está vazia\n");
    printf("[7] Imprimir Lista\n");
    printf("______________________________\n");
}

void verify_option(int option) {
    switch(option) {
        case 0: {
            printf("Saindo do programa...\n");
            press_enter_to_continue();
            break;
        }
        case 1: {
            queue = initialize_queue();
            press_enter_to_continue();
            break;
        }
        case 2: {
            insert_item(queue, 10);
            press_enter_to_continue();
            break;
        }
        case 3: {
            int removed_item = remove_item(queue);
            if(removed_item != 0) {
                printf("Item removido: %d\n", removed_item);
            } else {
                printf("Não foi possível remover.\n");
            }
            press_enter_to_continue();
            break;
        }
        case 4: {
            select_item(queue, 0);
            press_enter_to_continue();
            break;
        }
        case 5: {
            int tam = get_queue_size(queue);
            if(tam != -1) {
                printf("Tamanho da fila: %d\n", get_queue_size(queue));
            }
            
            press_enter_to_continue();
            break;
        }
        case 6: {
            int res = queue_is_empty(queue);
            if(res == 1) {
                printf("A fila está vazia.\n");
            } else if(res == 0) {
                printf("A fila não está vazia.\n");
            }
            press_enter_to_continue();
            break;
        }
        case 7: {
            print_queue(queue);
            press_enter_to_continue();
            break;
        }
        default: {
            printf("Opcao invalida! Tente novamente.\n");
            press_enter_to_continue();
            break;
        }
    }
}

void press_enter_to_continue() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}