/*
2. Escribir un programa que solicite el ingreso de una serie de números.
Por cada número ingresado se deberá informar si el mismo es ó no, un número
capicúa.

Se debe evaluar que lo ingresado, sea un número entero positivo;
de lo contrario, se debe enviar el mensaje “Número Inválido”, y solicitar el
siguiente.

El ingreso de números, termina cuando en lugar de un número, el usuario ingresa
“FIN”.
*/

#include <stdio.h>
#include <stdbool.h>

#define FIN 0

void pedir_numero(int *numero)
{
    do
    {
        printf("Ingrese un número (0 para salir): ");
        scanf("%i", numero);

        if (*numero < 0)
            printf("Número Inválido \n\n");

    } while (*numero < FIN);
}

bool es_capicua(int x)
{
    int aux, y;

    aux = x;
    y = 0;

    while (x > 0)
    {
        y *= 10;
        y += x % 10;

        x /= 10;
    }

    return y == aux;
}

int main()
{
    int numero;

    do
    {
        pedir_numero(&numero);

        if (numero != FIN)
        {
            if (es_capicua(numero))
                printf("El número es capicúa");
            else
                printf("El número no es capicúa");

            printf("\n\n");
        }

    } while (numero != FIN);

    return 0;
}
