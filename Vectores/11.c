/*
11) Escribir un subprograma que dada una matriz de números reales, de n x m,
devuelva un vector que en cada posición i almacene el elemento mínimo de cada
fila i de la matriz.
*/

#include <stdio.h>

#define MF_F 5 // n
#define MF_C 4 // m

typedef float t_vec[MF_F];
typedef float t_matriz[MF_F][MF_C];

void encontrar_minimos(t_matriz matriz, t_vec minimos)
{
    int i, j;
    float minimo;

    for (i = 0; i < MF_F; i++)
    {
        minimo = matriz[i][0];

        for (j = 0; j < MF_C; j++)
            if (matriz[i][j] < minimo)
                minimo = matriz[i][j];

        minimos[i] = minimo;
    }
}

void mostrar_vector(t_vec vector, int ML)
{
    int i;

    for (i = 0; i < ML; i++)
        printf("%.2f ", vector[i]);
}

int main()
{
    t_matriz matriz = {
        {4, 3, 2, 1},
        {3, 8, 9, 1},
        {10, 9, 3, 19},
        {7, 4, 2, 7},
        {1, 3, 5, 2},
    };

    t_vec minimos;

    encontrar_minimos(matriz, minimos);
    mostrar_vector(minimos, MF_F);
    return 0;
}