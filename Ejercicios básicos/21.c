/*
21) Se dan como datos de entrada las fechas de nacimiento (día, mes, año)
y los números de DNI de cada integrante de un grupo.

Se indica fin de datos de entrada cuando día = 0.

Muestre por pantalla el número de DNI del integrante más joven del grupo.
*/

/*

#include <stdio.h>

// Las fechas ingresadas tienen que ser anteriores al 14/09/2024
#define DIA_ACTUAL 14
#define MES_ACTUAL 9
#define AÑO_ACTUAL 2024

void main()
{
    int dia, mes, año, dni, dni_menor, menor;
    menor = 2147483647; // Mayor entero posible para 32-bits

    do
    {
        printf("Ingrese fecha de nacimiento \n");

        printf("Día: ");
        scanf("%i", &dia);

        if (dia != 0)
        {
            printf("Mes: ");
            scanf("%i", &mes);
            printf("Año: ");
            scanf("%i", &año);

            printf("Ingrese DNI: ");
            scanf("%i", &dni);

            // Para encontrar la persona más joven, comparo cuántos días vivió cada uno
            // NOTA: es un aproximado, ya que no tuve en cuenta años bisiestos
            if ((AÑO_ACTUAL - año) * 365 + (MES_ACTUAL - mes) * 30 + (DIA_ACTUAL - dia) < menor)
                dni_menor = dni;

            printf("\n");
        }
    } while (dia != 0);

    printf("El DNI del menor es: %i", dni_menor);
}

*/
/*
#include <stdio.h>

void main() {
    int dia, mes, año, dni, dni_menor;
    dni_menor = 0;

    do
    {
        printf("Ingrese fecha de nacimiento \n");

        printf("Día: ");
        scanf("%i", &dia);

        if (dia != 0)
        {
            printf("Mes: ");
            scanf("%i", &mes);
            printf("Año: ");
            scanf("%i", &año);

            printf("Ingrese DNI: ");
            scanf("%i", &dni);

            if (dni > dni_menor)
                dni_menor = dni;

            printf("\n");
        }
    } while (dia != 0);

    printf("El DNI del menor es: %i", dni_menor);
}

*/

#include <stdio.h>
#include <stdbool.h> // Incluyo stdbool para hacer una flag y no repetir tanto código

void main()
{
    int dia, mes, año, dni, dia_menor, mes_menor, año_menor, dni_menor;
    bool es_menor;

    printf("Ingrese fechas de nacimiento y DNI para mostrar DNI del menor\n\n");

    /* Primer ingreso para establecer menor */

    printf("Ingrese fecha de nacimiento \n");
    printf("Día (0 para terminar): ");
    scanf("%d", &dia);

    if (dia != 0)
    {
        printf("Mes: ");
        scanf("%d", &mes);
        printf("Año: ");
        scanf("%d", &año);

        printf("Ingrese DNI: ");
        scanf("%i", &dni);

        dia_menor = dia;
        mes_menor = mes;
        año_menor = año;
        dni_menor = dni;

        printf("\n");
    }

    /* ------------------------------------ */

    while (dia != 0)
    {
        es_menor = false;

        printf("Ingrese fecha de nacimiento \n");

        printf("Día: ");
        scanf("%i", &dia);

        if (dia != 0)
        {
            printf("Mes: ");
            scanf("%i", &mes);
            printf("Año: ");
            scanf("%i", &año);

            printf("Ingrese DNI: ");
            scanf("%i", &dni);

            if (año > año_menor)
                es_menor = true;

            else if (año == año_menor)
                if (mes > mes_menor)
                    es_menor = true;

                else if (mes == mes_menor)
                    if (dia > dia_menor)
                        es_menor = true;

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

    printf("El DNI del menor es: %d", dni_menor);
}