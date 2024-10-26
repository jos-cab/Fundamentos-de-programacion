/*
8) Ingresar un número (del 1 al 12) que representa un mes, 
indicar la cantidad de días de dicho mes.
*/

#include <stdio.h>

void main()
{
    int mes;

    printf("Ingrese un número para saber la cantidad de días del mes: ");
    scanf("%i", &mes);

    switch (mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("Este més tiene 31 días");
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            printf("Este més tiene 30 días");
            break;
        
        case 2:
            printf("Este més tiene 28/29 días");
            break;
        
        default:
            printf("Número de mes inválido");
            break;
    }
}