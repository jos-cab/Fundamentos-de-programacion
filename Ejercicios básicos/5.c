/*
5) Ingresar un número entero y decir si:
a) es par o impar.
b) es mayor, menor o igual a cero.
*/

#include <stdio.h>

void main()
{
    int numero;

    printf("Ingrese un número: ");
    scanf("%i", &numero);

    // a)
    if (numero % 2 == 0)
        printf("El número es par");
    else
        printf("El número es impar");

    printf("\n");

    // b)
    if (numero > 0)
        printf("El número es positivo");
    else if (numero < 0)
        printf("El número es negativo");
    else
        printf("El número es cero");
}
