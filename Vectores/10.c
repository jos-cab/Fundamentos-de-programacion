/*
10) Escribir un programa que cargue 2 (dos) matrices y sus dimensiones, las
multiplique en caso de ser posible o devuelva una señal si la operación no
puede realizarse.
*/

#include <stdio.h>

#define MF_F 3
#define MF_C 3

typedef int t_matriz[MF_F][MF_C];

void vaciar_matriz(t_matriz matriz)
{
    int i, j;

    for (i = 0; i < MF_F; i++)
        for (j = 0; j < MF_C; j++)
            matriz[i][j] = 0;
}

void mostrar_matriz(t_matriz matriz, int ML_F, int ML_C)
{
    int i, j;

    for (i = 0; i < ML_F; i++)
    {
        for (j = 0; j < ML_C; j++)
            printf("%d ", matriz[i][j]);

        printf("\n");
    }

    printf("\n");
}

void multiplicar_matrices(t_matriz matriz_1, t_matriz matriz_2, t_matriz resultado, int ML_F1, int ML_C1, int ML_F2, int ML_C2)
{
    int i, j, k;

    if (ML_C1 != ML_F2)
        printf("No se pueden multiplicar las matrices");
    else
        for (i = 0; i < ML_F1; i++)
            for (j = 0; j < ML_C2; j++)
                for (k = 0; k < ML_C1; k++)
                    resultado[i][j] += matriz_1[i][k] * matriz_2[k][j];
}

int main()
{
    int ML_F1, ML_C1, ML_F2, ML_C2;

    ML_F1 = 2;
    ML_C1 = 3;

    t_matriz matriz_1 = {
        {1, 2, 3},
        {4, 5, 6},
    };

    ML_F2 = 3;
    ML_C2 = 2;

    t_matriz matriz_2 = {
        {7, 8},
        {9, 10},
        {11, 12},
    };

    t_matriz resultado;
    vaciar_matriz(resultado);

    multiplicar_matrices(matriz_1, matriz_2, resultado, ML_F1, ML_C1, ML_F2, ML_C2);

    // Para mostrar esto no valido si se pudo hacer la multiplicación
    printf("El resultado de multiplicar\n\n");

    printf("Matriz 1:\n");
    mostrar_matriz(matriz_1, ML_F1, ML_C1);

    printf("Y matriz 2:\n");
    mostrar_matriz(matriz_2, ML_F2, ML_C2);

    printf("Es:\n");
    mostrar_matriz(resultado, ML_F1, ML_C2);

    return 0;
}
