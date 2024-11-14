/*
13. Escribir un programa modular en C, que solicite el ingreso de 3 oraciones,
de no más de 50 caracteres cada una.

Luego informar:
1. Cuál es la oración más larga.
2. Si hay al menos 2 oraciones iguales.
3. Solicitar el ingreso de una palabra o parte de una oración, e indicar si la
misma se encuentra en las oraciones, y en cuales.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LARGO_MAXIMO_ORACION 50

typedef char oracion_t[LARGO_MAXIMO_ORACION];

void ingresar_oracion(oracion_t oracion)
{
    printf("Ingrese una oración de no más de %hu caracteres: ", 
        LARGO_MAXIMO_ORACION);

    fgets(oracion, LARGO_MAXIMO_ORACION, stdin);
    fflush(stdin);

    oracion[strlen(oracion)-1] = '\0';
}

// Esta función puede ser luego modificada para n cantidad de oraciones
short int obtener_oracion_mas_larga(oracion_t oracion_1, 
                                    oracion_t oracion_2,
                                    oracion_t oracion_3)
{
    short int oracion_mas_larga;
    unsigned short int largo_oracion_1, largo_oracion_2, largo_oracion_3;
    
    largo_oracion_1 = strlen(oracion_1);
    largo_oracion_2 = strlen(oracion_2);
    largo_oracion_3 = strlen(oracion_3);

    if (largo_oracion_1 > largo_oracion_2 && largo_oracion_1 > largo_oracion_3)
        oracion_mas_larga = 1;
    else if (largo_oracion_2 > largo_oracion_1 && largo_oracion_2 > largo_oracion_3)
        oracion_mas_larga = 2;
    else if (largo_oracion_3 > largo_oracion_1 && largo_oracion_3 > largo_oracion_2)
        oracion_mas_larga = 3;
    else
        oracion_mas_larga = -1; // las tres son igual de largas

    return oracion_mas_larga;
}

bool hay_oraciones_iguales(oracion_t oracion_1, 
                           oracion_t oracion_2,
                           oracion_t oracion_3)
{
    bool oraciones_iguales;

    if (strcmp(oracion_1, oracion_2) == 0)
        oraciones_iguales = true;
    else if (strcmp(oracion_1, oracion_3) == 0)
        oraciones_iguales = true;
    else if (strcmp(oracion_2, oracion_3) == 0)
        oraciones_iguales = true;
    else
        oraciones_iguales = false;

    return oraciones_iguales;
}

void buscar_subcadena(oracion_t subcadena,
                      oracion_t oracion_1, 
                      oracion_t oracion_2,
                      oracion_t oracion_3)
{
    bool existe_subcadena;

    // if (subcadena in oracion_1)
    if (strcmp(strstr(subcadena, oracion_1), "") != 0)
        existe_subcadena = true;
}

int main()
{
    oracion_t oracion_1, oracion_2, oracion_3, subcadena;
    short int oracion_mas_larga;

    ingresar_oracion(oracion_1);
    ingresar_oracion(oracion_2);
    ingresar_oracion(oracion_3);

    printf("\n");

    oracion_mas_larga = obtener_oracion_mas_larga(oracion_1, 
                                                  oracion_2,
                                                  oracion_3);

    if (oracion_mas_larga == -1)
        printf("Las oraciones tienen el mismo largo\n");
    else
        printf("La oración más larga es la oración %hi\n", oracion_mas_larga);

    if(hay_oraciones_iguales(oracion_1, oracion_2, oracion_3))
        printf("Hay al menos dos oraciones iguales\n");
    else
        printf("Las tres oraciones son distintas\n");
    
    ingresar_oracion(subcadena);
    buscar_subcadena(subcadena, oracion_1, oracion_2, oracion_3);

    return 0;
}
