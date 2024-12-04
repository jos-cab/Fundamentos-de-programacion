/*
5) Dado un archivo de apellidos y nombres, generar otro archivo con los
mismos datos ordenados alfabéticamente.

Suponer que el archivo de entrada cabe en memoria.
*/

#include <stdio.h>
#include <string.h>

#define MAX 100
#define ARCHIVO_NOMBRES "./nombres.txt"
#define ARCHIVO_NOMBRES_ORDENADOS "./nombres_ordenados.txt"

typedef char t_cadena[MAX];
typedef t_cadena t_nombres[MAX];

void leer_nombres(FILE *archivo, t_nombres nombres, int *ML)
{
    int i;

    archivo = fopen(ARCHIVO_NOMBRES, "r");
    i = 0;

    while (!feof(archivo))
    {
        fgets(nombres[i], MAX, archivo);
        i++;
    }

    *ML = i;

    fclose(archivo);
}

void ordenar_nombres(t_nombres nombres, int ML)
{
    int i, j;
    t_cadena temp;

    for (i = 0; i < ML - 1; i++)
        for (j = 0; j < ML - 1 - i; j++)
            if (strcmp(nombres[j], nombres[j + 1]) > 0)
            {
                strcpy(temp, nombres[j]);
                strcpy(nombres[j], nombres[j + 1]);
                strcpy(nombres[j + 1], temp);
            }
}

void guardar_nombres(FILE *archivo, t_nombres nombres, int ML)
{
    int i;

    archivo = fopen(ARCHIVO_NOMBRES_ORDENADOS, "w");

    for (i = 0; i < ML; i++)
        fprintf(archivo, "%s", nombres[i]);

    fclose(archivo);
}

int main()
{
    FILE *archivo_nombres, *archivo_nombres_ordenados;
    t_nombres nombres;
    int ML;

    leer_nombres(archivo_nombres, nombres, &ML);
    ordenar_nombres(nombres, ML);
    guardar_nombres(archivo_nombres_ordenados, nombres, ML);

    return 0;
}
