/*
5) Desarrollar una función recursiva para obtener en mayor valor en un vector de números enteros.
*/

#include <stdio.h>

int mayor(int v[], int i)
{
    int mayor = 0;

    if (v[i] > mayor)
        mayor = v[i];

    return mayor;
}

int main()
{
    int lista[] = {1, 2, 3};
    printf("Mayor en las siguientes listas");
    printf("[1, 2, 3]: %d", mayor(lista, 0));
    return 0;
}