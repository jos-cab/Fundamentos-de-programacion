/*
1) Hallar la superficie de un triángulo conociendo la base y la altura.
Solicitarle los datos de entrada al usuario.
*/

#include <stdio.h>

int main()
{
    unsigned int base, altura;
    double superficie;

    printf("Ingrese la base: ");
    scanf("%u", &base);

    printf("Ingrese la altura: ");
    scanf("%u", &altura);

    superficie = (double)(base * altura) / 2;

    printf("La superficie es: %.2g", superficie);

    return 0;
}