/*
11. Escribir un programa modular en C, que solicite el ingreso de no más de 20 
palabras.

Cada palabra no tendrá más de 20 caracteres. 

Informar:
1. Mostrar las palabras ingresadas.
2. Cuál es la palabra más larga.
3. Solictar el ingreso de una palabra, e indicar si la misma se encuentra entre
las ingresadas.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CANTIDAD_PALABRAS 20
#define MAXIMA_CANTIDAD_CARACTERES 20

typedef char palabra_t[MAXIMA_CANTIDAD_CARACTERES];
typedef palabra_t lista_t[CANTIDAD_PALABRAS];

void ingresar_palabras(lista_t palabras)
{
    int i;

    for (i = 0; i < CANTIDAD_PALABRAS; i++)
    {
        printf("Ingrese una palabra: ");
        fgets(palabras[i], MAXIMA_CANTIDAD_CARACTERES, stdin);
        fflush(stdin);

        // borro \n al final de cada palabra
        palabras[i][strlen(palabras[i]) - 1] = '\0';
    }
}

void mostrar_palabras(lista_t palabras)
{
    int i;

    printf("\nPalabras ingresadas\n");

    for (i = 0; i < CANTIDAD_PALABRAS; i++)
    {
        printf("%s ", palabras[i]);
    }
}

unsigned short int obtener_longitud_palabra_mas_larga(lista_t palabras)
{
    int i;
    unsigned short int longitud_palabra_mas_larga, longitud_palabra;
    
    longitud_palabra_mas_larga = 0;

    for (i = 0; i < CANTIDAD_PALABRAS; i++)
    {
        longitud_palabra = strlen(palabras[i]);

        if (longitud_palabra >  longitud_palabra_mas_larga)
            longitud_palabra_mas_larga = longitud_palabra;
    }

    return longitud_palabra_mas_larga;
}

void obtener_palabra_mas_larga(lista_t palabras,
                               unsigned short int longitud_palabra_mas_larga,
                               palabra_t palabra_mas_larga)
{
    unsigned short int longitud_palabra;
    int i;

    i = 0;

    do
    {
        longitud_palabra = strlen(palabras[i]);

        if (longitud_palabra == longitud_palabra_mas_larga)
            strcpy(palabra_mas_larga, palabras[i]);
        
        i++;
    } while (longitud_palabra != longitud_palabra_mas_larga);
}

void mostrar_palabra_mas_larga(lista_t palabras)
{
    palabra_t palabra_mas_larga;

    obtener_palabra_mas_larga(palabras,
                              obtener_longitud_palabra_mas_larga(palabras),
                              palabra_mas_larga);
    
    printf("\n\nPalabras más larga\n");
    printf("%s", palabra_mas_larga);
}

bool buscar_palabra(palabra_t palabra, lista_t palabras)
{
    bool existe_palabra;
    int i;

    existe_palabra = false;
    i = 0;

    do
    {
        if (strcmp(palabra, palabras[i]) == 0)
            existe_palabra = true;
        
    } while (!existe_palabra && (i < CANTIDAD_PALABRAS));
    
    return existe_palabra;
}

int main()
{
    palabra_t palabra;
    lista_t palabras;

    ingresar_palabras(palabras);
    mostrar_palabras(palabras);
    mostrar_palabra_mas_larga(palabras);

    printf("\n\n");
    printf("Ingrese una palabra para verificar si se encuentra en la lista: ");
    fgets(palabra, MAXIMA_CANTIDAD_CARACTERES, stdin);
    fflush(stdin);
    palabra[strlen(palabra) - 1] = '\0';

    if (buscar_palabra(palabra, palabras))
        printf("La palabra está en la lista");
    else
        printf("La palabra no está en la lista");
    
    return 0;
}
