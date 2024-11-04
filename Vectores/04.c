/*
4) Cargar una serie de números reales en un vector.

No se conoce la cantidad exacta de datos,
pero se sabe que no superan los 100.

No se conocen cotas para los datos.

Informar el valor máximo, la cantidad de veces que aparece y la/s posición/es que ocupa.
*/

#include <stdio.h>

#define MF 100

typedef float t_vec[MF];

void ingresar_datos(t_vec vector, int *ML)
{
    float numero;
    *ML = 0;

    printf("Ingrese números para saber el mayor, la cantidad de veces que aparece\n");
    printf("y la/s posición/es que ocupa.\n");
    printf("\n");

    do
    {
        printf("Ingrese un número (0 para salir): ");
        scanf("%f", &numero);

        vector[*ML] = numero;

        (*ML)++;
    } while (numero != 0 && *ML < MF);
}

float calcular_mayor(t_vec vector, int ML)
{
    int i;
    float mayor;
    mayor = vector[0];

    for (i = 0; i < ML; i++)
        if (vector[i] > mayor)
            mayor = vector[i];

    return mayor;
}

unsigned short calcular_cantidad_mayor(t_vec vector, int ML, float mayor)
{
    int cantidad_mayor, i;
    cantidad_mayor = 0;

    for (i = 0; i < ML; i++)
        if (vector[i] == mayor)
            cantidad_mayor++;

    return cantidad_mayor;
}

void mostrar_posiciones_mayor(t_vec vector, int ML, float mayor)
{
    int i;

    printf("Las posiciones donde aparece el mayor número (%.2f) es/son: ", mayor);

    for (i = 0; i < ML; i++)
        if (vector[i] == mayor)
            printf("%d ", i);
}

int main()
{
    float mayor;
    int ML;
    t_vec vector;

    ingresar_datos(vector, &ML);
    if (vector[0] != 0)
    {
        mayor = calcular_mayor(vector, ML);
        printf("La cantidad de veces que aparece el mayor número (%.2f) es: %hu\n",
               mayor, calcular_cantidad_mayor(vector, ML, mayor));
        mostrar_posiciones_mayor(vector, ML, mayor);
    }

    return 0;
}