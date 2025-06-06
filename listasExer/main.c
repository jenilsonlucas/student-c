#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void preencher(Item items[], Lista *lista)
{
    for (int i = 0; i < 5; i++)
    {
        inserirElemento(lista, i, &items[i]);
    }
}

int main()
{
    Lista *lista;
    Item items[12] = {{1, 2}, {2, 2}, {3, 12}, {4, 4}, {5, 4}};
    if (inicializarLista(&lista, 3))
        printf("Lista inicializa\n");
    preencher(items, lista);

    lista = inversaInterativa(lista);
    imprimir(lista);

    return 0;
}