#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void print_menu();

int main(){
    SinglyLinkedList myList;
    initialize_list(&myList);
    int option, value;
    
    do {
        print_menu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
            printf("Digite o valor para inserir no INICIO: ");
            scanf("%d", &value);
            insert_at_begin(&myList, value);
            break;
            case 2:
            printf("Digite o valor para inserir no FIM: ");
            scanf("%d", &value);
            insert_at_end(&myList, value);
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
            break;
            case 4:
            print_list(&myList);
            break;
            case 5:
            destroy_list(&myList);
            printf("\nLista destruida! Todos os nos foram liberados.\n");
            break;
            case 0:
            printf("\nSaindo do programa...\n");
            destroy_list(&myList); // Garante que a memória seja liberada ao sair
            break;
            default:
            printf("\nOpcao invalida! Tente novamente.\n");
        }
        
    } while (option != 0);
    
    return 0;
}

void print_menu() {
    printf("\n--- Menu Lista Encadeada Simples ---\n");
    printf("1. Inserir no Inicio\n");
    printf("2. Inserir no Fim\n");
    printf("3. Remover por valor\n");
    printf("4. Imprimir Lista\n");
    printf("5. Destruir Lista\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}