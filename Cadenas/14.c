/*
14. Escribir un programa que solicite el ingreso de un texto que será enviado
mediante un telegrama.

Luego de ingresado, se deberá informar la cantidad de palabras que lo componen y
el importe a abonar por el solicitante.

El texto sólo puede contener, letras, números y los siguientes signos de
puntuación: . , ; : ()

Para el cálculo de las palabras, considerar que una palabra estará separada de
otra, por uno ó más blancos.

Para el cálculo del importe a abonar, deberá considerar que cada palabra pagará
$10 por cada 3 caracteres.
Por las fracciones menores a los 3 caracteres, pagará $8.
*/

// Sacado de Modularización/05.c

#include <stdio.h>
#include <stdbool.h>

#define ML 150

typedef char string[ML];

bool validar_caracter(char x)
{
    return (
        (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') ||
        (x >= '0' && x <= '9') || (x == '.') || (x == ',') ||
        (x == ';') || (x == ':') || (x == '(') || (x == ')') || (x == ' '));
}

bool validar_telegrama(string cadena)
{
    int i;
    bool telegrama_valido;

    i = 0;
    telegrama_valido = true;

    while (cadena[i] != '\0' && telegrama_valido)
    {
        // Si un caracter es inválido el telegrama es inválido
        telegrama_valido = validar_caracter(cadena[i]);

        i++;
    }

    return telegrama_valido;
}

int contar_palabras(string cadena)
{
    int cantidad_palabras, i;
    bool caracter_espacio;

    cantidad_palabras = 0;
    caracter_espacio = false;

    i = 0;

    while (cadena[i] != '\0')
    {
        if (cadena[i] == ' ')
        {
            if (!caracter_espacio)
                cantidad_palabras++;

            caracter_espacio = true;
        }
        else
        {
            caracter_espacio = false;
        }

        i++;
    }

    // Al contar las palabras a partir de los espacios cuento n-1 palabras.
    cantidad_palabras++;

    return cantidad_palabras;
}

int calcular_aporte(string cadena)
{
    int aporte, i, j;
    aporte = 0;

    i = 0;

    while (cadena[i] != '\0')
    {
        j = 1;

        while (cadena[i + j] != '\0' && cadena[i + j] != ' ' && j < 3)
            j++;

        // Con "==" basta, pero funcionará si se pasa.
        if (j >= 3)
            aporte += 10;
        else
            aporte += 8;

        i += j;

        while (cadena[i] == ' ')
            i++;
    }

    return aporte;
}

int main()
{
    string telegrama;

    printf("Ingrese telegrama: ");
    scanf("%[^\n]", telegrama);

    if (!validar_telegrama(telegrama))
    {
        printf("El telegrama no es válido");
    }
    else
    {
        printf("La cantidad de palabras en el telegrama es: %d\n",
            contar_palabras(telegrama));

        printf("El importe a abonar es de: %d",
            calcular_aporte(telegrama));
    }

    return 0;
}
