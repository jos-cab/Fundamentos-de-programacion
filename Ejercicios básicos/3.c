/*
3) Ingresar el radio de una esfera y calcular el volumen.
*/

#include <stdio.h>

#define PI 3.1415

void main()
{
    float radio, volumen;

    printf("Ingrese el radio de una esfera para calcular su volumen: ");
    scanf("%f", &radio);

    volumen = PI * radio * radio;

    printf("El volumen de la esfera es: %f", volumen);
}

