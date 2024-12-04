/*
2) Escribir una función que tenga como parametro un vector de tamaño 500 Tvector
ya cargado y su maximo logico y devuelva:
- El numero par mas alto en el vector (si no hay devolver -1).
- Una variable booleana que te diga si hay numeros impares en el vector (true) o
si no los hay (false).

Recorrer solo una vez el vector.
*/

#include <stdbool.h>

#define MAX 500

typedef int Tvector[MAX];

void obtener_mayor_par_y_detectar_impar(Tvector vector, 
                                        int ML,
                                        int *maximo_par,
                                        bool *hay_impar
                                        )
{
    int i, numero;
    bool es_par;

    *hay_impar = false; // Si no se actualiza a true debo devolver false
    *maximo_par = -1; // Si no hay un mayor par debo devolver -1 (por enunciado)

    for (i = 0; i < ML; i++)
    {
        numero = vector[i];
        es_par = numero % 2 == 0;

        if (!es_par)
            *hay_impar = true;
        else if (numero > *maximo_par)
            *maximo_par = numero;
    }
    
}