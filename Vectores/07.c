/*
7) Dado un vector a de longitud n y un elemento p del mismo tipo que los
elementos del vector, buscar p en el vector a y devolver la posición que ocupa
en caso de encontrarlo o una señal en caso contrario.

Suponer que no hay repeticiones.
*/

#include <stdio.h>

#define MF 5
#define n 5

typedef int t_vec[MF];

int buscar(t_vec vector, int x)
{
    int i;
    i = 0;

    while (vector[i] != x && i < n)
        i++;

    return i;
}

int main()
{
    t_vec a = {1, 2, 3, 4, 5};
    int p;
    unsigned short posicion;

    p = 5;
    posicion = buscar(a, p);

    if (posicion == n)
        printf("No se encontró %d", p);
    else
        printf("Se encontró %d en la posición %d", p, posicion);

    return 0;
}
