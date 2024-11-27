/*
2) Dado un archivo de números enteros, generar otro archivo que contenga
aquellos que son primos en el primero.
*/

#include <stdio.h>
#include <stdbool.h>

bool es_primo(int numero)
{
    int i;
    bool primo;

    primo = true;

    i = 2;
    while ((i < numero) && (primo))
    {
        if (numero % i == 0)
            primo = false;
        else
            i++;
    }

    return primo;
}

int main()
{
    FILE *archivo_numeros, *archivo_primos;
    int numero;

    archivo_numeros = fopen("./numeros.txt", "r");
    archivo_primos = fopen("./primos.txt", "w");

    while (!feof(archivo_numeros))
    {
        fscanf(archivo_numeros, "%d", &numero);

        if (es_primo(numero))
            fprintf(archivo_primos, "%d\n", numero);
    }

    fclose(archivo_numeros);
    fclose(archivo_primos);

    return 0;
}
