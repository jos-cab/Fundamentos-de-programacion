/*
11) Dado un número n, informar los n primeros términos de la sucesión geométrica de razón 3 (1, 3, 9, 27, etc.).
*/

#include <stdio.h>

void main()
{
    int n, i, j, termino;
    termino = 1;

    printf("Ingrese n para calcular sucesión geométrica de razón 3: ");
    scanf("%i", &n);

    for (i = 0; i < n; i++)
    {
        printf("%i ", termino);
        
        termino *= 3;
    }
}