/*
9. Escribir una función que recibirá por parámetro, una palabra, que representa
un sustantivo en singular.

La función deberá devolver, el plural de dicho sustantivo, aplicando las
siguientes reglas:

a. Agregar una “s” al final, si la palabra termina en vocal sin acento.
b. Agregar una “s” al final, si la palabra termina con una é (acentuada).
c. Si la palabra termina en “z”, la reemplazamos por “ces”.
d. Agregamos “es” al final, si la palabra termina en una consonante (a excepción
de la “s”, la “z”, y la “x”), ó si la palabra termina con las vocales
acentuadas: á, í, ó, ú.
e. Si el sustantivo termina en “s” ó “x”, entonces el plural es igual al
singular, por lo tanto la función deberá devolver lo mismo que recibió.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 16

typedef char t_cadena[MAX];

void borrar_final(t_cadena cadena)
{
    unsigned short int indice_ultimo_caracter;

    indice_ultimo_caracter = strlen(cadena) - 1;

    cadena[indice_ultimo_caracter] = '\0';
}

bool termina_en(char final, t_cadena cadena)
{
    unsigned short int indice_ultimo_caracter;

    indice_ultimo_caracter = strlen(cadena) - 1;

    return cadena[indice_ultimo_caracter] == final;
}

void obtener_plural(t_cadena palabra, t_cadena plural)
{
    bool termina_en_vocal_sin_acento;

    termina_en_vocal_sin_acento = termina_en('a', palabra) || 
                                  termina_en('e', palabra) ||
                                  termina_en('i', palabra) ||
                                  termina_en('o', palabra) ||
                                  termina_en('u', palabra);
    
    strcpy(plural, palabra);

    if (termina_en_vocal_sin_acento)
        strcat(plural, "s");
    else if (termina_en('é', palabra))
        strcat(plural, "s");
    else if (termina_en('z', palabra))
    {
        borrar_final(plural);
        strcat(plural, "ces");
    }
    else if (!(termina_en('s', palabra) || termina_en('x', palabra)))
        strcat(plural, "es");

}

void imprimir_plural(t_cadena palabra)
{
    t_cadena plural;

    obtener_plural(palabra, plural);

    printf("El plural de %s es: %s\n", palabra, plural);
}

int main()
{
    imprimir_plural("manzana");
    imprimir_plural("café");
    imprimir_plural("luz");
    imprimir_plural("flor");
    imprimir_plural("crisis");

    // La condición e) no se cumple siempre, ej: mes -> meses

    return 0;
}
