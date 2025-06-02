#include <stdio.h>
#include <stdlib.h>
#include "interface.h"


int lerNumero(){
    float n;

    printf("Digite o numerador: ");
    scanf("%f", &n);

    return n;
}


int main(){
    int num, den;
    num = lerNumero();
    den = lerNumero();

    Tracional *r1;

    if(criarRacional(num, den, r1)){
        imprimirRacional(r1);
    }

    return 0;
}