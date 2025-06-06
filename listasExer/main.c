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

    Item x = {2,4};
    Item y = {12, 24};
    if (inicializarLista(&lista, 3))
        printf("Lista inicializa\n");
    preencher(items, lista);

    if(removerNelementos(lista, 0, 3)){
        imprimir(lista);
    }

    liberar(&lista);
    return 0;
}