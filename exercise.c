#include <stdlib.h>
#include <stdio.h>


int tribonacci(int n, int primeiro, int segundo, int terceiro)
{
    if(n == 1) return primeiro;
    if(n == 2) return primeiro + segundo;
    if(n == 3) return primeiro + segundo + terceiro;
    int result ;
    for(int i = 0; i < n; i++){
        result = primeiro + segundo + terceiro;

        primeiro = segundo;
        segundo = terceiro;
        terceiro = result;
    }


    return result;
}



int main()
{

    int tri = tribonacci(7, 1,1,2);

    printf("O valor da sequeencia de tribonacci e %d\n", tri);

    return 0;
}