#define NOT_FOUND - 1
#define OK 1
#define LIST_FULL 2
#define LIST_EMPTY 3
#define INVALID_INDEX 4


#define TAM 100

typedef enum {False = 0, True = 1} Boolean;

typedef struct Item
{
    int chave;
    int valor;
}Item;


typedef struct Lista
{
    Item vLista[TAM];
    int nElemento;
}Lista;

void inicialiarLista(Lista *lista);
//inicializa lista

Boolean vaziaLista(Lista *lista);
//verifica se a lista esta vazia
Boolean listaCheia(Lista * lista);

Item *consultarPos(Lista *lista, int pos);
//dada uma posicão retorna o valor deste elemento;

Item *consultarCha(Lista *lista, int chave);
//dada uma chave retorna o valor deste elemento

int inserirElemento(Lista *lista, int pos, Item *item);
//inserir elemento na lista dada posicão

int removerElemento(Lista *lista, int pos, Item *item);
//remover um elemento na lista dada posição

int ordenarListaCres(Lista *lista);
//ordernar uma lista de maneira crescente

int ordenarListaDecre(Lista *lista);
//ordenar uma lista de maneira decrescente

void imprimirLista(Lista *lista);
//mostrar os elementos da lista