/*
10) Dada una fecha con año, mes y día, informar si es correcta o no.
Solicitarle los datos al usuario de forma independiente.
Considerar años bisiestos.
*/

#include <stdio.h>
#include <stdbool.h>

void main()
{
    int dia, mes, año;
    bool fecha_es_valida;
    fecha_es_valida = false;

    printf("Ingrese una fecha para validarla \n");

    printf("Día: ");
    scanf("%i", &dia);
    printf("Mes: ");
    scanf("%i", &mes);
    printf("Año: ");
    scanf("%i", &año);

    switch (mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (dia >= 1 && dia <= 31)
                fecha_es_valida = true;

            break;
        
        case 4:
        case 6:
        case 9:
        case 11:
            if (dia >= 1 && dia <= 30)
                fecha_es_valida = true;
                
            break;
        
        case 2:
            // año bisiesto
            if ((año % 4 == 0 && año % 100 != 0) || (año % 400 == 0))
                if (dia >= 1 && dia <= 29)
                    fecha_es_valida = true;

            // año no bisiesto
            else
                if (dia >= 1 && dia <= 28)
                    fecha_es_valida = true;
            
            break;
    }

    if (fecha_es_valida)
        printf("La fecha es válida");
    else
        printf("La fecha no es válida");
}