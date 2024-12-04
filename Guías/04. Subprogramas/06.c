/*
6) Escribir una función que dados a y b devuelva el resto de la división entera,
sin utilizar el operador correspondiente de lenguaje.

Validar los tipos de datos de entrada.
*/
/*
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

int calcular_resto(int x, int y)
{
    while (x >= y)
        x -= y;

    return x;
}

int modulo(int x, int y)
{
    int resultado;
    bool negativo;

    if (y == 0)
        resultado = 2147483647; // INT_MAX
    else
    {
        negar_numeros(&x, &y, &negativo);
        resultado = calcular_resto(x, y);
    }

    if (negativo)
        resultado *= -1;

    return resultado;
}

int main()
{
    printf("El resto de la división 10 / 2 = %d\n", modulo(10, 2));
    printf("El resto de la división 11 / 2 = %d\n", modulo(11, 2));
    printf("El resto de la división 12 / 2 = %d\n", modulo(12, 2));
    printf("El resto de la división -3 / 1 = %d\n", modulo(-3, 1));
    printf("El resto de la división -11 / 2 = %d\n", modulo(-11, 2));
    printf("El resto de la división 3 / -1 = %d\n", modulo(3, -1));
    printf("El resto de la división -3 / -3 = %d\n", modulo(-3, -3));
    printf("El resto de la división 71 / 25 = %d\n", modulo(71, 25));

    if (modulo(3, 0) == 2147483647)
    {
        printf("No se puede dividir por cero\n");
    }
    return 0;
}
*/