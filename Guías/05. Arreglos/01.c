/*
1) Dado n entero positivo y un listado de n números reales, almacenar los
números en un vector en el orden de entrada.

Informar el contenido del vector indicando la posición ocupada por cada número a
partir de la primera posición.
*/

#include <stdio.h>

#define MF 5
#define ML 5

typedef float t_vec[MF];

void ingresar_datos(t_vec vector)
{
    int i;

    for (i = 0; i < ML; i++)
    {
        printf("%d: ", i + 1);
        scanf("%f", &vector[i]);
    }
}

void mostrar_vector(t_vec vector)
{
    int i;

    for (i = 0; i < ML; i++)
        printf("%.2f ", vector[i]);
}

int main()
{
    t_vec vector;

    ingresar_datos(vector);
    mostrar_vector(vector);

    return 0;
}
