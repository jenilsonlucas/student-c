#include <stdio.h>
#include "interface.h"

void inicialiarLista(Lista *lista)
{
    lista->nElemento = 0;
}

Boolean vaziaLista(Lista *lista)
{
    if (lista->nElemento == 0)
        return True;

    return False;
}

Boolean listaCheia(Lista *lista)
{
    if (lista->nElemento == TAM)
        return True;

    return False;
}

Item *consultarPos(Lista *lista, int pos)
{
    if (pos < 0 || pos > lista->nElemento - 1)
        return NULL;

    return &lista->vLista[pos];
}

Item *consultarCha(Lista *lista, int chave)
{
    for (int i = 0; i < lista->nElemento; i++)
    {
        if (lista->vLista[i].chave == chave)
            return &lista->vLista[i];
    }
    return NULL;
}

int inserirElemento(Lista *lista, int pos, Item *item)
{
    if (listaCheia(lista))
        return LIST_FULL;
    if (pos < 0 || pos > lista->nElemento)
        return INVALID_INDEX;

    for (int i = lista->nElemento - 1; i >= pos; i--)
    {
        lista->vLista[i + 1] = lista->vLista[i];
    }

    lista->vLista[pos] = *item;
    lista->nElemento++;
    return OK;
}

int removerElemento(Lista *lista, int pos, Item *item)
{
    if (vaziaLista(lista))
        return LIST_EMPTY;
    if (pos < 0 || pos > lista->nElemento - 1)
        return INVALID_INDEX;

    *item = lista->vLista[pos];

    for (int i = pos; i <= lista->nElemento - 2; i++)
    {
        lista->vLista[i] = lista->vLista[i + 1];
    }
    lista->nElemento--;
    return OK;
}

int ordenarListaCres(Lista *lista)
{

    for (int i = 0; i < lista->nElemento - 1; i++)
    {
        for (int j = 0; j < lista->nElemento - i - 1; j++)
        {
            if (lista->vLista[j].chave > lista->vLista[j + 1].chave)
            {
                Item temp = lista->vLista[j + 1];
                lista->vLista[j + 1] = lista->vLista[j];
                lista->vLista[j] = temp;
            }
        }
    }
}

int ordenarListaDecre(Lista *lista)
{
    for (int i = 0; i < lista->nElemento - 1; i++)
    {
        for (int j = 0; j < lista->nElemento - i - 1; j++)
        {
            if (lista->vLista[j].chave < lista->vLista[j + 1].chave)
            {
                Item temp = lista->vLista[j + 1];
                lista->vLista[j + 1] = lista->vLista[j];
                lista->vLista[j] = temp;
            }
        }
    }
}

void imprimirLista(Lista *lista)
{
    if (vaziaLista(lista))
        LIST_EMPTY;

    for (int i = 0; i < lista->nElemento; i++)
    {
        printf("{%d : %d }\n", lista->vLista[i].chave, lista->vLista[i].valor);
    }
}
