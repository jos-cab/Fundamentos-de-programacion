/*
1. Escribir una función que reciba un mes y un año; y devuelva la cantidad de
días del mes, considerando los años bisiestos.

Tenga en cuenta que un año bisiesto es aquel divisible por 4, salvo que sea
divisible por 100, en cuyo caso también debe ser divisible por 400.
*/

#include <stdio.h>

unsigned short int calcular_cantidad_dias_mes(unsigned short int mes,
                                              short int año)
{
    unsigned short int cantidad_dias;

    switch (mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cantidad_dias = 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            cantidad_dias = 30;
            break;
    
        case 2:
            // Si el año es bisiesto la cantidad de días de febrero es 29

            if ((año % 4 == 0 && año % 100 != 0) || (año % 400 == 0))
                cantidad_dias = 29;
            else
                cantidad_dias = 28;
            
            break;
    
        default:
            cantidad_dias = 0;
            break;
    }

    return cantidad_dias;
}

int main()
{
    printf("La cantidad de días del mes 1 de 2024: %hu\n", 
        calcular_cantidad_dias_mes(1, 2024));

    printf("La cantidad de días del mes 2 de 2024: %hu\n",
        calcular_cantidad_dias_mes(2, 2024));

    printf("La cantidad de días del mes 2 de 2023: %hu\n",
        calcular_cantidad_dias_mes(2, 2023));

    printf("La cantidad de días del mes 4 de 2024: %hu\n",
        calcular_cantidad_dias_mes(4, 2024));

    printf("La cantidad de días del mes '13' de 2024: %hu\n",
        calcular_cantidad_dias_mes(13, 2024));
    
    return 0;
}
