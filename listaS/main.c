    #include <stdio.h>
    #include <stdlib.h>
    #include "interface.h"

    void preencher(Item items[], Lista *lista){
        for(int i = 0; i < 5; i++){
            inserirElemento(lista, i, &items[i]);
        }
    }

    int main(){
        Lista lista;
        Item items[12] = {{1,2}, {2,2}, {3,12}, {4,12}, {5,123}};

        inicialiarLista(&lista);
        preencher(items, &lista);
        ordenarListaCres(&lista);
        imprimirLista(&lista);
        printf("\n");
        ordenarListaDecre(&lista);
        imprimirLista(&lista);
        return 0;
    }

