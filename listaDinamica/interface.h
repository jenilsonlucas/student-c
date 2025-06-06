

typedef struct Item
{
    int chave;
    int valor;
}Item;


typedef struct Lista
{
    Item *item;
    int nElementos;
    int maxEle;
}Lista;



int inicializarLista(Lista **lista, int dim);
//alocar memoria para a lista

int realoc(Lista *lista);
//aumentar a memoria da lista 

int listaCheia(Lista *lista);
//verificar se lista esta cheia

int listaVazia(Lista *lista);
//verificar se lista esta vazia

int inserirElemento(Lista *lista, int pos, Item *item);
//inserir elementos na lista

int removerElemento(Lista *lista, int pos);
//remover elementos na lista

void imprimirLista(Lista *lista);
//imprimir elementos da lista

void liberar(Lista **lista);
//liberar memoria da lista