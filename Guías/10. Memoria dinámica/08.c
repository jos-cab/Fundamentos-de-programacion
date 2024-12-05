/*
8) Implementar una función que retorna un puntero a un vector de n valores de
tipo int, todos inicializados en cero, el cual apunta a un bloque de memoria
dinámica, respetando la siguiente declaración.

En caso de no poder reservar la memoria, retornar NULL.

int* crear_vector_inicializado(int n);
*/

#include <stdio.h>
#include <stdlib.h>

int *crear_vector_inicializado(int n)
{
	return calloc(n, sizeof(int));
}

int main()
{
	int n;
	int *vector;

	n = 10;
	vector = crear_vector_inicializado(n);

	if (vector != NULL)
	{
		printf("Vector creado\n");

		free(vector);
	}
	else
	{
		printf("No se pudo crear el vector\n");
	}

	return 0;
}