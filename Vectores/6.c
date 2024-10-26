/*
6) Dados 2 vectores a y b de longitudes n y m,
el primero ordenado ascendente y el segundo ordenado descendente,
crear un nuevo vector c de n + m elementos intercalando los elementos de a y b
de modo que c quede ordenado ascendente.
*/

#include <stdio.h>

#define MF 15

#define n 5
#define m 10

typedef int t_vec[MF];

void vaciar_vector(t_vec vector)
{
    int i;

    for (i = 0; i < MF; i++)
        vector[i] = 0;
}

void invertir_vector(t_vec vector, int ML)
{
    int aux, i;

    for (i = 0; i < ML / 2; i++)
    {
        aux = vector[i];
        vector[i] = vector[ML - i - 1];
        vector[ML - i - 1] = aux;
    }
}

void mostrar_vector(t_vec vector, int ML)
{
    int i;

    for (i = 0; i < ML; i++)
        printf("%d ", vector[i]);
}

void calcular_c(t_vec a, t_vec b, t_vec c)
{
    int i, j;

    // Relleno con a
    for (i = 0; i < n; i++)
        c[i * 2] = a[i];

    // Relleno con b
    i = 0;
    j = 0;

    invertir_vector(b, m);

    while (j < m)
    {
        if (c[i] == 0)
        {
            c[i] = b[j];
            j++;
        }

        i++;
    }
}

int main()
{
    t_vec a = {1, 2, 3, 4, 5};
    t_vec b = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    t_vec c;

    vaciar_vector(c);

    calcular_c(a, b, c);

    mostrar_vector(c, m + n);
    return 0;
}
