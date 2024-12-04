/*
5) Desarrollar una función recursiva para obtener el mayor valor en un vector de
números enteros.
*/

#include <stdio.h>

#define MF 10

typedef int vector_t[MF];

int obtener_mayor(vector_t lista, int ML, int i)
{
    if (i + 1 < ML)
        if (lista[i] > obtener_mayor(lista, ML, i + 1))
            return lista[i];
        else
            return obtener_mayor(lista, ML, i + 1);

    return lista[i];
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
    vector_t lista = {1, 3, 2};
    int ML;

    ML = 3;

    mostrar_lista(lista, ML);
    printf("\nMayor: %d\n", obtener_mayor(lista, ML, 0));

    return 0;
}