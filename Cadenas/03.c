/*
3. Escribir una función en C, que reciba como parámetro una cadena de tipo t_cadena,
y devuelva la cantidad de palabras que hay en la cadena.

Considerar que una palabra está separada de otra, por uno ó más blancos.

No recorrer la cadena más de una vez.

Declare un tipo t_cadena acorde.

Escribir el programa que incluya a la función y las invocaciones con los siguientes caso de prueba:

cant_palabras("El sol es amarillo.") devuevle 4
cant_palabras(" Hoy es 30 de Junio de 2021 ") devuevle 7
cant_palabras("30/06/2021") devuelve 1
cant_palabras("El precio es  $2.000.- ") devuelve 4
cant_palabras(" ") devuelve 0
*/

#include <stdio.h>

#define MAX 32

typedef char t_cadena[MAX];

unsigned short int cant_palabras(t_cadena cadena)
{
    unsigned short int cantidad_palabras;
    int i;

    cantidad_palabras = 0;
    i = 0;

    while (cadena[i] != '\0')
    {
        while (cadena[i] == ' ')
            i++;
        
        if (cadena[i] != ' ' && cadena[i] != '\0')
            cantidad_palabras++;

        while (cadena[i] != ' ' && cadena[i] != '\0')
            i++;
    }
        
    
    return cantidad_palabras;
}

int main()
{
    printf("Cantidad palabras: %hu\n", cant_palabras("El sol es amarillo."));
    printf("Cantidad palabras: %hu\n", cant_palabras(" Hoy es 30 de Junio de 2021 "));
    printf("Cantidad palabras: %hu\n", cant_palabras("30/06/2021"));
    printf("Cantidad palabras: %hu\n", cant_palabras("El precio es  $2.000.- "));
    printf("Cantidad palabras: %hu\n", cant_palabras(" "));
    
    return 0;
}
