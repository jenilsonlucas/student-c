#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char titulo[100];
    char autor[100];
    int data;

} livro;

void preencherLivro(livro *l)
{
    printf("Digite o titulo do livro:\n");
    fgets(l->titulo, 100, stdin);

    printf("Digite o autor do livro:\n");
    fgets(l->titulo, 100, stdin);

    printf("Digite a data de publicação do livro:\n");
    scanf("%d", l->data);
}

int main()
{

    livro *l;

    preencherLivro(l);

    printf("titulo = %s\n", l->titulo);
    printf("autor = %s\n", l->autor);
    printf("data = %d\n", l->data);
    return 0;
}