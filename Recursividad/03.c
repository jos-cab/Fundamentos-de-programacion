/*
3) Desarrollar una función recursiva para realizar una búsqueda binaria en un
vector.
*/

#include <stdio.h>

#define MF 10

typedef int vector_t[MF];

int busqueda_binaria(vector_t lista, int x, int izquierda, int derecha)
{
    int medio = (izquierda + derecha) / 2;

    if (izquierda > derecha)
        return -1;
    else if (lista[medio] > x)
        return busqueda_binaria(lista, x, izquierda, medio - 1);
    else if (lista[medio] < x)
        return busqueda_binaria(lista, x, medio + 1, derecha);

    return medio;
}

void mostrar_lista(vector_t lista, int ML)
{
    int i;

    printf("Lista: ");
    for (i = 0; i < ML; i++)
        printf("%d ", lista[i]);
}

int main()
{
    vector_t lista = {1, 2, 3, 4, 5};
    int ML, x, posicion;

    ML = 5;
    x = 6;

    mostrar_lista(lista, ML);
    printf("\nNumero a buscar: %d\n", x);

    posicion = busqueda_binaria(lista, x, 0, ML - 1);

    if (posicion == -1)
        printf("\nEl elemento no se encuentra en la lista\n");
    else
        printf("\nEl elemento se encuentra en la lista en el índice %d\n", posicion);

    return 0;
}
