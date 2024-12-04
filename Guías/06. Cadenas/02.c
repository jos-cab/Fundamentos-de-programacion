/*
2. Escribir una función que reciba como parámetro una cadena de caracteres y 
devuelva la cantidad de caracteres no alfabéticos que hay en la cadena.

No tener en cuenta la ñ, ni las vocales acentuadas.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 15

typedef char string[MAX];

bool es_letra(char caracter)
{
    return ('a' <= caracter && caracter <= 'z') || 
           ('A' <= caracter && caracter <= 'Z');
}

unsigned short int obtener_cantidad_caracteres_no_alfabeticos(string cadena){
    unsigned short int cantidad_caracteres_no_alfabeticos;
    int i;

    cantidad_caracteres_no_alfabeticos = 0;
    i = 0;

    while (cadena[i] != '\0')
    {
        if (!es_letra(cadena[i]))
            cantidad_caracteres_no_alfabeticos++;

        i++;
    }
    
    return cantidad_caracteres_no_alfabeticos;
}

int main()
{
    printf("La cantidad de caracteres no alfabéticos de 'a{}bcde' es: %hu\n",
        obtener_cantidad_caracteres_no_alfabeticos("a{}bcde"));
        
    printf("La cantidad de caracteres no alfabéticos de '1234567890' es: %hu\n",
        obtener_cantidad_caracteres_no_alfabeticos("1234567890"));
    
    return 0;
}
