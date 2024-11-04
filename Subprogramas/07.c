/*
7) Escribir una función que dado un código numérico de m dígitos,
separe un sub-código consistente en una cantidad n<m de dígitos a partir del k-ésimo lugar
a contar del dígito menos significativo.

Utilizarla en un programa que ingrese un listado de códigos numéricos junto con sus
correspondientes parámetros m,n y k y liste dichos códigos de entrada junto con el sub-código deseado.
*/

#include <stdio.h>

int contar_caracteres(int m)
{
    int i;

    i = 0;
    while (m != 0)
    {
        m /= 10;
        i++;
    }

    return i;
}

void remover_ultimos_significativos(int *m, int x)
{
    int i;

    for (i = 0; i < x; i++)
        *m /= 10;
}

void invertir_numero(int *m)
{
    int aux;
    aux = 0;

    while (*m != 0)
    {
        aux *= 10;
        aux += *m % 10;
        *m /= 10;
    }

    *m = aux;
}

int obtener_ultimos_n_significativos(int m, int n)
{
    invertir_numero(&m);
    remover_ultimos_significativos(&m, contar_caracteres(m) - n);
    invertir_numero(&m);

    return m;
}

int separar_numero(int m, int n, int k)
{
    int resultado;

    remover_ultimos_significativos(&m, k);
    resultado = obtener_ultimos_n_significativos(m, n);

    return resultado;
}

int main()
{
    printf("m = 123456789, n = 3, k = 2: %d\n", separar_numero(123456789, 3, 2));
    printf("m = 123456789, n = 2, k = 5: %d\n", separar_numero(123456789, 2, 5));
    return 0;
}
