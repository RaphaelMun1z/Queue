#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

void print_menu();
void verify_option(int option);
void press_enter_to_continue();

CircularList myList;

int main() {
    int option;
    initialize_list(&myList);
    
    do {
        print_menu();
        
        printf("Escolha uma opcao: ");
        scanf("%d", &option);
        
        verify_option(option);
    } while(option != 0);
    
    return 0;
}

void print_menu() {
    printf("\n_____________MENU_____________\n");
    printf("1. Inserir no Inicio\n");
    printf("2. Inserir no Fim\n");
    printf("3. Remover por valor\n");
    printf("4. Imprimir Lista\n");
    printf("5. Destruir Lista\n");
    printf("0. Sair\n");
    printf("______________________________\n");
}

void verify_option(int option) {
    int value;
    switch (option) {
        case 1:
        printf("Digite o valor para inserir no INICIO: ");
        scanf("%d", &value);
        insert_at_begin(&myList, value);
        press_enter_to_continue();
        break;
        case 2:
        printf("Digite o valor para inserir no FIM: ");
        scanf("%d", &value);
        insert_at_end(&myList, value);
        press_enter_to_continue();
        break;
        case 3:
        if (is_empty(&myList)) {
            printf("\nAVISO: A lista esta vazia.\n");
        } else {
            printf("Digite o valor a ser REMOVIDO: ");
            scanf("%d", &value);
            if (remove_item(&myList, value)) {
                printf("\nValor %d removido com sucesso!\n", value);
            } else {
                printf("\nERRO: Valor %d nao encontrado na lista.\n", value);
            }
        }
        press_enter_to_continue();
        break;
        case 4:
        print_list(&myList);
        press_enter_to_continue();
        break;
        case 5:
        destroy_list(&myList);
        printf("\nLista destruida! Todos os nos foram liberados.\n");
        press_enter_to_continue();
        break;
        case 0:
        printf("\nSaindo do programa...\n");
        destroy_list(&myList);
        break;
        default:
        printf("\nOpcao invalida! Tente novamente.\n");
        press_enter_to_continue();
        break;
    }
}

void press_enter_to_continue() {
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n');
    getchar();
}
