/*
4. Escribir un programa que solicite el ingreso de dos números,
y luego informe los números primos que hay entre esos dos números.

Se debe validar que los números ingresados sean enteros
y además que el primer número sea menor o igual que el segundo.
*/

#include <stdio.h>
#include <stdbool.h>

void ingresar_numeros(int *numero_1, int *numero_2)
{
    printf("Ingrese dos números para imprimir los números primos entre ellos\n");

    do
    {
        printf("Primer número: ");
        scanf("%i", numero_1);
        printf("Segundo número: ");
        scanf("%i", numero_2);

        if (*numero_1 < 0 || *numero_2 < 0)
            printf("Los números deben ser positivos");
        else if (*numero_1 > *numero_2)
            printf("El primer número debe ser mayor o igual al segundo\n\n");

    } while (*numero_1 > *numero_2 || *numero_1 < 0 || *numero_2 < 0);
}

bool es_primo(int n)
{
    bool primo;
    int i;

    primo = true;
    i = 2;

    do
        if (n % i == 0)
            primo = false;
        else
            i++;
    while (primo && i < n / 2);

    return primo;
}

void calcular_primos(int numero_1, int numero_2)
{
    int i;

    for (i = numero_1; i < numero_2; i++)
        if (es_primo(i))
            printf("%i ", i);
}

int main()
{
    int numero_1, numero_2;

    ingresar_numeros(&numero_1, &numero_2);
    calcular_primos(numero_1, numero_2);

    return 0;
}
