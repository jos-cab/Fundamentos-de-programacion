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
        if ('0' <= cadena[i] && cadena[i] <= '9')
            cantidad_digitos_numericos++;
        
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
