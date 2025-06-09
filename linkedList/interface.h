typedef struct Info
{
    int chave;
    int valor;
}Info;

typedef struct Atomo
{
    Info info;
    struct Atomo *prox;
}Atomo;

typedef struct Lista Lista;

typedef enum{ False = 0, True = 1}Boolean;

#define NOT_FOUND 0
#define OK 1
#define LIST_EMPTY 2
#define NO_SPACE 3

//inicializar a lista
void inicilializarLista(Lista *lista);

//verificar lista vazia
Boolean listaVazia(Lista *lista);

//imprimir lista
void imprimirLista(Lista *lista);

//tamanho da lista
int tamanhodaLista(Lista *lista);

//buscar um dados atomo
Atomo *buscarAtomo(Lista * lista, int chave);

//inserir um atomo fim
int inserirNoFim(Lista *lista, Info info);

//remover um elemento da lista
int removerAtomoChave(Lista *lista, int chave);

void liberar(Lista **lista);