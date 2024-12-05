/*
2) Escribir un programa el cual reserve memoria dinámica para almacenar una
cierta cantidad de números numeros (n * int), este valor n debe ser ingresado
por el usuario.

Luego solicitarle que ingrese n valores numéricos ingresados de a uno y
almacenarlos en la memoria previamente reservada.

Mostrar luego todos los valores ingresados.

Liberar la memoria reservada al finalizar el programa.
*/

#include <stdio.h>
#include <stdlib.h>

void ingresar_datos(int *numeros, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("Ingrese el numero %i: ", i + 1);
		scanf("%i", &numeros[i]);
	}
}

void mostrar_datos(int *numeros, int n)
{
	int i;

	printf("Los numeros ingresados fueron: ");

	for (i = 0; i < n; i++)
		printf("%i ", numeros[i]);
}

int main()
{
	int *numeros;
	int n;

	printf("Indique la cantidad de valores numeros a almacenar: ");
	scanf("%i", &n);

	numeros = malloc(n * sizeof(int));

	if (numeros != NULL)
	{
		ingresar_datos(numeros, n);
		mostrar_datos(numeros, n);

		free(numeros);
	}
	else
	{
		printf("Error al reservar espacio de memoria.");
	}

	return 0;
}