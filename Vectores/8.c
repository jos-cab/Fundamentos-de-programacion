/*
8) Idem problema anterior, pero el vector está ordenado ascendente.
*/

#include <stdio.h>
#include <stdbool.h>

#define MF 5
#define n 5

typedef int t_vec[MF];

int buscar(t_vec vector, int x)
{
    int izquierda, medio, derecha;
    bool encontrado;

    encontrado = false;
    izquierda = 0;
    derecha = n - 1;

    while (izquierda <= derecha && !encontrado)
    {
        medio = (izquierda + derecha) / 2;

        if (vector[medio] == x)
            encontrado = true;
        else if (vector[medio] < x)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }

    if (!encontrado)
        medio = -1;

    return medio;
}

int main()
{
    t_vec a = {1, 2, 3, 4, 5};
    int p;
    int posicion;

    p = 6;
    posicion = buscar(a, p);

    if (posicion == -1)
        printf("No se encontró %d", p);
    else
        printf("Se encontró %d en la posición %d", p, posicion);

    return 0;
}
