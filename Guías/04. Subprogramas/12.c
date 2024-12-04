/*
12) Dadas 2 fechas, informar cuál es la fecha anterior. Los datos se dan según
los siguientes casos:
a) Cada fecha consiste en 3 números, día, mes y año.
b) Cada fecha consiste en un único número en formato aammdd.
c) Cada fecha consiste en un único número en formato ddmmaa.
Puede darse el caso que las fechas sean iguales.
*/

#include <stdio.h>

#define MF 3

typedef int fecha[MF];

void leer_formato(char *formato)
{
    do
    {
        printf("Ingrese el formato de las fechas:\n");
        printf("a) 3 números, día, mes y año.\n");
        printf("b) Un único número en formato aammdd.\n");
        printf("c) Un único número en formato ddmmaa.\n");

        printf("formato> ");
        scanf("%c", formato);

        printf("\n");
    } while (*formato != 'a' && *formato != 'b' && *formato != 'c');
}

void leer_fechas(fecha fecha_1, fecha fecha_2)
{
    char formato;
    int aux;

    leer_formato(&formato);

    if (formato == 'a')
    {
        printf("Ingrese primera fecha: \n");
        printf("Dia: ");
        scanf("%d", &fecha_1[0]);
        printf("Mes: ");
        scanf("%d", &fecha_1[1]);
        printf("Año: ");
        scanf("%d", &fecha_1[2]);

        printf("Ingrese segunda fecha: \n");
        printf("Dia: ");
        scanf("%d", &fecha_2[0]);
        printf("Mes: ");
        scanf("%d", &fecha_2[1]);
        printf("Año: ");
        scanf("%d", &fecha_2[2]);
    }
    else // formato == 'b' || formato == 'c'
    {
        printf("Ingrese primera fecha: ");
        scanf("%d", &fecha_1[0]);

        printf("Ingrese segunda fecha: ");
        scanf("%d", &fecha_2[0]);

        fecha_1[1] = (fecha_1[0] % 10000) / 100;
        fecha_1[2] = fecha_1[0] % 100;
        fecha_1[0] /= 10000;

        fecha_2[1] = (fecha_2[0] % 10000) / 100;
        fecha_2[2] = fecha_2[0] % 100;
        fecha_2[0] /= 10000;

        if (formato == 'b') // paso caso b a ddmmaa
        {
            aux = fecha_1[0];
            fecha_1[0] = fecha_1[2];
            fecha_1[2] = aux;

            aux = fecha_2[0];
            fecha_2[0] = fecha_2[2];
            fecha_2[2] = aux;
        }
    }
}

int obtener_fecha_anterior(fecha fecha_1, fecha fecha_2)
{
    int anterior;

    if (fecha_1[2] == fecha_2[2])

        if (fecha_1[1] == fecha_2[1])
            if (fecha_1[0] == fecha_2[0])
                anterior = 0;
            else if (fecha_1[0] < fecha_1[0])
                anterior = 1;
            else
                anterior = 2;
        else if (fecha_1[1] < fecha_2[1])
            anterior = 1;
        else
            anterior = 2;

    else if (fecha_1[2] < fecha_2[2])
        anterior = 1;
    else
        anterior = 2;

    return anterior;
}

void mostrar_fecha(fecha fecha)
{
    int i;

    for (i = 0; i < MF; i++)
    {
        printf("%d", fecha[i]);

        if (i < MF - 1)
            printf("/");
    }
}

int main()
{
    fecha fecha_1, fecha_2;

    leer_fechas(fecha_1, fecha_2);

    switch (obtener_fecha_anterior(fecha_1, fecha_2))
    {
    case 1:
        printf("La fecha anterior de las dos es: ");
        mostrar_fecha(fecha_1);
        break;
    case 2:
        printf("La fecha anterior de las dos es: ");
        mostrar_fecha(fecha_2);
        break;

    default:
        printf("Las fechas son iguales");
        break;
    }

    return 0;
}