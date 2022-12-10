struct contato{
    char nome[30];
    char email[30];
    int numero;
};

typedef struct lista Lista;

Lista* cria_lista();
void libera_lista(Lista* l);

int lista_cheia(Lista *l);
int lista_vazia(Lista *l);

int append(Lista *l, struct contato contact);
int remover(Lista *l, int numero);

int imprime(Lista *l);