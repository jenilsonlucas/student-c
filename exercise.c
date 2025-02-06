#include <stdlib.h>
#include <stdio.h>

void seqAlternante(int n)
{
    int numeroActual, segmento1, segmento2, altern1, altern2;
    for(int i = 0; i < n; i++){
        scanf("%d", &numeroActual);

        if((numeroActual % 2) == 0){
            ++segmento1;
            segmento2 = 0;
            if(segmento1 > 1){
                altern1++;
            }
        }else{
            ++segmento2;
            segmento1 = 0;
            if(segmento2 > 1){
                altern2++;
            }
        }

    }

     if(altern1 <= 1 && altern2 <= 1 && n > 4){
        printf("Essa n e uma sequencia alternada");
        return;
    }

    if((altern1 >= 1 && altern2 == 0) || (altern2 >= 1 && altern1 == 0) || (altern1 >= 1 && altern2 >= 1)){
        printf("Essa e uma sequencia alternada\n");
        return;
    }

    
}

int main()
{

    seqAlternante(9);
    return 0;
}