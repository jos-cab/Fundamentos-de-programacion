/*
12) Dados a y n números enteros, informar la potencia enésima de a por productos sucesivos.
*/

#include <stdio.h>

void main()
{
    int a, n, potencia_nesima, i, j;
    potencia_nesima = 1;

    printf("Ingrese a y n para calcular potencia enésima de a por productos sucesivos \n");

    printf("a: ");
    scanf("%i", &a);
    printf("n: ");
    scanf("%i", &n);

    for (i = 0; i < n; i++)
        potencia_nesima *= a;
    
    printf("La potencia n-esima es: %i ", potencia_nesima);
}
