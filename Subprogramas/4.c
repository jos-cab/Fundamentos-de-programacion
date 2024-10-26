/*
4) Escribir una función que dados 2 números,
calcule el porcentaje que el primero representa respecto del segundo.
*/

#include <stdio.h>

float calcular_porcentaje(int x, int y)
{
    return (float)(x * 100) / y;
}

int main()
{
    printf("20 es %.0f%% de 30\n", calcular_porcentaje(20, 30));
    printf("50 es %.0f%% de 100\n", calcular_porcentaje(50, 100));
    printf("15 es %.3f%% de 37\n", calcular_porcentaje(15, 37));
    printf("72 es %.5f%% de 28\n", calcular_porcentaje(72, 28));
    return 0;
}
