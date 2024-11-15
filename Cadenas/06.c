/*
6. Escribir una función para validar una nueva clave de acceso

La función deberá recibir una cadena de caracteres, que contendrá la clave
candidata, ingresada previamente por el usuario.

Devolverá true o false, dependiendo de si cumple o no con las siguientes
condiciones:
- La clave debe estar formada únicamente por, entre 4 y 8 caracteres numéricos
- Los caracteres no pueden ser todos iguales

Ejemplos:
validar("j2020") devuevle false
validar("2021a") devuevle false
validar("20X21") devuevle false
validar("2220") devuelve true
validar("23445776") devuelve true
validar("089") devuelve false
validar("027845321") devuelve false
validar("02784532") devuelve true
validar("33333") devuelve false
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 32

typedef char t_cadena[MAX];

bool son_todos_caracteres_iguales(t_cadena clave, int ML)
{
    int i;
    bool son_todos_iguales;
    char caracter_bandera;

    son_todos_iguales = true;
    caracter_bandera = clave[0];
    
    i = 1; // clave[0] ya está guardado en caracter_bandera
    while (son_todos_iguales && i < ML)
    {
        son_todos_iguales = clave[i] == caracter_bandera;
        i++;
    }
    
    return son_todos_iguales;
}

bool son_todos_caracteres_numericos(t_cadena clave, int ML)
{
    bool son_todos_numericos;
    int i;

    son_todos_numericos = true;
    i = 0;

    while (son_todos_numericos && i < ML)
    {
        // TODO: cambiar switch por condicion 0 <= clave[i] <= 9 
        switch (clave[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                son_todos_numericos = true;
                break;

            default:
                son_todos_numericos = false;
                break;
        }

        i++;
    }

    return son_todos_numericos;
}

bool validar(t_cadena clave)
{
    bool clave_es_valida;
    unsigned short int cantidad_caracteres_clave;
    int i;
    
    cantidad_caracteres_clave = strlen(clave);

    clave_es_valida = true;
    
    if (cantidad_caracteres_clave < 4 || cantidad_caracteres_clave > 8)
        clave_es_valida = false;
    else if(son_todos_caracteres_iguales(clave, cantidad_caracteres_clave))
        clave_es_valida = false;
    else if (!(son_todos_caracteres_numericos(clave, 
                                              cantidad_caracteres_clave)))
        clave_es_valida = false;
    
    return clave_es_valida;
}

int main()
{
    if (validar("j2020")) printf("La clave 'j2020' es válida\n"); 
    else printf("La clave 'j2020' no es válida\n");
    
    if (validar("2021a")) printf("La clave '2021a' es válida\n"); 
    else printf("La clave '2021a' no es válida\n");

    if (validar("20X21")) printf("La clave '20X21' es válida\n");
    else printf("La clave '20X21' no es válida\n");

    if (validar("2220")) printf("La clave '2220' es válida\n");
    else printf("La clave '2220' no es válida\n");

    if (validar("23445776")) printf("La clave '23445776' es válida\n");
    else printf("La clave '23445776' no es válida\n");

    if (validar("089")) printf("La clave '089' es válida\n");
    else printf("La clave '089' no es válida\n");

    if (validar("027845321")) printf("La clave '027845321' es válida\n");
    else printf("La clave '027845321' no es válida\n");

    if (validar("02784532")) printf("La clave '02784532' es válida\n");
    else printf("La clave '02784532' no es válida\n");

    if (validar("33333")) printf("La clave '33333' es válida\n");
    else printf("La clave '33333' no es válida\n");

    return 0;
}
