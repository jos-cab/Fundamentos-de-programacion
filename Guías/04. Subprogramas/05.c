/*
5) Escribir una función que dados a y b devuelva el cociente de la división
entera, sin utilizar el operador correspondiente del lenguaje.

Validar los tipos de datos de entrada.
*/

#include <stdio.h>
#include <stdbool.h>

void negar_numeros(int *x, int *y, bool *negativo)
{
    if (*x < 0 && *y < 0) // - / -
    {
        *x *= -1;
        *y *= -1;
        *negativo = false;
    }
    else if (*x < 0) // - / +
    {
        *x *= -1;
        *negativo = true;
    }
    else if (*y < 0) // + / -
    {
        *y *= -1;
        *negativo = true;
    }
    else // + / +
    {
        *negativo = false;
    }
}

int dividir(int x, int y)
{
    int resultado;
    resultado = 0;

    while (x >= y)
    {
        x -= y;
        resultado++;
    }

    return resultado;
}

int division_entera(int x, int y)
{
    int resultado;
    bool negativo;

    if (y == 0)
        resultado = 2147483647; // INT_MAX
    else
    {
        negar_numeros(&x, &y, &negativo);
        resultado = dividir(x, y);
    }

    if (negativo)
        resultado *= -1;

    return resultado;
}

int main()
{
    printf("La división entera 10 / 2 = %d\n", division_entera(10, 2));
    printf("La división entera 11 / 2 = %d\n", division_entera(11, 2));
    printf("La división entera 12 / 2 = %d\n", division_entera(12, 2));
    printf("La división entera -3 / 1 = %d\n", division_entera(-3, 1));
    printf("La división entera -11 / 2 = %d\n", division_entera(-11, 2));
    printf("La división entera 3 / -1 = %d\n", division_entera(3, -1));
    printf("La división entera -3 / -3 = %d\n", division_entera(-3, -3));

    if (division_entera(3, 0) == 2147483647)
    {
        printf("No se puede dividir por cero\n");
    }

    return 0;
}
