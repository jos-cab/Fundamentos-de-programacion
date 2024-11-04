/*
6) Ingresar tres números y hallar el mayor.
*/

#include <stdio.h>

int main()
{
    int numero_1, numero_2, numero_3;

    printf("Ingrese tres números para saber cual es mayor \n");

    printf("Primer número: ");
    scanf("%i", &numero_1);
    printf("Segundo número: ");
    scanf("%i", &numero_2);
    printf("Tercer número: ");
    scanf("%i", &numero_3);

    // Suponiendo que los 3 son distintos
    if (numero_1 > numero_2 && numero_1 > numero_3)
        printf("El primer número (%i) es mayor", numero_1);
    else if (numero_2 > numero_1 && numero_2 > numero_3)
        printf("El segundo número (%i) es mayor", numero_2);
    else
        printf("El tercer número (%i) es mayor", numero_3);
    
    return 0;
}