#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

void print_menu();
void verify_option(int option);
void press_enter_to_continue();

Queue queue;

int main() {
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
    printf("[1] Inserir Item\n");
    printf("[2] Remover Item\n");
    printf("[3] Consultar Inicio da Fila\n");
    printf("[4] Consultar Tamanho\n");
    printf("[5] Verificar se esta cheia\n");
    printf("[6] Verificar se esta vazia\n");
    printf("[7] Imprimir Fila\n");
    printf("______________________________\n");
}

void verify_option(int option) {
    int valor;
    switch(option) {
        case 0: {
            printf("Saindo do programa...\n");
            break;
        }
        case 1: {
            if (queue_is_full(&queue)) {
                printf("ERRO: A fila esta cheia!\n");
            } else {
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);
                insert_item(&queue, valor);
                printf("Item %d inserido.\n", valor);
            }
            press_enter_to_continue();
            break;
        }
        case 2: {
            if (queue_is_empty(&queue)) {
                printf("AVISO: A fila ja esta vazia.\n");
            } else {
                valor = remove_item(&queue);
                printf("Item removido: %d\n", valor);
            }
            press_enter_to_continue();
            break;
        }
        case 3: {
            if (queue_is_empty(&queue)) {
                printf("AVISO: A fila esta vazia.\n");
            } else {
                valor = consult_first(&queue);
                printf("Primeiro item da fila: %d\n", valor);
            }
            press_enter_to_continue();
            break;
        }
        case 4: {
            printf("Tamanho da fila: %d\n", queue_size(&queue));
            press_enter_to_continue();
            break;
        }
        case 5: {
            if(queue_is_full(&queue)) {
                printf("A fila esta cheia.\n");
            } else {
                printf("A fila nao esta cheia.\n");
            }
            press_enter_to_continue();
            break;
        }
        case 6: {
            if(queue_is_empty(&queue)) {
                printf("A fila esta vazia.\n");
            } else {
                printf("A fila nao esta vazia.\n");
            }
            press_enter_to_continue();
            break;
        }
        case 7: {
            print_queue(&queue);
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