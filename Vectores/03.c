/*
3) Dado un listado de valores numéricos i y x,
donde i es un entero mayor que 0 y x un real,
almacenar x en la posición i de un vector.

El listado no se ingresa ordenado por posición.

Informar la cantidad de números y el contenido delvector indicando la posición
ocupada por cada número a partir de la primera posición.
*/

#include <stdio.h>
#include <stdbool.h>

#define MF 150

typedef float t_vec[MF];
typedef bool t_pos[MF];

void vaciar_vector(t_pos posiciones)
{
    int i;

    for (i = 0; i < MF; i++)
        posiciones[i] = false;
}

void ingresar_datos(t_vec vector, t_pos posiciones)
{
    int i;
    float x;

    do
    {
        printf("Ingrese una posición (0 para salir): ");
        scanf("%d", &i);

        if (i > 0 && i <= MF)
        {
            printf("Ingrese un número: ");
            scanf("%f", &x);

            vector[i - 1] = x;
            posiciones[i - 1] = true;
        }
        else if (i != 0)
        {
            printf("Posición inválida\n");
        }
    } while (i != 0);
}

int obtener_cantidad_numeros(t_pos posiciones)
{
    int cantidad_numeros, i;
    cantidad_numeros = 0;

    for (i = 0; i < MF; i++)
        if (posiciones[i])
            cantidad_numeros++;

    return cantidad_numeros;
}

void imprimir_vector(t_vec vector, t_pos posiciones)
{
    int i;

    for (i = 0; i < MF; i++)
        if (posiciones[i])
        {
            printf("%d: ", i);
            printf("%.2f ", vector[i]);
        }
}

int main()
{
    t_vec vector;
    t_pos posiciones;

    vaciar_vector(posiciones);
    ingresar_datos(vector, posiciones);

    printf("La cantidad de números del vector son: %d\n",
        obtener_cantidad_numeros(posiciones));
        
    imprimir_vector(vector, posiciones);

    return 0;
}