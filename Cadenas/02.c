/*
2. Escribir una función que reciba como parámetro una cadena de caracteres y devuelva
la cantidad de caracteres no alfabéticos que hay en la cadena.

No tener en cuenta la ñ, ni las vocales acentuadas.
*/

#include <stdio.h>

#define MAX 15

typedef char string[MAX];

unsigned short int obtener_cantidad_caracteres_no_alfabeticos(string cadena){
    // cuento la cantidad de caracteres alfabéticos y lo sustraigo de la cantidad de caracteres 
    // totales de la cadena
    unsigned short int cantidad_caracteres_alfabeticos, cantidad_caracteres_cadena;
    int i;

    cantidad_caracteres_alfabeticos = 0;
    cantidad_caracteres_cadena = 0;
    i = 0;

    while (cadena[i] != '\0')
    {
        if (('a' <= cadena[i] && cadena[i] <= 'z') || ('A' <= cadena[i] && cadena[i] <= 'Z'))
            cantidad_caracteres_alfabeticos++;

        cantidad_caracteres_cadena++;
        i++;
    }
    
    return cantidad_caracteres_cadena - cantidad_caracteres_alfabeticos;
}

int main()
{
    printf("La cantidad de caracteres no alfabéticos de 'a{}bcde' es: %hu\n", obtener_cantidad_caracteres_no_alfabeticos("a{}bcde"));
    printf("La cantidad de caracteres no alfabéticos de '1234567890' es: %hu\n", obtener_cantidad_caracteres_no_alfabeticos("1234567890"));
    
    return 0;
}
