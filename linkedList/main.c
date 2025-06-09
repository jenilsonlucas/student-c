#include <stdio.h>
#include <stdlib.h>
#include "interface.h"




int main(){

    Lista *lista;

    Info *info;
    info->chave = 12;
    info->valor = 13;
    // Info info2 = {12, 14};
    // Info info3 = {12, 14};
    inicilializarLista(lista);

    inserirNoFim(lista, *info);
    inserirNoFim(lista, *info);
    inserirNoFim(lista, *info);

    
    imprimirLista(lista);
    printf("\n Tamanho da lista :%d \n", tamanhodaLista(lista));

    
    return 0;
}