/*
1) Escribir una función que dados a y b enteros devuelva a ^ b.
*/

#include <stdio.h>

float elevado(int x, int y)
{
    float resultado;
    int i, j;

    resultado = 1;

    if (y >= 0)
        for (j = 0; j < y; j++)
            resultado *= x;
    else
        for (j = 0; j < -y; j++)
            resultado /= x;

    return resultado;
}

int main()
{
    printf("2 ^ 2 = %.0f\n", elevado(2, 2));
    printf("3 ^ 2 = %.0f\n", elevado(3, 2));
    printf("2 ^ 3 = %.0f\n", elevado(2, 3));
    printf("0 ^ 1 = %.0f\n", elevado(0, 1));
    printf("1 ^ 0 = %.0f\n", elevado(1, 0));
    printf("-2 ^ 3 = %.0f\n", elevado(-2, 3));
    printf("2 ^ -3 = %.3f\n", elevado(2, -3));
    return 0;
}
