/*
3) Dado un archivo de números enteros entre 0 y 255, imprimir los caracteres
correspondientes según el código ASCII.
*/

#include <stdio.h>

int main()
{
    FILE *archivo;
    char c;

    archivo = fopen("./numeros.txt", "r");

    while (!feof(archivo))
    {
        c = fgetc(archivo);

        if (0 <= c && c <= 255)
            printf("%c", c);
    }

    fclose(archivo);

    return 0;
}