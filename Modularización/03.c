/*
3. Escribir un programa que solicite el ingreso de valores, que representarán una cantidad de segundos.
El programa deberá informar al usuario, el equivalente en días, horas, minutos y segundos.

Se debe validar que el valor ingresado sea entero y positivo,
de lo contrario, deberá mostrarse el mensaje: “Valor ingresado inválido”.

El ingreso de valores finaliza cuando el usuario ingrese como valor, 0.
*/

#include <stdio.h>

void pedir_segundos(int *segundos)
{
    do
    {
        printf("Ingrese tiempo en segundos para calcular su equivalente en días, horas, minutos y segundos: ");
        scanf("%i", segundos);

        if (*segundos < 0)
            printf("Valor ingresado inválido\n");

    } while (*segundos < 0);
}

void calcular_tiempos(int segundos, int *resto_segundos, int *minutos, int *horas, int *dias)
{
    *dias = 0;
    *horas = 0;
    *minutos = 0;
    *resto_segundos = segundos;

    if (*resto_segundos >= 86400) // 86400s = 1 día
    {
        *dias = *resto_segundos / 86400;
        *resto_segundos -= *dias * 86400;
    }
    if (*resto_segundos >= 3600) // 3600s = 1 hora
    {
        *horas = *resto_segundos / 3600;
        *resto_segundos -= *horas * 3600;
    }
    if (*resto_segundos >= 60) // 60s = 1 minuto
    {
        *minutos = *resto_segundos / 60;
        *resto_segundos -= *minutos * 60;
    }
}

int main()
{
    int segundos, dias, horas, minutos, resto_segundos;

    do
    {
        pedir_segundos(&segundos);

        if (segundos > 0)
        {
            calcular_tiempos(segundos, &resto_segundos, &minutos, &horas, &dias);
            printf("Días: %i, horas: %i, minutos: %i, segundos: %i\n", dias, horas, minutos, resto_segundos);
        }
    } while (segundos != 0);

    return 0;
}
