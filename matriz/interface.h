#define MAX 100

typedef struct matriz Matriz;
typedef enum { False = 0, True = 1} Boolean;
//criação de uma matriz
Boolean criarMatriz(Matriz *m, int linha, int coluna);

//preencher a Tmatriz com valores
void preencerMatriz(Matriz  *m);

//aceder um elemento da Matriz
int acederMatriz(Matriz *m, int linha, int coluna);

//atribuir um valor a uma posição
Boolean atribuir(Matriz *m, int linha, int coluna, int valor);

//somar duas Matrizes
Matriz *somar(Matriz *m1, Matriz *m2);

//subtrair duas Matrizes
Matriz *subtrair(Matriz *m1, Matriz *m2);

//multiplicar duas Matrizes
Matriz *multiplicar(Matriz *m1, Matriz *m2);

//transpor uma Matriz
Matriz *transpor(Matriz *m1);

//imprimir a matriz
void imprimirMatriz(Matriz *m);

