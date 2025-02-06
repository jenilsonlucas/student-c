#include <stdio.h>
#include <stdlib.h>


void sequencia()
{
    int anterior, atual, proximo;

    printf("digite uma sequecia de numeros inteiros (para sair digite um valor negativo)");

    scanf("%d", &anterior);
    if(anterior < 0) return;

    scanf("%d", &atual);
    if(atual < 0) return;

    while(1){

        scanf("%d", &proximo);

        if(proximo < 0) return;

        if(atual != 0 && anterior != 0 && proximo != 0)
        if(atual > anterior && atual > proximo){
            printf("segue essa caracterista %d\n", atual);
        }

        anterior = atual;
        atual = proximo;

    }

}


int main()
{
    sequencia();

    return 0;
}
