/*
6. Escribir una función que reciba dos valores enteros, y devuelva el máximo común divisor entre ambos números.

Recordemos que se define el máximo común divisor (MCD) de dos o más números enteros
al mayor número entero que los divide sin dejar resto alguno.

Te sugerimos que antes de programar la solución te hagas preguntas del tipo a las planteadas
en en el ejercicio anterior.
*/

#include <stdio.h>

int mcd(int numero_1, int numero_2)
{
    int maximo_divisor, maximo_divisor_posible, i;
    maximo_divisor = 1;
    i = 2;

    if (numero_1 > numero_2)
        maximo_divisor_posible = numero_2;
    else
        maximo_divisor_posible = numero_1;

    while (i <= maximo_divisor_posible)
    {
        if (numero_1 % i == 0 && numero_2 % i == 0)
            maximo_divisor = i;

        i++;
    }

    return maximo_divisor;
}

int main()
{
    printf("MCD(18, 48): %d\n", mcd(18, 48));
    printf("MCD(48, 18): %d\n", mcd(48, 18));
    printf("MCD(-1, -2): %d\n", mcd(-1, -2));
    printf("MCD(10, 0): %d\n", mcd(10, 0));
    printf("MCD(100, 50): %d\n", mcd(100, 50));
    return 0;
}
