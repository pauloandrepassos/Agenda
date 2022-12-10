#include "stdio.h"
#include "stdlib.h"
#include "agenda.h"
#define MAX 100

struct lista{
    int qtd;
    struct contato dados[MAX];
};

Lista* cria_lista() {
    Lista *l;
    l = (Lista*) malloc(sizeof(struct lista));
    if(l == NULL){
        printf("MEMORIA INSUFICIENTE!");
        exit(1);
    }
    if(l != NULL)
        l->qtd = 0;
    return l;
}

void libera_lista(Lista* l) {
    free(l);
}

int lista_cheia(Lista *l) {
    if(l == NULL)
        return -1;
    return (l->qtd == MAX);
}

int lista_vazia(Lista *l) {
    if(l == NULL)
        return -1;
    return (l->qtd == 0);
}

int append(Lista *l, struct contato contact){
    if(l == NULL)
        return 0;
    if(lista_cheia(l)){
        printf("Agenda Cheia!\n");
        return 0;
    }
    l->dados[l->qtd] = contact;
    l->qtd++;
    return 1;
}

int remover(Lista *l, int numero) {
    if(l == NULL)
        return 0;
    if(lista_vazia(l)) {
        printf("Não ha contatos cadastrados!\n");
        return 0;
    }
    int i, j = 0;
    while(j < l->qtd && l->dados[j].numero != numero)
        j++;
    if(j == l->qtd) {
        printf("Contato nao encontrado!\n");
        return 0;
    }
    for (i = j; i < l->qtd - 1; i++) {
        l->dados[i] = l->dados[i + 1];
    }
    l->qtd--;
    return 1;
}


int imprime(Lista *l) {
    if(lista_vazia(l)) {
        printf("Lista vazia!\n");
        return 0;
    }
    int i;
    for(i = 0; i < l->qtd; i ++){
        printf("\n%s - %d - %s\n", l->dados[i].nome, l->dados[i].numero, l->dados[i].email);
    }
    printf("\n");
    return 1;
}