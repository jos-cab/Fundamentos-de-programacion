/*
22) Se tiene un listado de alumnos que consiste en número de padrón y 4 notas por alumno.
Informar el mayor y el menor promedio registrado junto con el número de padrón del alumno,
suponiendo que ambos son únicos.
*/

#include <stdio.h>

#define CANTIDAD_NOTAS 4

void main()
{
    int padron_menor_promedio, padron_mayor_promedio, padron, nota, i;
    float mayor_promedio, menor_promedio, promedio;
    char desea_continuar;
    mayor_promedio = 0;
    menor_promedio = 10; // Supongo que el mayor promedio posible es 10

    do
    {
        promedio = 0;

        printf("Ingrese el número de padrón: ");
        scanf("%i", &padron);

        // Calculo promedio
        for (i = 0; i < CANTIDAD_NOTAS; i++)
        {
            printf("Ingrese nota %i: ", i+1);
            scanf("%i", &nota);
            promedio += nota;
        }

        promedio /= CANTIDAD_NOTAS;

        // Verifico si el promedio es mayor o menor, y de ser así lo guardo
        if (promedio > mayor_promedio)
        {
            mayor_promedio = promedio;
            padron_mayor_promedio = padron;
        }

        if (promedio < menor_promedio)
        {
            menor_promedio = promedio;
            padron_menor_promedio = padron;
        }
        
        // Pregunto si desea continuar
        do
        {
            printf("Desea continuar? (s/n): ");
            scanf(" %c", &desea_continuar);
        } while (desea_continuar != 's' && desea_continuar != 'n');
    } while (desea_continuar == 's');
    

    printf("%i tiene el mayor promedio: %.2f \n", padron_mayor_promedio, mayor_promedio);
    printf("%i tiene el menor promedio: %.2f \n", padron_menor_promedio, menor_promedio);
}
