/*
7) Ingresar un número (del 1 al 7) que representa un día de la semana,
escribir el nombre del día correspondiente.
En el caso de haber ingresado un número fuera de rango indicarle del error al usuario.
*/

#include <stdio.h>

int main()
{
    unsigned short int dia;

    printf("Ingrese un número para saber el día de la semana: ");
    scanf("%hu", &dia);

    switch (dia)
    {
        case 1: printf("Lunes"); break;
        case 2: printf("Martes"); break;
        case 3: printf("Miércoles"); break;
        case 4: printf("Jueves"); break;
        case 5: printf("Viernes"); break;
        case 6: printf("Sábado"); break;
        case 7: printf("Domingo"); break;
        default: printf("Número de día inválido"); break;
    }

    return 0;
}