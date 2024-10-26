/*
1.Escribir un programa que solicite el ingreso de 2 valores enteros y luego
informe el resultado de multiplicarlos, pero mediante sumas sucesivas.

Optimizar el cálculo, realizando la menor cantidad de ciclos posibles.

Tener en cuenta que el usuario puede ingresar valores negativos.
*/

#include <stdio.h>

long multiplicar(int x, int y)
{
    int i;
    long resultado;

    resultado = 0;

    if (x != 0 && y != 0)
    {
        if (y < 0)
        {
            y *= -1;
            x *= -1;
        }

        if (x < y)
            for (i = 0; i < x; i++)
                resultado += y;
        else
            for (i = 0; i < y; i++)
                resultado += x;
    }

    return resultado;
}

int main()
{
    printf("3 x 7 = %li\n", multiplicar(3, 7));
    printf("7 x 3 = %li\n", multiplicar(7, 3));
    printf("10 x 5 = %li\n", multiplicar(10, 5));
    printf("-1 x 5 = %li\n", multiplicar(-1, 5));
    printf("5 x -1 = %li\n", multiplicar(5, -1));
    printf("-5 x -3 = %li\n", multiplicar(-5, -3));
    printf("0 x 100 = %li\n", multiplicar(0, 100));
    return 0;
}
