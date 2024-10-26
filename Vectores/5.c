/*
5) Cargar un conjunto de números de documento en un vector.

No se conoce la cantidad de datos válidos.

Informar el número de documento más alto del conjunto y la posición que ocupa.

Puede haber repetición, en este caso informar todas las posiciones que ocupa.
*/

#include <stdio.h>

#define MF 100

typedef int t_vec[MF];

void ingresar_datos(t_vec vector, int *ML)
{
    int numero;
    *ML = 0;

    printf("Ingrese números para saber el mayor, la cantidad de veces que aparece\n");
    printf("y la/s posición/es que ocupa.\n");
    printf("\n");

    do
    {
        printf("Ingrese un número de documento (0 para salir): ");
        scanf("%d", &numero);

        vector[*ML] = numero;

        (*ML)++;
    } while (numero != 0 && *ML < MF);
}

int calcular_mayor(t_vec vector, int ML)
{
    int i;
    int mayor;
    mayor = vector[0];

    for (i = 0; i < ML; i++)
        if (vector[i] > mayor)
            mayor = vector[i];

    return mayor;
}

unsigned short calcular_cantidad_mayor(t_vec vector, int ML, int mayor)
{
    int cantidad_mayor, i;
    cantidad_mayor = 0;

    for (i = 0; i < ML; i++)
        if (vector[i] == mayor)
            cantidad_mayor++;

    return cantidad_mayor;
}

void mostrar_posiciones_mayor(t_vec vector, int ML, int mayor)
{
    int i;

    printf("Las posiciones donde aparece el mayor número (%d) es/son: ", mayor);

    for (i = 0; i < ML; i++)
        if (vector[i] == mayor)
            printf("%d ", i);
}

int main()
{
    int mayor;
    int ML;
    t_vec vector;

    ingresar_datos(vector, &ML);
    if (vector[0] != 0)
    {
        mayor = calcular_mayor(vector, ML);
        printf("La cantidad de veces que aparece el mayor número (%d) es: %hu\n",
               mayor, calcular_cantidad_mayor(vector, ML, mayor));
        mostrar_posiciones_mayor(vector, ML, mayor);
    }

    return 0;
}