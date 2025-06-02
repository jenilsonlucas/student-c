#include <stdio.h>
#include "./matriz/interface.h"
#include <time.h>

typedef struct matriz
{
    int linha;
    int coluna;
    int dados[MAX][MAX];
} Matriz;

Boolean criarMatriz(Matriz *m, int linha, int coluna)
{

    if (linha > MAX || coluna > MAX)
        return False;

    m->linha = linha;
    m->coluna = coluna;

    return True;
}

void preencerMatriz(Matriz *m)
{
    srand(time(NULL));
    for (int i = 0; i < m->linha; i++)
    {
        for (int j = 0; j < m->coluna; j++)
        {
            m->dados[i][j] = (rand() % 100) + 1;
        }
    }
}

int acederMatriz(Matriz *m, int linha, int coluna)
{
    if (linha > m->linha || coluna > m->coluna)
        return 0;

    return m->dados[linha][coluna];
}

Boolean atribuir(Matriz *m, int linha, int coluna, int valor)
{
    if (linha > m->linha || coluna > m->coluna)
        return False;

    m->dados[linha][coluna] =  valor;

    return True;   
}

Matriz *somar(Matriz *m1, Matriz *m2){
    if(m1->linha != m2->linha || m1->coluna != m2->coluna) return NULL;

    Matriz *resultado;
    criarMatriz(resultado, m1->linha, m2->linha);

    for(int i = 0; i < m1->linha; i++){
        for(int j = 0; i < m1->coluna; j++){
            resultado->dados[i][j] = m1->dados[i][j] + m2->dados[i][j]; 
        }
    }

    return resultado;
}

Matriz *subtrair(Matriz *m1, Matriz *m2){
    if(m1->linha != m2->linha || m1->coluna != m2->coluna) return NULL;

    Matriz *resultado;
    criarMatriz(resultado, m1->linha, m2->linha);

    for(int i = 0; i < m1->linha; i++){
        for(int j = 0; i < m1->coluna; j++){
            resultado->dados[i][j] = m1->dados[i][j] - m2->dados[i][j]; 
        }
    }

    return resultado;
}

Matriz *multiplicar(Matriz *m1, Matriz *m2){

    if(m1->coluna != m2->linha) return NULL;
    Matriz *resultado;
    criarMatriz(resultado, m1->coluna, m2->linha);
    for(int i = 0; i < m1->linha; i++){
        for(int j = 0; j < m1->coluna; j++){
            resultado->dados[i][j] = m1->dados[i][j] * m2->dados[j][i];
        }
    }  

    return resultado;
}

Matriz *transpor(Matriz *m1){
    Matriz *resultado;
    criarMatriz(resultado, m1->coluna, m1->linha);

    for(int i = 0; 0 < m1->linha; i++){
        for(int j = 0; m1->coluna; j++){
            resultado->dados[j][i] = m1->dados[i][j];
        }
    }

    return resultado;
}

void imprimirMatriz(Matriz *m){
    for(int i = 0; i < m->linha; i++){
        for(int j = 0; j < m->coluna; j++){
            printf("%d ", m->dados[i][j]);
        }

        printf("\n");
    }
}
