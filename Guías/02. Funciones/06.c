/*
6. Escribir una función que reciba dos valores enteros, y devuelva el máximo
común divisor entre ambos números.

Recordemos que se define el máximo común divisor (MCD) de dos o más números
enteros al mayor número entero que los divide sin dejar resto alguno.

Te sugerimos que antes de programar la solución te hagas preguntas del tipo a
las planteadas en en el ejercicio anterior.
*/

#include <stdio.h>
#include <stdbool.h>

int mcd(int numero_1, int numero_2) {
    int maximo_divisor, aux, i;
    bool resultado_negativo;

    resultado_negativo = (numero_1 < 0) || (numero_2 < 0);

    if (numero_1 < 0) numero_1 *= -1; // abs(numero_1)
    if (numero_2 < 0) numero_2 *= -1; // abs(numero_2)

    // swap
    if (numero_2 < numero_1) {
        aux = numero_2;
        numero_2 = numero_1;
        numero_1 = aux;
    }

    if (numero_1 == 0)
        maximo_divisor = numero_2;
    else
    {
        maximo_divisor = -1;
        i = numero_1;

        while ((i >= 1) && (maximo_divisor == -1))
        {
            if ((numero_1 % i == 0) && (numero_2 % i == 0)) {
                maximo_divisor = i;
            }

            i--;
        }

        if (resultado_negativo)
            maximo_divisor *= -1;
    }

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
