/*
12. Escribir un programa modular en C, que solicite el ingreso de 1 oración, de 
no más de 100 caracteres.

Luego informar la cantidad de vocales minúsculas, no acentuadas, que hay en la
oración.
*/

#include <stdio.h>
#include <string.h>

#define LARGO_MAXIMO_ORACION 100

typedef char oracion_t[LARGO_MAXIMO_ORACION];

void ingresar_oracion(oracion_t oracion)
{
    printf("Ingrese una oración de no más de 100 caracteres: ");

    fgets(oracion, LARGO_MAXIMO_ORACION, stdin);
    fflush(stdin);

    oracion[strlen(oracion)-1] = '\0';
}

unsigned short int obtener_cantidad_vocales_minusculas_sin_acento(oracion_t oracion)
{
    unsigned short int cantidad_vocales_minusculas_sin_acento;
    char caracter_actual;
    int i;

    cantidad_vocales_minusculas_sin_acento = 0;
    i = 0;

    do
    {
        caracter_actual = oracion[i];

        switch (caracter_actual)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                cantidad_vocales_minusculas_sin_acento++;
                break;
        }

        i++;
    } while (caracter_actual != '\0');
    
    return cantidad_vocales_minusculas_sin_acento;
}

int main()
{
    oracion_t oracion;

    ingresar_oracion(oracion);

    printf("La cantidad de vocales minúsculas sin acento de la oración es: %hu",
        obtener_cantidad_vocales_minusculas_sin_acento(oracion));

    return 0;
}
