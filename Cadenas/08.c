/*
8. Escribir una función en C, que reciba una cadena que representa una palabra o
una frase y devuelva si la misma es o no un palíndromo.

Un palíndromo, es una palabra o frase que se lee igual en ambos sentidos.

Probar la función con los siguientes casos de prueba:
- anilina (Es palíndromo)
- ojo (Es palíndromo)
- radar (Es palíndromo)
- reconocer (Es palíndromo)
- amar a roma (Es palíndromo)
- ana lava lana (Es palíndromo)
- a ti no, bonita (Es palíndromo)
- algoritmos y programas (No es palíndromo)
- lenguaje C (No es palíndromo)

Evitar realizar ciclos innecesarios.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 32
#define DIFERENCIA_MAYUSCULA_MINUSCULA 32

typedef char t_cadena[MAX];

bool es_letra(char caracter)
{
    return ('a' <= caracter && caracter <= 'z') || 
           ('A' <= caracter && caracter <= 'Z');
}

char minuscula(char caracter)
{
    if ('A' <= caracter && caracter <= 'Z')
        caracter += DIFERENCIA_MAYUSCULA_MINUSCULA;
    
    return caracter;
}

bool es_palindromo(t_cadena cadena)
{
    bool palindromo;
    unsigned short int cantidad_caracteres;
    int i, j;

    palindromo = true;
    cantidad_caracteres = strlen(cadena);
    i = 0;
    j = cantidad_caracteres - 1;

    while(palindromo && i < (cantidad_caracteres / 2))
    {
        while (!es_letra(cadena[j]))
            j--;

        while ( !es_letra(cadena[i]))
            i++;
        
        palindromo = (minuscula(cadena[i]) == minuscula(cadena[j]));

        i++;
        j--;
    }
    
    return palindromo;
}

int main()
{
    if (es_palindromo("anilina")) printf("'anilina' es palindromo\n");
    else printf("'anilina' no es palindromo\n");
    
    if (es_palindromo("ojo")) printf("'ojo' es palindromo\n");
    else printf("'ojo' no es palindromo\n");

    if (es_palindromo("radar")) printf("'radar' es palindromo\n");
    else printf("'radar' no es palindromo\n");

    if (es_palindromo("reconocer")) printf("'reconocer' es palindromo\n");
    else printf("'reconocer' no es palindromo\n");

    if (es_palindromo("amar a roma")) printf("'amar a roma' es palindromo\n");
    else printf("'amar a roma' no es palindromo\n");

    if (es_palindromo("ana lava lana")) 
        printf("'ana lava lana' es palindromo\n");
    else 
        printf("'ana lava lana' no es palindromo\n");

    if (es_palindromo("a ti no, bonita")) 
        printf("'a ti no, bonita' es palindromo\n");
    else 
        printf("'a ti no, bonita' no es palindromo\n");

    if (es_palindromo("algoritmos y programas")) 
        printf("'algoritmos y programas' es palindromo\n");
    else 
        printf("'algoritmos y programas' no es palindromo\n");

    if (es_palindromo("lenguaje C")) printf("'lenguaje C' es palindromo\n");
    else printf("'lenguaje C' no es palindromo\n");

    return 0;
}
