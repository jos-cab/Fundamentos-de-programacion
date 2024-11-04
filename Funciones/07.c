/*
7. Ahora toma el ejercicio anterior, pero intenta resolverlo aplicando el método de Euclides.

Para poder escribir el algoritmo, quizás te ayude ver el siguiente video:
https://www.youtube.com/watch?v=x6qFMSRpgpM
ó consultar en el siguiente link:
https://es.wikipedia.org/wiki/Algoritmo_de_Euclides
*/

#include <stdio.h>

int mcd(int numero_1, int numero_2)
{
    int aux, maximo_divisor;

    if (numero_2 > numero_1)
    {
        aux = numero_2;
        numero_2 = numero_1;
        numero_1 = aux;
    }

    while (numero_2 != 0)
    {
        aux = numero_1 % numero_2;
        numero_1 = numero_2;
        numero_2 = aux;
    }

    maximo_divisor = numero_1;

    return maximo_divisor;
}

int main()
{
    printf("MCD(18, 48): %d\n", mcd(18, 48));
    printf("MCD(48, 18): %d\n", mcd(48, 18));
    printf("MCD(-1, -2): %d\n", mcd(-1, -2));
    printf("MCD(-3, -15): %d\n", mcd(-3, -15));
    printf("MCD(-3, 15): %d\n", mcd(-3, 15));
    printf("MCD(10, 0): %d\n", mcd(10, 0));
    printf("MCD(100, 50): %d\n", mcd(100, 50));
    printf("MCD(0, 0): %d\n", mcd(0, 0));
    return 0;
}
