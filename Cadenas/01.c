/*
1. Escribir una función que reciba como parámetro una cadena de caracteres
y devuelva la cantidad de dígitos numéricos que hay en la cadena.
*/

#include <stdio.h>

#define MAX 15

typedef char string[MAX];

unsigned short int obtener_cantidad_digitos_numericos(string cadena){
    unsigned short int cantidad_digitos_numericos;
    int i;

    cantidad_digitos_numericos = 0;
    i = 0;

    while (cadena[i] != '\0')
    {
        switch (cadena[i])
        {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
                cantidad_digitos_numericos++;
                break;
        }

        i++;
    }
    
    return cantidad_digitos_numericos;
}

int main()
{
    printf("La cantidad de digitos numéricos de 'núm3r05' es: %hu\n", 
        obtener_cantidad_digitos_numericos("núm3r05"));

    printf("La cantidad de digitos numéricos de '1234567890' es: %hu\n",
        obtener_cantidad_digitos_numericos("1234567890"));
    
    return 0;
}
