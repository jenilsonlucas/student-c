
typedef struct Item{
    int chave;
    int valor;
}Item;

typedef struct Lista{
    Item *items;
    int nElem;
    int maxElem;
}Lista;

int inicializarLista(Lista **lista, int dim);

int realoc(Lista *lista);

int vazia(Lista *lista);

int cheia(Lista *lista);

int inserirElemento(Lista *lista, int pos, Item *item);

int somaRecursiva(Lista *lista);

Lista *inversaInterativa(Lista *lista);

Lista *inversaRecursiva(Lista *lista, int inicio, int fim);

int findForKey(Lista *lista, Item *x, Item *y);

void imprimir(Lista *lista);

void liberar(Lista **lista);