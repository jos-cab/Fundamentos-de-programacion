/*
3) Asumiendo que ya existe un puntero que apunta a un bloque de memoria
previamente reservada con malloc de tamaño (n * int), redimensionar dicha
memoria a un tamaño de (2 * n *int).
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *numeros;
	int n, i;

	n = 3;

	numeros = malloc(n * sizeof(int));

	if (numeros != NULL)
	{
		printf("El tamaño de la memoria es %i\n", n);

		numeros = realloc(numeros, 2 * n * sizeof(int));

		printf("El tamaño fue redimensionado a %i\n", 2 * n);

		free(numeros);
	}
	else
	{
		printf("Error al reservar espacio de memoria.");
	}

	return 0;
}