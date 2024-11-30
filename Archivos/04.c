/*
4) Dados dos archivos de números enteros de 5 dígitos ordenados en forma
creciente, generar un archivo que contenga todos los números, ordenado de igual
forma.

No hay números repetidos.
*/

#include <stdio.h>

/*
int main()
{
    FILE *archivo_numeros_ordenados_1, *archivo_numeros_ordenados_2, *archivo_numeros_ordenados_3;
    int numero_1, numero_2;

    archivo_numeros_ordenados_1 = fopen("./numeros.txt", "r");
    archivo_numeros_ordenados_2 = fopen("./numeros_2.txt", "r");
    archivo_numeros_ordenados_3 = fopen("./numeros_ordenados.txt", "w");

    if (archivo_numeros_ordenados_1 == NULL || archivo_numeros_ordenados_2 == NULL || archivo_numeros_ordenados_3 == NULL)
    {
        printf("Error al abrir los archivos.\n");
        return 1;
    }

    fscanf(archivo_numeros_ordenados_1, "%d", &numero_1);
    fscanf(archivo_numeros_ordenados_2, "%d", &numero_2);

    while (!feof(archivo_numeros_ordenados_1) && !feof(archivo_numeros_ordenados_2))
    {
        if (numero_1 < numero_2)
        {
            fprintf(archivo_numeros_ordenados_3, "%d\n", numero_1);
            fscanf(archivo_numeros_ordenados_1, "%d", &numero_1);
        }
        else
        {
            fprintf(archivo_numeros_ordenados_3, "%d\n", numero_2);
            fscanf(archivo_numeros_ordenados_2, "%d", &numero_2);
        }
    }

    while (!feof(archivo_numeros_ordenados_1))
    {
        fprintf(archivo_numeros_ordenados_3, "%d\n", numero_1);
        fscanf(archivo_numeros_ordenados_1, "%d", &numero_1);
    }

    while (!feof(archivo_numeros_ordenados_2))
    {
        fprintf(archivo_numeros_ordenados_3, "%d\n", numero_2);
        fscanf(archivo_numeros_ordenados_2, "%d", &numero_2);
    }

    if (numero_1 < numero_2)
    {
        fprintf(archivo_numeros_ordenados_3, "%d\n", numero_1);
        fprintf(archivo_numeros_ordenados_3, "%d\n", numero_2);
    }
    else
    {
        fprintf(archivo_numeros_ordenados_3, "%d\n", numero_2);
        fprintf(archivo_numeros_ordenados_3, "%d\n", numero_1);
    }

    fclose(archivo_numeros_ordenados_1);
    fclose(archivo_numeros_ordenados_2);
    fclose(archivo_numeros_ordenados_3);

    return 0;
}
*/

#include <stdio.h>

int main()
{
    FILE *archivo_numeros_ordenados_1, *archivo_numeros_ordenados_2, *archivo_numeros_ordenados_3;
    int numero_1, numero_2;
    int leido_1, leido_2;

    archivo_numeros_ordenados_1 = fopen("numeros.txt", "r");
    archivo_numeros_ordenados_2 = fopen("numeros_2.txt", "r");
    archivo_numeros_ordenados_3 = fopen("numeros_ordenados.txt", "w");

    leido_1 = fscanf(archivo_numeros_ordenados_1, "%d", &numero_1);
    leido_2 = fscanf(archivo_numeros_ordenados_2, "%d", &numero_2);

    // TODO: Cambiar EOF

    while (leido_1 != EOF || leido_2 != EOF)
    {
        if (leido_1 != EOF && (leido_2 == EOF || numero_1 < numero_2))
        {
            fprintf(archivo_numeros_ordenados_3, "%d\n", numero_1);
            leido_1 = fscanf(archivo_numeros_ordenados_1, "%d", &numero_1);
        }
        else if (leido_2 != EOF && (leido_1 == EOF || numero_2 < numero_1))
        {
            fprintf(archivo_numeros_ordenados_3, "%d\n", numero_2);
            leido_2 = fscanf(archivo_numeros_ordenados_2, "%d", &numero_2);
        }
    }

    fclose(archivo_numeros_ordenados_1);
    fclose(archivo_numeros_ordenados_2);
    fclose(archivo_numeros_ordenados_3);

    return 0;
}
