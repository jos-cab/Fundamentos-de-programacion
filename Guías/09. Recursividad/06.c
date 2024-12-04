/*
6) Desarrollar un programa que solicite al usuario el ingreso de un numero
entero y lo muestre invertido.

No se puede utilizar vectores.
*/

#include <stdio.h>

void mostrar_numero_invertido(int numero)
{
    if (numero != 0)
    {
        printf("%d", numero % 10);
        mostrar_numero_invertido(numero / 10);
    }
}

int main()
{
    int numero;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    mostrar_numero_invertido(numero);

    return 0;
}
