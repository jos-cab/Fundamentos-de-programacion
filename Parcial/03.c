/*
3) Escribir una funcion de verdad que tenga como parametro una matriz de tamaño 
TMatriz ya cargada, sus respectivos maximos logicos y un numero entero.

Devolver True si el numero entero se encuentra en la matriz o false si no lo
está.
*/

#include <stdbool.h>

// No recuerdo los máximos lógicos que pedía originalmente
#define MAX 45

typedef int TMatriz[MAX][MAX];

bool existe_en_matriz(TMatriz matriz, int MLF, int MLC, 
                   int x)
{
    bool numero_en_matriz;
    int i, j;

    // Se debe definir la variable para compararla en los while
    numero_en_matriz = false;

    i = 0;

    while (!numero_en_matriz && i < MLF)
    {
        j = 0;

        while (!numero_en_matriz && j < MLC)
        {
            numero_en_matriz = matriz[i][j] == x;
            j++;
        }

        i++;
    }

    return numero_en_matriz;
}