/*
11) Dado un número n, informar los n primeros términos de la sucesión geométrica
de razón 3 (1, 3, 9, 27, etc.).
*/

#include <stdio.h>

int main()
{
    // Puede ser unsigned short int o size_t para la variable i,
    // pero para este curso siempre le asignaré tipo int
    int i; 
    unsigned int n;
    unsigned long int termino;

    termino = 1;

    printf("Ingrese n para calcular sucesión geométrica de razón 3: ");
    scanf("%u", &n);

    for (i = 0; i < n; i++)
    {
        printf("%lu ", termino);
        
        termino *= 3;
    }

    return 0;
}