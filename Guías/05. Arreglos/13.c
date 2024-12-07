/*
13) Se tiene un listado con los siguientes datos:
número de alumno ( 1 a n ) ,
número de materia ( 1 a m ),
nota ( 0 a 10 ).

a) El mismo número de alumno y de materia puede aparecer más de una vez.
b) El listado no está ordenado, ni necesariamente completo.
Esto último quiere decir que puede ser que un alumno no haya cursado una o más
materias, y por lo tanto no existan los datos correspondientes en el listado.

Se pide:
.(1) Crear una estructura bidimensional que almacene el promedio por materia de
cada alumno e informarla asignándole en la impresión un guión al caso de falta
de datos mencionado.
.(2) Informar el porcentaje de alumnos que cursó cada materia y
el promedio general por materia considerando los alumnos que la cursaron.
.(3) Informar la cantidad de materias que cursó cada alumno y el promedio que
obtuvo considerando las materias que cursó.
*/

#include <stdio.h>

#define MF_ALUMNOS 4  // n
#define MF_MATERIAS 4 // m
#define MF_NOTAS 3

#define NO_CURSADA -1

typedef int t_matriz_notas[MF_ALUMNOS][MF_MATERIAS][MF_NOTAS];
typedef float t_matriz_promedios[MF_ALUMNOS][MF_MATERIAS];
typedef float t_promedios[MF_MATERIAS];
typedef int t_materias_cursadas[MF_ALUMNOS];

void calcular_promedios(t_matriz_notas notas, t_matriz_promedios promedios)
{
    int i, j, k;
    float promedio;

    for (i = 0; i < MF_ALUMNOS; i++)
        for (j = 0; j < MF_MATERIAS; j++)
        {
            if (notas[i][j][0] != NO_CURSADA)
            {
                promedio = 0;

                for (k = 0; k < MF_NOTAS; k++)
                    promedio += notas[i][j][k];

                // Supongo que terminó la cursada y se tienen todas las notas
                promedio /= MF_NOTAS;
            }
            else
                promedio = NO_CURSADA;

            promedios[i][j] = promedio;
        }
}

void mostrar_matriz(t_matriz_promedios promedios)
{
    int i, j;

    for (i = 0; i < MF_ALUMNOS; i++)
    {
        for (j = 0; j < MF_MATERIAS; j++)
            if (promedios[i][j] == NO_CURSADA)
                printf("    - ");
            else
                printf("%5.2g ", promedios[i][j]);

        printf("\n");
    }
}

void calcular_procentajes_cursada_materias(t_matriz_promedios promedios,
                                           t_promedios procentajes_cursada_materias)
{
    int i, j;
    float porcentaje;

    for (i = 0; i < MF_MATERIAS; i++)
    {
        porcentaje = 0;

        for (j = 0; j < MF_ALUMNOS; j++)
            if (promedios[j][i] != NO_CURSADA)
                porcentaje++;

        porcentaje /= MF_ALUMNOS;
        porcentaje *= 100;

        procentajes_cursada_materias[i] = porcentaje;
    }
}

void mostrar_porcentajes(t_promedios porcentajes)
{
    int i;

    for (i = 0; i < MF_MATERIAS; i++)
        printf("%5.3g%%", porcentajes[i]);
}

void mostrar_promedios_materias(t_promedios promedios)
{
    int i;

    for (i = 0; i < MF_MATERIAS; i++)
        if (promedios[i] == NO_CURSADA)
            printf("    - ");
        else
            printf("%5.3g", promedios[i]);
}

void mostrar_promedios_alumnos(t_promedios promedios)
{
    int i;

    for (i = 0; i < MF_ALUMNOS; i++)
        if (promedios[i] == NO_CURSADA)
            printf("    - ");
        else
            printf("%5.3g", promedios[i]);
}

void calcular_promedios_generales_materias(t_matriz_promedios promedios,
                                           t_promedios porcentajes,
                                           t_promedios promedios_generales_materias)
{
    int i, j;
    int cantidad_cursados;
    float promedio;

    for (i = 0; i < MF_MATERIAS; i++)
    {
        cantidad_cursados = MF_ALUMNOS * (porcentajes[i] / 100);
        promedio = 0;

        for (j = 0; j < MF_ALUMNOS; j++)
            if (promedios[j][i] != NO_CURSADA)
                promedio += promedios[j][i];

        if (cantidad_cursados > 0)
            promedio /= cantidad_cursados;
        else
            promedio = NO_CURSADA;

        promedios_generales_materias[i] = promedio;
    }
}

void calcular_cantidad_materias_cursadas_alumnos(t_matriz_promedios promedios,
                                                 t_materias_cursadas cantidad_materias_cursadas_alumnos)
{
    int i, j;

    for (i = 0; i < MF_ALUMNOS; i++)
    {
        int cantidad_materias_cursadas = 0;

        for (j = 0; j < MF_MATERIAS; j++)
            if (promedios[i][j] != NO_CURSADA)
                cantidad_materias_cursadas++;

        cantidad_materias_cursadas_alumnos[i] = cantidad_materias_cursadas;
    }
}

void calcular_promedios_alumnos(t_matriz_promedios promedios,
                                t_materias_cursadas cantidad_materias_cursadas_alumnos,
                                t_promedios promedios_alumnos)
{
    int i, j;
    float promedio;

    for (i = 0; i < MF_ALUMNOS; i++)
    {
        promedio = 0;

        for (j = 0; j < MF_MATERIAS; j++)
            if (promedios[i][j] != NO_CURSADA)
                promedio += promedios[i][j];

        if (cantidad_materias_cursadas_alumnos[i] > 0)
            promedio /= cantidad_materias_cursadas_alumnos[i];
        else
            promedio = NO_CURSADA;

        promedios_alumnos[i] = promedio;
    }
}

void mostrar_cantidad_materias_cursadas_alumno(
    t_materias_cursadas cantidad_materias_cursadas_alumnos)
{
    int i;

    for (i = 0; i < MF_ALUMNOS; i++)
        if (cantidad_materias_cursadas_alumnos[i] == NO_CURSADA)
            printf("    - ");
        else
            printf("%4d ", cantidad_materias_cursadas_alumnos[i]);
}

int main()
{
    t_matriz_notas notas = {
        // alumno_n: materia -> vector_notas
        {{8, 9, 5}, {3, 6, 7}, {NO_CURSADA}, {NO_CURSADA}},
        {{2, 5, 4}, {3, 7, 2}, {9, 8, 4}, {NO_CURSADA}},
        {{10, 3, 5}, {NO_CURSADA}, {NO_CURSADA}, {NO_CURSADA}},
        {{NO_CURSADA}, {NO_CURSADA}, {NO_CURSADA}, {NO_CURSADA}},
    };
    t_matriz_promedios promedios;
    t_promedios procentajes_cursada_materias;
    t_promedios promedios_generales_materias;
    t_materias_cursadas cantidad_materias_cursadas_alumnos;
    t_promedios promedios_alumnos;

    calcular_promedios(notas, promedios);

    printf("Filas: alumnos, columnas: materias\n");
    printf("Promedios:\n");
    mostrar_matriz(promedios);

    printf("\n");

    calcular_procentajes_cursada_materias(promedios,
                                          procentajes_cursada_materias);

    printf("Porcentajes de alumnos que cursaron cada materia:\n");
    mostrar_porcentajes(procentajes_cursada_materias);

    printf("\n\n");

    calcular_promedios_generales_materias(promedios,
                                          procentajes_cursada_materias,
                                          promedios_generales_materias);

    printf("Promedios generales por materia:\n");
    mostrar_promedios_materias(promedios_generales_materias);

    printf("\n\n");

    calcular_cantidad_materias_cursadas_alumnos(promedios,
                                                cantidad_materias_cursadas_alumnos);

    printf("Cantidad de materias cursadas por alumno:\n");
    mostrar_cantidad_materias_cursadas_alumno(
        cantidad_materias_cursadas_alumnos);

    printf("\n\n");

    calcular_promedios_alumnos(promedios,
                               cantidad_materias_cursadas_alumnos,
                               promedios_alumnos);

    printf("Promedio de materias cursadas por alumno:\n");
    mostrar_promedios_alumnos(promedios_alumnos);

    return 0;
}