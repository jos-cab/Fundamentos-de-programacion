/*
14) Escribir un programa que muestre las tablas de multiplicar 
desde la tabla del 1 hasta la tabla del 9 para los primeros 100 números 
naturales.
*/

#include <stdio.h>

#define N 9
#define M 100

int main()
{
    int i, j;

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= M; j++)
            printf("%i ", i * j);
        
        printf("\n\n");
    }

    return 0;
}