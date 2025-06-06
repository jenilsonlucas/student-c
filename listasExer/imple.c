#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

typedef struct Lista{
    Item *items;
    int nElem;
    int maxElem;
}Lista;

int inicializarLista(Lista **lista, int dim)
{
    *lista = malloc(sizeof(Lista));
    if (*lista == NULL)
        return 0;

    (*lista)->nElem = 0;
    (*lista)->maxElem= dim;

    (*lista)->items = malloc(dim * sizeof(Item));

    if ((*lista)->items == NULL)
    {
        free(*lista);
        return 0;
    }

    return 1;
}

int realoc(Lista *lista){
    lista->items = realloc(lista->items, lista->maxElem * sizeof(Item));

    if(lista->items == NULL) return 0;

    return 1;
}

int vazia(Lista *lista){
    if(lista->nElem == 0) return 1;

    return 0;
}


int cheia(Lista *lista){
    if(lista->nElem == lista->maxElem) return 1;

    return 0;
}

int inserirElemento(Lista *lista, int pos, Item *item){

    if(cheia(lista)){
        lista->maxElem++;
        if(!realoc(lista)){
            return 0;
        }
    }

    if(pos < 0 || pos > lista->nElem) return 0;

    for(int i = lista->nElem - 1; i >= pos; i--){
        lista->items[i + 1] = lista->items[i];
    }

    lista->items[pos] = *item;
    lista->nElem++;

    return 1;
}

int somaRecursiva(Lista *lista){
    if(lista->nElem == 0) return 0;
 
    lista->nElem--;

    return lista->items[lista->nElem].valor + somaRecursiva(lista);
}

Lista *inversaInterativa(Lista *lista){
    if(vazia(lista)){
        return 0;
    }

    if(lista->nElem == 1) return lista;

    for(int i = 0; i < lista->nElem / 2; i++){
        Item item = lista->items[i];
        lista->items[i] = lista->items[lista->nElem - i - 1];
        lista->items[lista->nElem - i - 1] = item;
    }

    return lista;
}



















void imprimir(Lista *lista){
    for(int i = 0; i < lista->nElem; i++){
        printf("{%d : %d}\n", lista->items[i].chave, lista->items[i].valor);
    }
}

void liberar(Lista **lista)
{

    free((*lista)->items);

    free(*lista);
}
