#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

void print_menu();
void verify_option(int option);
void press_enter_to_continue();

Queue* queue = NULL;

int main(){
    queue = initialize_queue();
    int option;
    
    do{
        print_menu();
        
        printf("Escolha uma opcao: ");
        scanf("%d", &option);
        
        verify_option(option);
    } while(option != 6);
    
    return 0;
}

void print_menu() {
    printf("\n_____________MENU_____________\n");
    printf("[1] Criar Nova Mensagem\n");
    printf("[2] Consultar Mensagens\n");
    printf("[3] Consultar e Remover a Primeira Mensagem\n");
    printf("[4] Consultar Mensagens Por Remetente\n");
    printf("[5] Consultar Quantidade de Mensagens\n");
    printf("[6] Sair\n");
    printf("______________________________\n");
}

void verify_option(int option) {
    switch(option) {
        case 1: {
            Message new_mg;

            printf("Informe o remetente: ");
            getchar();
            fgets(new_mg.sender_name, sizeof(new_mg.sender_name), stdin);
            new_mg.sender_name[strcspn(new_mg.sender_name, "\n")] = 0;

            printf("Informe o conteudo da mensagem: ");
            fgets(new_mg.content, sizeof(new_mg.content), stdin);
            new_mg.content[strcspn(new_mg.content, "\n")] = 0;

            send_message(queue, new_mg);
            press_enter_to_continue();
            break;
        }
        case 2: {
            view_messages(queue);
            press_enter_to_continue();
            break;
        }
        case 3: {
            consult_and_remove_first_message(queue);
            press_enter_to_continue();
            break;
        }
        case 4: {
            char sender_name[100];
            printf("Informe o remetente: ");
            getchar();
            fgets(sender_name, sizeof(sender_name), stdin);
            sender_name[strcspn(sender_name, "\n")] = 0;

            search_messages_by_sender(queue, sender_name);
            press_enter_to_continue();
            break;
        }
        case 5: {
            printf("Total de mensagens: %d\n", count_total_messages(queue));
            press_enter_to_continue();
            break;
        }
        case 6: {
            exit_and_free_memory(queue);
            printf("Saindo do programa...\n");
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