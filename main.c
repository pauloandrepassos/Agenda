#include "stdio.h"
#include "agenda.h"

void exibir_menu() {
    printf("\nMENU"
           "\n1 - Adicionar contato"
           "\n2 - Remover contato"
           "\n3 - Listar contatos"
           "\n4 - Encerrar");
}

int main() {
    Lista *l;
    l = cria_lista();
    struct contato contact;

    int opcao = 1;
    while(opcao != 4) {
        exibir_menu();
        printf("\nDigite:");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("\nNome (sem espacos):");
            scanf(" %s", contact.nome);
            printf("");

            printf("Numero (xxxxxxxxx):");
            scanf("%d", &contact.numero);
            printf("");

            printf("Email: ");
            scanf(" %s",  contact.email);
            printf("");

            append(l, contact);
        }
        else if (opcao == 2) {
            int numero;
            printf("\nNumero do contato que deseja remover:");
            scanf("%d", &numero);
            printf(" ");

            remover(l, numero);
        }
        else if (opcao == 3) {
            imprime(l);
        }
    }
    /*contact.nome = "Paulo";
    contact.numero = 25;
    contact.email = "abc";

    append(l, contact);
    remover(l, 26);
    imprime(l);*/
    return 1;
}
