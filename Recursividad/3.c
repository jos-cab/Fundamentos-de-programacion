/*
3) Desarrollar una función recursiva para realizar una búsqueda binaria en un vector.
*/

#include <stdio.h>

int busqueda_binaria(int v[], int n, int l, int r)
{
    int m = (l + r) / 2, posicion;

    if (l > r)
        posicion = -1;
    else if (v[m] > n)
        posicion = busqueda_binaria(v, n, l, m - 1);
    else if (v[m] < n)
        posicion = busqueda_binaria(v, n, m + 1, r);
    else
        posicion = m;

    return posicion;
}

int main()
{
    int v[] = {1, 2, 3, 4, 5};
    printf("[1, 2, 3, 4, 5], 5: %d", busqueda_binaria(v, 6, 0, 5));
    return 0;
}
