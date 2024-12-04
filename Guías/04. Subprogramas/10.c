/*
10) Escribir un programa que ingrese un listado de números e informe la cantidad
de múltiplos de 2, 3, 5 y 7.

Utilizar una función que dados 2 números devuelva una señal que indique si el
primero es o no múltiplo del segundo.
*/

#include <stdio.h>
#include <stdbool.h>

bool validar_multiplo(int n, int multiplo)
{
    return (n % multiplo == 0);
}

int main()
{
    int multiplos_2 = 0;
    int multiplos_3 = 0;
    int multiplos_5 = 0;
    int multiplos_7 = 0;

    int numero;

    printf("Ingresa números para múltiplos de 2, 3, 5 y 7. 0 para salir.\n");

    do
    {
        printf("Ingrese un número (0 para salir): ");
        scanf("%d", &numero);

        if (numero != 0)
        {
            if (validar_multiplo(numero, 2))
                (multiplos_2)++;
            if (validar_multiplo(numero, 3))
                (multiplos_3)++;
            if (validar_multiplo(numero, 5))
                (multiplos_5)++;
            if (validar_multiplo(numero, 7))
                (multiplos_7)++;
        }

    } while (numero != 0);

    printf("Múltiplos de 2: %d\n", multiplos_2);
    printf("Múltiplos de 3: %d\n", multiplos_3);
    printf("Múltiplos de 5: %d\n", multiplos_5);
    printf("Múltiplos de 7: %d\n", multiplos_7);

    return 0;
}
