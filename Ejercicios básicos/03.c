/*
3) Ingresar el radio de una esfera y calcular el volumen.
*/

#include <stdio.h>

#define PI 3.1415

int main()
{
    float radio;
    double volumen;

    printf("Ingrese el radio de una esfera para calcular su volumen: ");
    scanf("%f", &radio);

    // 4/3 * PI * radio ^ 3
    volumen = (4 * PI * radio * radio * radio) / 3;

    printf("El volumen de la esfera es: %.2g", volumen);

    return 0;
}

