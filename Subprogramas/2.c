/*
2) Idem 1 para parámetros reales.
*/

#include <stdio.h>

float potencia(float x, float y)
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
    printf("2 ^ 2 = %.0f\n", potencia(2, 2));
    printf("2.1 ^ 2 = %.2f\n", potencia(2.1, 2));
    printf("2 ^ 2.1 = %.2f\n", potencia(2, 2.1));

    return 0;
}
