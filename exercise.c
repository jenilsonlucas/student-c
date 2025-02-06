#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define ERRO 1.0e-18


double potencia(double base, int exp){

    double result = 1.0;
    for(int i = 0; i < exp; i++){
        result *= base;
    }

    return result;
}
double calculatorPi(){
    double pi_aprox = 0.0;
    double termo = 1.0/2.0;
    int i = 1;


    do{
        termo *= ((2.0 * i - 1) / (2.0 * i)) * (1.0/(2.0*i + 1.0)); //* potencia(1.0/2.0, (2*i+1 ));
        printf("valor do termo %lf\n", termo);
        pi_aprox += termo;
        i++;
    }while(fabs(6.0 * pi_aprox - PI) <= ERRO);    

    return pi_aprox * 6.0;
}

int main()
{
   printf("\nvalor de pi aproximado %lf\n", calculatorPi());
   printf("valor de pi %lf\n", PI);
   printf("valor de erro %lf\n", ERRO);


    return 0;
}