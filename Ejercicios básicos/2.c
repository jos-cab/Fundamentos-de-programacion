/*
2) Calcular el sueldo de un operario ingresando por teclado la cantidad de horas que trabajó en el mes 
y el valor de la hora.
Mostrarle el resultado al usuario con un mensaje adecuado.
*/

#include <stdio.h>

void main()
{
    int valor_hora, cantidad_horas, sueldo;

    printf("Ingrese el valor de cada hora: ");
    scanf("%i", &valor_hora);

    printf("Ingrese la cantidad de horas: ");
    scanf("%i", &cantidad_horas);

    sueldo = cantidad_horas * valor_hora;

    printf("El sueldo es: %i", sueldo);
}
