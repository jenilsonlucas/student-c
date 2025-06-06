#include <stdio.h>
#include <stdlib.h>
#include "interface.h"


void preencher(Item item[], Lista *lista){
    for(int i = 0; i < 5; i++){
          inserirElemento(lista, i, &item[i]);
    }
}



int main(){
    Lista *lista;
    Item items[12] = {{1,2}, {2,2}, {3,12}, {4,12}, {5,123}};

    if(!inicializarLista(&lista, 3)) printf("Erro\n");
    preencher(items, lista);

    imprimirLista(lista);

     liberar(&lista);
    return 0;

}