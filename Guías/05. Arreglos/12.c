/*
12) Se tiene un registro de la temperatura por hora (0 a 23) por día (1 a n) de
un mes, ordenada cronológicamente.

Se pide:

a) Ingresar el número de mes para conocer la cantidad de días registrados.
b) Cargar el listado en una matriz e informarla en forma bidimensional.
c) Informar además la máxima y la mínima temperatura por día, la máxima y la
mínima temperatura del mes.
*/

#include <stdio.h>

#define MF_F 24
#define MF_C 31

typedef float t_matriz[MF_F][MF_C];
typedef float t_vec[MF_C];

int calcular_cantidad_dias_mes(unsigned short mes, short año)
{
    int cantidad_dias;

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

void ingresar_datos(t_matriz matriz, int ML_F, int ML_C)
{
    int i, j;

    for (i = 0; i < ML_C; i++)
        for (j = 0; j < ML_F; j++)
        {
            printf("Día %d, hora %d: ", i + 1, j);
            scanf("%f", &matriz[j][i]);
        }
}

void encontrar_minimos_dia(t_matriz matriz, t_vec minimos, int ML_F, int ML_C)
{
    int i, j;
    float minimo;

    for (i = 0; i < ML_C; i++)
    {
        minimo = matriz[0][i];

        for (j = 1; j < ML_F; j++)
            if (matriz[j][i] < minimo)
                minimo = matriz[j][i];

        minimos[i] = minimo;
    }
}

void encontrar_maximos_dia(t_matriz matriz, t_vec maximos, int ML_F, int ML_C)
{
    int i, j;
    float maximo;

    for (i = 0; i < ML_C; i++)
    {
        maximo = matriz[0][i];

        for (j = 1; j < ML_F; j++)
            if (matriz[j][i] > maximo)
                maximo = matriz[j][i];

        maximos[i] = maximo;
    }
}

float encontrar_minimo_total(t_vec minimos, int ML_C)
{
    int i;
    float minimo;

    minimo = minimos[0];
    for (i = 1; i < ML_C; i++)
        if (minimos[i] < minimo)
            minimo = minimos[i];

    return minimo;
}

float encontrar_maximo_total(t_vec maximos, int ML_C)
{
    int i;
    float maximo;

    maximo = maximos[0];
    for (i = 1; i < ML_C; i++)
        if (maximos[i] > maximo)
            maximo = maximos[i];

    return maximo;
}

void mostrar_matriz(t_matriz matriz, int ML_F, int ML_C)
{
    int i, j;

    for (i = 0; i < ML_F; i++)
    {
        for (j = 0; j < ML_C; j++)
            printf("%.2f ", matriz[i][j]);

        printf("\n");
    }

    printf("\n");
}

void mostrar_vector(t_vec vector, int ML)
{
    int i;

    for (i = 0; i < ML; i++)
        printf("%.2f ", vector[i]);

    printf("\n");
}

int main()
{
    int ML_F, ML_C, mes, año;
    t_matriz temperaturas;
    t_vec minimos, maximos;

    ML_F = MF_F;

    printf("Ingrese año y número de mes para ingresar temperaturas\n");
    printf("Año: ");
    scanf("%d", &año);
    printf("Mes: ");
    scanf("%d", &mes);

    if (mes < 1 || mes > 12)
    {
        printf("Número de mes inválido");
    }
    else
    {
        ML_C = calcular_cantidad_dias_mes(mes, año);

        ingresar_datos(temperaturas, ML_F, ML_C);

        printf("Las temperaturas fueron: \n");
        mostrar_matriz(temperaturas, ML_F, ML_C);

        encontrar_minimos_dia(temperaturas, minimos, ML_F, ML_C);
        encontrar_maximos_dia(temperaturas, maximos, ML_F, ML_C);
        
        printf("Las temperaturas mínimas por día: \n");
        mostrar_vector(minimos, ML_C);

        printf("Las temperaturas máximas por día: \n");
        mostrar_vector(maximos, ML_C);

        printf("La temperatura mínima del mes: %.2f\n",
            encontrar_minimo_total(minimos, ML_C));

        printf("La temperatura máxima del mes: %.2f\n",
            encontrar_maximo_total(maximos, ML_C));
    }

    return 0;
}
