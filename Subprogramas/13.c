/*
13) Dada una fecha en formato aammdd, verificar si es correcta.

Si lo es, informarla según dd de cccc de 19aa.
Si no lo es, informar un mensaje de error.

cccc es la cadena de caracteres correspondiente al mes mm.
*/

#include <stdio.h>
#include <stdbool.h>

void ingresar_fecha(int *fecha)
{
    printf("Ingrese una fecha (aammdd): ");
    scanf("%d", fecha);
}

int obtener_año(int fecha)
{
    return fecha / 10000;
}

int obtener_mes(int fecha)
{
    return (fecha % 10000) / 100;
}

int obtener_dia(int fecha)
{
    return fecha % 100;
}

bool validar_fecha(int fecha)
{
    int dia, mes, año;
    bool fecha_es_valida;

    fecha_es_valida = false;

    año = obtener_año(fecha);
    mes = obtener_mes(fecha);
    dia = obtener_dia(fecha);

    if (99999 < fecha < 1000000 && 1 <= mes <= 12)
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
                else if (dia >= 1 && dia <= 28)
                    fecha_es_valida = true;

            break;
        }

    return fecha_es_valida;
}

void imprimir_mes(int mes)
{
    switch (mes)
    {
    case 1:
        printf("enero");
        break;
    case 2:
        printf("febrero");
        break;
    case 3:
        printf("marzo");
        break;
    case 4:
        printf("abril");
        break;
    case 5:
        printf("mayo");
        break;
    case 6:
        printf("junio");
        break;
    case 7:
        printf("julio");
        break;
    case 8:
        printf("agosto");
        break;
    case 9:
        printf("septiembre");
        break;
    case 10:
        printf("octubre");
        break;
    case 11:
        printf("noviembre");
        break;
    case 12:
        printf("diciembre");
        break;
    }
}

int main()
{
    int fecha;

    ingresar_fecha(&fecha);

    if (validar_fecha(fecha))
    {
        printf("La fecha es %d del mes ", obtener_dia(fecha));
        imprimir_mes(obtener_mes(fecha));
        printf(" de 19%d", obtener_año(fecha));
    }
    else
    {
        printf("La fecha no es válida");
    }

    return 0;
}
