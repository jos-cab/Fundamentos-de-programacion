/*
1) Hallar la superficie de un triángulo conociendo la base y la altura.
Solicitarle los datos de entrada al usuario.
*/

#include <stdio.h>

void main()
{
    int base, altura, superficie;

    printf("Ingrese la base: ");
    scanf("%i", &base);

    printf("Ingrese la altura: ");
    scanf("%i", &altura);

    superficie = (base * altura) / 2;

    printf("La superficie es: %i", superficie);
}