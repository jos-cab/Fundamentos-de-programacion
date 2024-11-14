/*
2) Literalmente una búsqueda binaria solo que sin devolver la posición, tenias 
que devolver si era encontrado o no.
*/

#include <stdbool.h>

#define MF 1000

typedef int Tvector[MF];

bool buscar(Tvector vector, int ML, int x)
{
    int izquierda, medio, derecha;
    bool encontrado;

    encontrado = false;
    izquierda = 0;
    derecha = ML - 1;

    if ((vector[izquierda] < x) && (x < vector[derecha]))
        while ((!encontrado) && (izquierda <= derecha))
        {
            medio = (izquierda + derecha) / 2;

            if (vector[medio] == x)
                encontrado = true;
            else if(vector[medio] < x)
                izquierda = medio + 1;
            else // vector[medio] > x
                derecha = medio - 1;
        }
    
    return encontrado;
}