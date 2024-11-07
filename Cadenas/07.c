/*
7.Escribir una función en C, que reciba una cadena que representa una palabra y
devuelva si la misma es o no un palíndromo.

Una palabra es un palíndromo, si se lee igual en ambos sentidos.

Probar la función con los siguientes casos de prueba:
- anilina (Es palíndromo)
- ojo (Es palíndromo)
- radar (Es palíndromo)
- reconocer (Es palíndromo)
- algoritmos (No es palíndromo)
- programas (No es palíndromo)

Evitar realizar ciclos innecesarios.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 16

typedef char t_cadena[MAX];

bool es_palindromo(t_cadena cadena)
{
    bool palindromo;
    unsigned short int cantidad_caracteres;
    int i;

    palindromo = true;
    cantidad_caracteres = strlen(cadena);

    i = 0;

    while(palindromo && i < cantidad_caracteres)
    {
        palindromo = cadena[i] == cadena[cantidad_caracteres - 1 - i];
        i++;
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

    if (es_palindromo("algoritmos")) printf("'algoritmos' es palindromo\n");
    else printf("'algoritmos' no es palindromo\n");

    if (es_palindromo("programas")) printf("'programas' es palindromo\n");
    else printf("'programas' no es palindromo\n");

    return 0;
}
