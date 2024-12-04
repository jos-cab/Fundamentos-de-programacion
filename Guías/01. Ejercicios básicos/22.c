/*
22) Se tiene un listado de alumnos que consiste en número de padrón y 4 notas
por alumno.

Informar el mayor y el menor promedio registrado junto con el número de padrón
del alumno, suponiendo que ambos son únicos.
*/

#include <stdio.h>

#define CANTIDAD_NOTAS 4
#define NOTA_MINIMA 0
#define NOTA_MAXIMA 10

int main()
{
    unsigned int padron_menor_promedio, padron_mayor_promedio, padron;
    unsigned short int nota;
    int i;
    float mayor_promedio, menor_promedio, promedio;
    char desea_continuar;

    mayor_promedio = NOTA_MINIMA;
    menor_promedio = NOTA_MAXIMA;

    do
    {
        promedio = 0;

        printf("Ingrese el número de padrón: ");
        scanf("%u", &padron);

        // Calculo promedio
        for (i = 0; i < CANTIDAD_NOTAS; i++)
        {
            do
            {
                printf("Ingrese nota %i: ", i+1);
                scanf("%hu", &nota);
            } while (nota < NOTA_MINIMA || nota > NOTA_MAXIMA);
            
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
    

    printf("%u tiene el mayor promedio: %.2g \n", 
        padron_mayor_promedio, mayor_promedio);
        
    printf("%u tiene el menor promedio: %.2g \n",
        padron_menor_promedio, menor_promedio);

    return 0;
}
