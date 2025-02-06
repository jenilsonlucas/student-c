#include <stdio.h>
#include <stdlib.h>


int potencia(int base, int expoente){

    if(expoente == 0) return 1;
    if(expoente == 1) return base;
   
    int result = 1;
    for(int i = 0; i < expoente; i++) result *= base;

    return result;
}

int factorial(int numero)
{
    if(numero == 0 || numero == 1) return 1;
    int result = 1;
    for(int i = 1; i <= numero; i++){
        result *= i ; 
    }

    return result;
}

double serieRaiz(int n, int x)
{
    int term = 1;

    for(int i = 1; i <= n; i++)
    {
        if((i % 2) != 0)
        {
            term = term + (1.0/potencia(2, i)) * (potencia(x - 1, i) / factorial(i));
        }else {
            term = term - (1.0/potencia(2, i)) * (potencia(x - 1, i) / factorial(i));
        }
    }
}


int main()
{
    printf("Potencia de 5 ^ 2 = %d", potencia(5, 2));
    printf("fatorial de 5 = %d\n", factorial(5));
    return 0;
}