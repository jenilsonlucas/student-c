#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

int inicializarLista(Lista **lista, int dim)
{
    *lista = malloc(sizeof(Lista));
    if (*lista == NULL)
        return 0;

    (*lista)->nElementos = 0;
    (*lista)->maxEle = dim;

    (*lista)->item = malloc(dim * sizeof(Item));

    if ((*lista)->item == NULL)
    {
        free(*lista);
        return 0;
    }

    return 1;
}

int realoc(Lista *lista)
{
    Item *novo = (Item *)realloc(lista->item, lista->maxEle * sizeof(Item));
    if (novo == NULL)
        return 0;

    lista->item = novo;

    return 1;
}

int listaCheia(Lista *lista)
{
    if (lista->nElementos == lista->maxEle)
        return 1;

    return 0;
}

int listaVazia(Lista *lista)
{
    if (lista->nElementos == 0)
        return 1;

    return 0;
}

int inserirElemento(Lista *lista, int pos, Item *item)
{
    if (listaCheia(lista))
    {
        lista->maxEle++;
        if (!realoc(lista))
        {
            printf("Erro ao realocar memória!\n");
            return 0; // ou tratar o erro de forma segura
        }
    }

    if (pos < 0 || pos > lista->nElementos)
        return 0;

    for (int i = lista->nElementos - 1; i >= pos; i--)
    {
        lista->item[i + 1] = lista->item[i];
    }
    lista->item[pos] = *item;
    lista->nElementos++;

    return 1;
}

int removerElemento(Lista *lista, int pos)
{
    if (listaVazia(lista))
        return 0;

    if (pos < 0 || pos > lista->nElementos - 1)
        return 0;

    for (int i = pos; i <= lista->nElementos - 2; i++)
    {
        lista->item[i] = lista->item[i + 1];
    }

    lista->nElementos--;
    lista->maxEle--;

    realoc(lista);
    return 0;
}

void imprimirLista(Lista *lista)
{

    for (int i = 0; i < lista->nElementos; i++)
    {
        printf("{%d: %d}\n", lista->item[i].chave, lista->item[i].valor);
    }
}

void liberar(Lista **lista)
{

    free((*lista)->item);

    free(*lista);
}
