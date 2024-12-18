/*
3) Hacer una función que compare 2 matrices ya completamente cargadas

#DEFINE cantfilas 15
#DEFINE cantcols 25
typedef float Tmatriz[cantfilas][cantcols]

La función debera:
• Sumar todos los valores de la columna que es igual en ambas matices
(aclaración: la columna 1 de la matriz 1 y 2 es igual, bueno se deberá sumar
todos los valores una vez, no 2 veces.

Si hay mas de una columna igual en ambas matrices, los valores de esta deberan
ir al acumlador, no hacer un acumulador por cada columna repetida)

• Un contador para las columnas que sean iguales (aclaración: si la columna 1 es
igual en la matriz 1 y 2, a este contador solo se deberá sumar +1, no +2)

Se deberá invocar a esta función.

Solo se deberá recorrer una vez cada matriz.

No hacer interaciones innecesarias.
*/

#include <stdio.h>
#include <stdbool.h>

#define cantfilas 15
#define cantcols 25

typedef float Tmatriz[cantfilas][cantcols];

void sumatoria_columnas_iguales(Tmatriz matriz_1, Tmatriz matriz_2, int ML_filas, int ML_columnas, float *suma, int *cantidad_columnas_iguales)
{
	int i, j;
	bool son_columnas_iguales;
	float suma_aux;

	*suma = 0;
	*cantidad_columnas_iguales = 0;

	i = 0;

	while (i < ML_columnas)
	{
		suma_aux = 0;
		son_columnas_iguales = true;

		j = 0;

		while ((son_columnas_iguales) && (j < ML_filas))
		{
			son_columnas_iguales = matriz_1[j][i] == matriz_2[j][i];

			if (son_columnas_iguales)
			{
				suma_aux += matriz_1[j][i];
				j++;
			}
		}

		if (son_columnas_iguales)
		{
			(*cantidad_columnas_iguales)++;
			*suma += suma_aux;
		}

		i++;
	}
}

int main()
{
	Tmatriz matriz_1 = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}};

	Tmatriz matriz_2 = {
		{1, 0, 3},
		{4, 0, 6},
		{7, 0, 9}};

	int ML_filas = 3;
	int ML_columnas = 3;

	float suma;
	int cantidad_columnas_iguales;

	sumatoria_columnas_iguales(matriz_1, matriz_2, ML_filas, ML_columnas, &suma, &cantidad_columnas_iguales);

	printf("La cantidad de columnas iguales es: %i y su sumatoria es: %.2f", cantidad_columnas_iguales, suma);

	return 0;
}
