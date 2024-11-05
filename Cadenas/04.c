/*
4. Escribir una función en C que reciba como primer parámetro,
una cadena de tipo t_cadena, y devuelva como segundo parámetro,
la misma cadena pero invertida, sin considerar los blancos.

Sólo se deben invertir las posiciones con caracteres ciertos,
y no aquellas posiciones potenciales a ser utilizadas pero que podrían contener
caracteres inciertos.

Recorrer la cadena a lo sumo una vez.

Declare un tipo t_cadena acorde.

Escribir el programa que incluya a la función y las invocaciones con los siguientes casos y
las impresiones para comprobar que devuelven lo correcto.

Casos:
invertir_cadena("Hola, me llamo Ana.", cad_invertida) ==> cad_invertida: ".anAomallem,aloH"
invertir_cadena("234561", cad_invertida) ==> cad_invertida: "165432"
invertir_cadena(" ", cad_invertida) ==> cad_invertida: ""
invertir_cadena("Somos o No somos", cad_invertida) ==> cad_invertida: "somosoNosomoS"
*/

#include <stdio.h>
#include <string.h>

#define MAX 32

typedef char t_cadena[MAX];

void invertir_cadena(t_cadena cadena_original, t_cadena cadena_invertida)
{
    int i, j;
    unsigned short int cantidad_caracteres_original;

    cantidad_caracteres_original = strlen(cadena_original);
    j = 0;

    for (i = cantidad_caracteres_original - 1; i >= 0; i--)
    {
        
        if (cadena_original[i] != ' ')
        {
            cadena_invertida[j] = cadena_original[i];
            j++;
        }
    }

    cadena_invertida[j] = '\0';
}

int main()
{
    t_cadena cad_invertida;

    invertir_cadena("Hola, me llamo Ana.", cad_invertida);
    printf("cadena 'Hola, me llamo Ana.' invertida: '%s'\n", cad_invertida);

    invertir_cadena("234561", cad_invertida);
    printf("cadena '234561' invertida: '%s'\n", cad_invertida);

    invertir_cadena(" ", cad_invertida);
    printf("cadena ' ' invertida: '%s'\n", cad_invertida);

    invertir_cadena("Somos o No somos", cad_invertida);
    printf("cadena 'Somos o No somos' invertida: '%s'\n", cad_invertida);

    return 0;
}
