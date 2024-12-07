/*
9) Dado un vector a de longitud n ordenado ascendente y un elemento p del mismo
tipo que los elementos del vector,

intercalar p en el vector a de modo que siga ordenado.
*/

#include <stdio.h>
#include <stdbool.h>

#define MF 6
#define n 5

typedef int t_vec[MF];

void mostrar_vector(t_vec vector, int ML)
{
    int i;

    for (i = 0; i < ML; i++)
        printf("%d ", vector[i]);
}

void agregar_espacio(t_vec vector, int ML, int posicion)
{
    int i;

    for (i = ML; i >= posicion; i--)
    {
        vector[i + 1] = vector[i];
    }
}

void insertar(int p, t_vec vector)
{
    int izquierda, medio, derecha;
    bool insertado;

    insertado = false;
    izquierda = 0;
    derecha = n - 1;

    while (izquierda <= derecha && !insertado)
    {
        medio = (izquierda + derecha) / 2;

        if (vector[medio] <= p && vector[medio + 1] >= p) // p:4  _3_ 5
        {
            agregar_espacio(vector, n - 1, medio + 1);
            vector[medio + 1] = p;
            insertado = true;
        }
        else if (vector[medio] >= p && vector[medio - 1] <= p) // p:3  2 _4_
        {
            agregar_espacio(vector, n - 1, medio);
            vector[medio] = p;
            insertado = true;
        }
        else if (vector[medio] < p)
        {
            izquierda = medio + 1;
        }
        else
        {
            derecha = medio - 1;
        }
    }
}

int main()
{
    t_vec a = {1, 2, 3, 5, 6};
    int p;
    p = 4;

    insertar(p, a);
    mostrar_vector(a, MF);

    return 0;
}
