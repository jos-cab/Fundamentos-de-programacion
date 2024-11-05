/*
21) Se dan como datos de entrada las fechas de nacimiento (día, mes, año)
y los números de DNI de cada integrante de un grupo.

Se indica fin de datos de entrada cuando día = 0.

Muestre por pantalla el número de DNI del integrante más joven del grupo.
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    unsigned short int dia, mes, dia_menor, mes_menor;
    short int año, año_menor;
    unsigned int dni, dni_menor;
    bool es_menor;

    printf("Ingrese fechas de nacimiento y DNI para mostrar DNI del menor\n\n");

    /* Primer ingreso para establecer menor */

    printf("Ingrese fecha de nacimiento \n");
    printf("Día (0 para terminar): ");
    scanf("%hu", &dia);

    if (dia != 0)
    {
        printf("Mes: ");
        scanf("%hu", &mes);
        printf("Año: ");
        scanf("%hi", &año);

        printf("Ingrese DNI: ");
        scanf("%u", &dni);

        dia_menor = dia;
        mes_menor = mes;
        año_menor = año;
        dni_menor = dni;

        printf("\n");
    } else 
        dni_menor = 0;

    /* Ingreso los datos de los ingresantes y calculo el menor del grupo */

    while (dia != 0)
    {
        es_menor = false;

        printf("Ingrese fecha de nacimiento \n");

        printf("Día: ");
        scanf("%hu", &dia);

        if (dia != 0)
        {
            printf("Mes: ");
            scanf("%hu", &mes);
            printf("Año: ");
            scanf("%hi", &año);

            printf("Ingrese DNI: ");
            scanf("%u", &dni);

            es_menor = (año > año_menor) || 
                    (año == año_menor && mes > mes_menor) || 
                    (año == año_menor && mes == mes_menor && dia > dia_menor);

            if (es_menor)
            {
                dia_menor = dia;
                mes_menor = mes;
                año_menor = año;
                dni_menor = dni;
            }

            printf("\n");
        }
    }

    printf("El DNI del menor es: %u", dni_menor);

    return 0;
}