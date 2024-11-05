/*
5. Escribir una función para validar una nueva clave de acceso.

La función deberá recibir una cadena de caracteres,
que contendrá la clave candidata, que ya fue ingresada previamente por el usuario.

Devolverá true o false, dependiendo de si cumple o no, con las siguientes condiciones:
- La clave debe estar formada únicamente por, entre 6 y 12 caracteres numéricos
- La cantidad de dígitos pares debe ser mayor a la de los impares.

A los sumo debe recorrer una vez la cadena.

Evite realizar ciclos innecesarios.

Compruebe el correcto funcionamiento, incluyendo los siguientes casos de prueba:
validar("j20893") devuevle false
validar("20893a") devuevle false
validar("208X930") devuevle false
validar("20201") devuelve false
validar("23445776") devuelve false
validar("089010") devuelve true
validar("02784532132567") devuelve false
validar("027845320011") devuelve true
*/


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 32

typedef char t_cadena[MAX];

void obtener_cantidad_digitos_pares_e_impares(t_cadena cadena, 
                                unsigned short int cantidad_caracteres_cadena, 
                                unsigned short int *cantidad_digitos_pares, 
                                unsigned short int *cantidad_digitos_impares, 
                                bool *clave_es_valida)
{
    int i;

    *cantidad_digitos_pares = 0;
    *cantidad_digitos_impares = 0;

    i = 0;

    while (*clave_es_valida && i < cantidad_caracteres_cadena)
    {
        switch (cadena[i])
        {
            case '0':
            case '2':
            case '4':
            case '6':
            case '8':
                (*cantidad_digitos_pares)++;
                break;

            case '1':
            case '3':
            case '5':
            case '7':
            case '9':
                (*cantidad_digitos_impares)++;
                break;
            
            default:
                *clave_es_valida = false;
                break;
        }

        i++;
    }
}

bool validar(t_cadena clave)
{
    bool clave_es_valida;
    unsigned short int cantidad_caracteres_clave;
    unsigned short int cantidad_digitos_pares;
    unsigned short int cantidad_digitos_impares;

    clave_es_valida = true;
    cantidad_caracteres_clave = strlen(clave);

    if ((cantidad_caracteres_clave < 6) ||
        (cantidad_caracteres_clave > 12))
        clave_es_valida = false;
    else
    {
        obtener_cantidad_digitos_pares_e_impares(clave,
                                                 cantidad_caracteres_clave, 
                                                 &cantidad_digitos_pares, 
                                                 &cantidad_digitos_impares, 
                                                 &clave_es_valida);

        if (clave_es_valida && 
            (cantidad_digitos_impares >= cantidad_digitos_pares))
            clave_es_valida = false;
    }

    return clave_es_valida;
}


int main()
{
    if (validar("j20893")) printf("La clave 'j20893' es válida\n"); 
    else printf("La clave 'j20893' no es válida\n");
    
    if (validar("20893a")) printf("La clave '20893a' es válida\n"); 
    else printf("La clave '20893a' no es válida\n");

    if (validar("208X930")) printf("La clave '208X930' es válida\n");
    else printf("La clave '208X930' no es válida\n");

    if (validar("20201")) printf("La clave '20201' es válida\n");
    else printf("La clave '20201' no es válida\n");

    if (validar("23445776")) printf("La clave '23445776' es válida\n");
    else printf("La clave '23445776' no es válida\n");

    if (validar("089010")) printf("La clave '089010' es válida\n");
    else printf("La clave '089010' no es válida\n");

    if (validar("02784532132567")) printf("La clave '02784532132567' es válida\n");
    else printf("La clave '02784532132567' no es válida\n");

    if (validar("027845320011")) printf("La clave '027845320011' es válida\n");
    else printf("La clave '027845320011' no es válida\n");

    return 0;
}
