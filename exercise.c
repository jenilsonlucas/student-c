#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[255];
    char password[255];
} Alunos;

typedef struct{
    Alunos alunos[5];
    int numerodeAlunos;
}control;


void inicializarLista(control *controlo){
    controlo->numerodeAlunos = 0;
}

int listavazia(control *controlo){
    if(controlo->numerodeAlunos == 0){
        return 1;
    }

    return 0;
}

int listacheia(control *controlo){
    if(controlo->numerodeAlunos >= 5){
        return 1;
    }

    return 0;

}

int tamanhoDaString(char array[])
{
    int i = 0;
    while (array[i] != '\0')
    {
        i++;
    }
    return i;
}

int verificarIgualdade(char string1[], char string2[])
{

    if (tamanhoDaString(string1) != tamanhoDaString(string2))
    {
        return 0;
    }

    for (int i = 0; i < tamanhoDaString(string1); i++)
    {
        if (string1[i] != string2[i])
        {
            return 0;
        }
    }

    return 1;
}

int verificarNome(char inputName[], Alunos alunos[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < tamanhoDaString(inputName); j++)
        {
            if (verificarIgualdade(alunos[i].name, inputName))
            {
                return i;
            }
        }
    }

    return -1;
}

int verificarPasse(char inputPassword[], int id, Alunos alunos[])
{
    if (verificarIgualdade(alunos[id].password, inputPassword))
    {
        return 1;
    }

    return 0;
}

int verificarAluno(char inputName[], char inputPassword[], Alunos alunos[])
{
    int id = verificarNome(inputName, alunos);
    if (id != -1 && verificarPasse(inputPassword, id, alunos))
    {
        return id;
    }

    return -1;
}
void apagarUsuario(control *controlo, int id) {
    if (id < 0 || id >= controlo->numerodeAlunos) {
        printf("ID inválido.\n");
        return;
    }

    for (int i = id; i < controlo->numerodeAlunos - 1; i++) {
        controlo->alunos[i] = controlo->alunos[i + 1];
    }

    controlo->numerodeAlunos--; 
    printf("Usuário removido com sucesso.\n");
}


void verDados(Alunos *aluno){
     printf("nome do estudante: %s \n", aluno->name);
     printf("password do estudante: %s \n", aluno->password);
}

void actualizarAluno(Alunos *aluno){
    printf("-----------------------------\n");
    printf("Digite o seu nome:");
    fgets(aluno->name, 255, stdin);
    printf("\n");
    printf("Digite a password");
    fgets(aluno->password, 255, stdin);

    printf("Usuario Actualizado com sucesso\n");
} 

void telaDeAluno(Alunos aluno, int id, control *controlo)
{
    int opcao;
    while (1)
    {
        printf("---------------------------------\n");
        printf("|      SISTEMA UNIVERSITARIO    |\n");
        printf("---------------------------------\n");
        printf("|      Seja Bem - vindo   %s    |\n", aluno.name);
        printf("Oque desejas?\n");
        printf("1) Atualizar\n");
        printf("2) ver seus dados\n");
        printf("3) apagar usuario\n");
        printf("4) Sair\n");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 1:
            actualizarAluno(&aluno);
            continue;
        case 2:
            verDados(&aluno);
             continue;
        case 3:
            apagarUsuario(controlo, id);
            return;
            break;
         default:
            break;
        return;
        }
    }
}

void listarEstudantes(control *controlo){
    if(listavazia(controlo)){
        printf("A lista esta vazia n tem nenhum estudante");
        return;
    }
    for(int i = 0; i < controlo->numerodeAlunos; i++){
        printf("nome do estudante: %s \n", controlo->alunos[i].name);
    }
}

void cadastro(control *controlo)
{
    if(listacheia(controlo)){
        printf("lista de usuarios cheia, espere por uma vaga\n");
        return;
    }

    int numeroDeEstudante = controlo->numerodeAlunos;
    printf("-----------------------------\n");
    printf("Digite o seu nome:");
    fgets(controlo->alunos[numeroDeEstudante].name, 255, stdin);
    printf("\n");
    printf("Digite a password");
    fgets(controlo->alunos[numeroDeEstudante].password, 255, stdin);

    controlo->numerodeAlunos++;
    printf("Usuario criado com sucesso\n");
}

void login(control *controlo)
{
    if(listavazia(controlo)){
        printf("cadastra-se primeiro antes de fazer o login\n");
        return; 
    }
    
    char inputName[255];
    char inputPassword[255];
    int id = 0;

    while (1)
    {
        printf("-----------------------------\n");
        printf("Digite o seu nome:");
        fgets(inputName, 255, stdin);
        printf("\n");
        printf("Digite a password");
        fgets(inputPassword, 255, stdin);
        id = verificarAluno(inputName, inputPassword, controlo->alunos);
        if (id != -1)
        {
            break;
        }
        else
        {
            printf("Palavra - passe ou nome de usuário incorreto.\n");
        }
    }

    telaDeAluno(controlo->alunos[id], id, controlo);
}

void initial(control *controlo)
{
    inicializarLista(controlo);
    while (1)
    {
        
        int opcao;
        printf("---------------------------------\n");
        printf("|      SISTEMA UNIVERSITARIO    |\n");
        printf("---------------------------------\n");
        printf("1) Cadastro\n");
        printf("2) Login\n");
        printf("3) Listar estudantes\n");
        printf("4) Sair\n");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 1:
            cadastro(controlo);
            continue;
        case 2:
            login(controlo);
            continue;
        case 3:
            listarEstudantes(controlo);
            continue;
        default:
            printf("Deixando o programa...\n");
            return;
            break;
        }
    }
    
}

int main()
{

    control controlo;

    initial(&controlo);
    return 0;
}
