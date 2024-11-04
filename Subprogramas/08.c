/*
8) Un número entero positivo se dice perfecto si es igual a la suma de todos
sus divisores excepto el mismo.

Ejemplo: los números
6 (1+2+3),
28 (1+2+4+7+14) y
496 (1+2+4+8+16+31+62+124+248)
son perfectos.

Se pide:
a) Escribir una función booleana que llamadadesde un programa,
permita discernir si un número (único parámetro) es perfecto.
b) Dar un ejemplo de cómo se hace referencia a dicha función desde un programa
o desde otro subprograma.

Nota: no usar variables globales.
*/

#include <stdio.h>
#include <stdbool.h>

int suma_divisores(int n)
{
    int i, resultado;
    resultado = 0;

    for (i = 1; i < n; i++)
        if (n % i == 0)
            resultado += i;

    return resultado;
}

bool es_perfecto(int n)
{
    return (suma_divisores(n) == n);
}

int main()
{
    if (es_perfecto(1))
        printf("1 es perfecto");
    else
        printf("1 no es perfecto");

    printf("\n");

    if (es_perfecto(2))
        printf("2 es perfecto");
    else
        printf("2 no es perfecto");

    printf("\n");

    if (es_perfecto(6))
        printf("6 es perfecto");
    else
        printf("6 no es perfecto");

    printf("\n");

    if (es_perfecto(28))
        printf("28 es perfecto");
    else
        printf("28 no es perfecto");

    printf("\n");

    if (es_perfecto(100))
        printf("100 es perfecto");
    else
        printf("100 no es perfecto");

    printf("\n");

    return 0;
}
