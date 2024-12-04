/*
11) Generar los primeros n números naturales e informar un listado de cada
número generado junto con el factorial correspondiente.

Utilizar una función que dado un número devuelva su factorial.
*/

#include <stdio.h>

long factorial(int n)
{
    int i;
    long resultado;
    resultado = 1;

    for (i = 2; i <= n; i++)
        resultado *= i;

    return resultado;
}

int main()
{
    int i, n;
    n = 10;

    for (i = 1; i <= n; i++)
        printf("%d! = %lu\n", i, factorial(i));

    return 0;
}
