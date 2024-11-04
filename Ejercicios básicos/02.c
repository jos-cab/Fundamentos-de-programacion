/*
2) Calcular el sueldo de un operario ingresando por teclado la cantidad de horas que trabajó en el mes 
y el valor de la hora.
Mostrarle el resultado al usuario con un mensaje adecuado.
*/

#include <stdio.h>

int main()
{
    unsigned int valor_hora, cantidad_horas;
    unsigned long int sueldo;

    printf("Ingrese el valor de cada hora: ");
    scanf("%u", &valor_hora);

    printf("Ingrese la cantidad de horas: ");
    scanf("%u", &cantidad_horas);

    sueldo = cantidad_horas * valor_hora;

    printf("El sueldo es: %lu", sueldo);

    return 0;
}
