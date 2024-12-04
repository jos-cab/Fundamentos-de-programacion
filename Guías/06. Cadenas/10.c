/*
10. Escribir un programa modular que solicite el ingreso de dos palabras y luego
muestre las mismas según la longitud de cada una de ellas, mostrando primero
la de menor longitud.

A igualdad de longitud, mostrar primero la menor de las dos, en términos de
orden alfabético.

Las palabras tienen una longitud máxima de 15 caracteres.
*/

#include <stdio.h>
#include <string.h>

#define MAX 15

typedef char t_cadena[MAX];

// Hice esta función de tipo int para su mejor entendimiento.
// A demás, en un futuro se pueden cambiar los parámetros para que compare
// más de 2 cadenas.
int obtener_menor_cadena_alfabetico(t_cadena cadena_1, t_cadena cadena_2)
{
    unsigned short int longitud_cadenas;
    int menor_cadena, i;

    // todas las cadenas deben tener el mismo longitud
    longitud_cadenas = strlen(cadena_1);
    menor_cadena = -1;
    i = 0;

    while ((menor_cadena == -1) && (i < longitud_cadenas))
    {
        if (cadena_1[i] < cadena_2[i])
            menor_cadena = 1;
        else if (cadena_2[i] < cadena_1[i])
            menor_cadena = 2;

        i++;
    }

    return menor_cadena;   
}

void imprimir_cadenas_ordenadas_alfabetico(t_cadena cadena_1, t_cadena cadena_2)
{
    int menor_cadena;

    menor_cadena = obtener_menor_cadena_alfabetico(cadena_1, cadena_2);

    switch (menor_cadena)
    {
        case 1:
            printf("Las cadenas en orden alfabético son: %s, %s\n",
                cadena_1, cadena_2);
            break;
        case 2:
            printf("Las cadenas en orden alfabético son: %s, %s\n",
                cadena_2, cadena_1);
            break;
        
        default:
            printf("Las cadenas son iguales: %s\n", cadena_1);
            break;
    }
}

void imprimir_cadenas_ordenadas_longitud(t_cadena cadena_1, t_cadena cadena_2)
{
    unsigned short int longitud_cadena_1, longitud_cadena_2;

    longitud_cadena_1 = strlen(cadena_1);
    longitud_cadena_2 = strlen(cadena_2);

printf("");

    if (longitud_cadena_1 < longitud_cadena_2)
        printf("Las cadenas en orden de longitud son:  %s, %s\n",
            cadena_1, cadena_2);

    else if (longitud_cadena_2 < longitud_cadena_1)
        printf("Las cadenas en orden de longitud son: %s, %s\n",
            cadena_2, cadena_1);

    else
        imprimir_cadenas_ordenadas_alfabetico(cadena_1, cadena_2);
    
}

int main()
{
    imprimir_cadenas_ordenadas_longitud("avión", "auto");
    imprimir_cadenas_ordenadas_longitud("casa", "edificio");
    imprimir_cadenas_ordenadas_longitud("cadena_1", "cadena_2");
    // No lo pedía el ejercicio, pero también tuve en cuenta si las cadenas
    // son iguales.
    imprimir_cadenas_ordenadas_longitud("cadena_1", "cadena_1");

    return 0;
}
