#ifndef INTERFACE_H
#define INTERFACE_H

typedef struct Tracional Tracional;

typedef enum {FALSE = 0, TRUE = 1} Boolean;

Boolean criarRacional (int num, int den, Tracional *r);

void somarRacional(Tracional *r1, Tracional *r2, Tracional *r3);

void imprimirRacional(Tracional *r);



#endif