#include <stdio.h>
#include <stdlib.h>
#include "interface.h"


typedef struct Lista
{
    Atomo *primeiro;
}Lista;

void inicilializarLista(Lista *lista){
    lista->primeiro = NULL;
}

Boolean listaVazia(Lista *lista){
    if(lista->primeiro == NULL) return True;

    return False;
}
    
void imprimirAtomo(Atomo *atomo){
    printf("{%d: %d}\n", atomo->info.chave, atomo->info.valor);
}

void imprimirLista(Lista *lista){
    for(Atomo *prox = lista->primeiro; prox != NULL; prox = prox->prox)
        imprimirAtomo(prox);
}

int tamanhodaLista(Lista *lista){
    int tamanho = 0;
    for(Atomo *prox = lista->primeiro; prox != NULL; prox = prox->prox)
        tamanho++;

        return tamanho;
}

Atomo *buscarAtomo(Lista * lista, int chave){
    for(Atomo *prox = lista->primeiro; prox != NULL; prox = prox->prox)
        if(prox->info.chave == chave) return prox;


    return NULL;
}

int inserirNoFim(Lista *lista, Info info){
    
    Atomo *prox, *pnovo = malloc(sizeof(Atomo));
    
    if(pnovo == NULL) return NO_SPACE;
    pnovo->info = info;
    pnovo->prox = NULL;
    
    if(listaVazia(lista)) 
        lista->primeiro = pnovo;
    else {
        for(prox = lista->primeiro; prox->prox != NULL; prox = prox->prox);
        prox->prox = pnovo;
    }    

    return OK;
}

int removerAtomoChave(Lista *lista, int chave){
    if(listaVazia(lista)) return LIST_EMPTY;

    Atomo *ant = NULL, *del = lista->primeiro;
    
    while(del != NULL && del->info.chave != chave){
        ant = del;
        del = del->prox;
    }

    if(del == NULL) return NOT_FOUND;

    if(del == lista->primeiro)
        lista->primeiro = lista->primeiro->prox;
    else
        ant->prox = del->prox;
        
    free(del);
    return OK;    
}


void liberar(Lista **lista){

  Atomo *atual = (*lista)->primeiro;
    while(atual != NULL){
        Atomo *prox = atual->prox;
        free(atual);
        atual = prox;
    }
}