/*
12) Dados a y n números enteros, informar la potencia enésima de a por productos sucesivos.
*/

#include <stdio.h>

int main()
{
    int a, n, i, j;
    unsigned long int potencia_nesima;

    potencia_nesima = 1;

    printf("Ingrese a y n para calcular potencia enésima de a por productos sucesivos \n");

    printf("a: ");
    scanf("%i", &a);
    printf("n: ");
    scanf("%i", &n);

    for (i = 0; i < n; i++)
        potencia_nesima *= a;
    
    printf("La potencia n-esima es: %lu ", potencia_nesima);

    return 0;
}
