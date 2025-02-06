#include <stdio.h>
#include <stdlib.h>


float rounded(float number)
{
    int inteiro = (int)number;
    float decimal = number - inteiro;

    if(decimal >= 0.0 && decimal <= 0.24)
        return inteiro + 0.25;
    if(decimal <= 0.54)
        return inteiro + 0.55;
    if(decimal <= 0.74)
        return inteiro + 0.75;
    if(decimal <= 0.99)
        return inteiro + 1.0;
}

int main()
{
    float n = rounded(1.90);

    printf("the value rounded: %.2f\n", n);
    return 0;
}