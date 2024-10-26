/*
2) Dado un listado de números reales del cual no se conoce la cantidad,
almacenar los números en un vector en el orden de entrada.

Informar lacantidad de números y el contenido del vector indicando la posición
ocupada por cada número a partir de la primera posición.
*/

#include <stdio.h>

#define MF 3

typedef float t_vec[MF];

void ingresar_datos(t_vec vector, int *ML)
{
    int i;

    printf("Ingrese números (0 para salir)\n");

    i = 0;
    do
    {
        printf("Ingrese número: ");
        scanf("%f", &vector[i]);
        i++;
    } while (vector[i - 1] != 0 && i < MF);

    if (i == MF && vector[i - 1] != 0)
    {
        printf("Se alcanzó la máxima cantidad de números permitidos para el ingreso\n");
        *ML = i;
    }
    else
    {
        *ML = i - 1;
    }
}

void mostrar_vector(t_vec vector, int ML)
{
    int i;

    for (i = 0; i < ML; i++)
        printf("%d: %f\n", i, vector[i]);
}

int main()
{
    int ML;
    t_vec vector;

    ingresar_datos(vector, &ML);

    printf("Se ingresaron %d números:\n", ML);
    mostrar_vector(vector, ML);

    return 0;
}
