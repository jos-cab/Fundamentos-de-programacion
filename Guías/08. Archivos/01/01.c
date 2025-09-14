/*
1) Dado un archivo de números enteros mayores o iguales que 0, generar otro
archivo que almacene los factoriales de cada número del registro correspondiente
del archivo de entrada.
*/

#include <stdio.h>

long long obtener_factorial(int numero)
{
    long long factorial;
    int i;

    factorial = 1;

    for (int i = 2; i <= numero; i++)
        factorial *= i;

    return factorial;
}

int main()
{
    FILE *archivo_numeros, *archivo_factoriales;
    int numero;
    long long factorial;

    archivo_numeros = fopen("./numeros.txt", "r");
    archivo_factoriales = fopen("./factoriales.txt", "w");

    while (!feof(archivo_numeros))
    {
        fscanf(archivo_numeros, "%d", &numero);
        factorial = obtener_factorial(numero);
        fprintf(archivo_factoriales, "%lld\n", factorial);
    }

    fclose(archivo_numeros);
    fclose(archivo_factoriales);

    return 0;
}
