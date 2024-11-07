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
