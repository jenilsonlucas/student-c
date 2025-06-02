#include <stdio.h>
#include "interface.h"

typedef struct Tracional
{
    float x; 
    float y;
}Tracional;


Boolean criarRacional(int num, int den, Tracional *r){
    if(den == 0) return FALSE;

    r->x = num;
    r->y = den;

    return TRUE;
}

void somarRacional(Tracional *r1, Tracional *r2, Tracional *r3){
    r3->x = (r1->x * r2->y) + (r2->x * r2->y);
    r3->y = r1->y * r2->y;
}

void imprimirRacional(Tracional *r){
    printf("\n Racional criado: %.2f %.2f\n", r->x, r->y);
}


