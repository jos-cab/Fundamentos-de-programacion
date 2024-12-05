/*
10) Utilizar memoria dinámica para almacenar una cierta cantidad de n palabras
ingresadas por el usuario.

Crear una estructura de datos dinámica de dos dimensiones que permita almacenar
esta información.

Mostrar toda la información de la estructura luego de haber sido cargada.

Liberar toda la memoria al finalizar el programa.

typedef char* t_palabra;
typedef t_palabra* t_vec;
*/

#include <stdio.h>
#include <stdlib.h>

typedef char *t_palabra;
typedef t_palabra *t_vec;

void ingresar_palabras(t_vec palabras, int n)
{
	int i;

	i = 0;

	do
	{
		palabras[i] = malloc(100 * sizeof(char));

		if (palabras[i] != NULL)
		{
			printf("Ingrese la palabra %i: ", i + 1);
			fgets(palabras[i], 100, stdin);
			fflush(stdin);
			i++;
		}
		else
		{
			printf("No se pudo reservar memoria");

			while (i > 0)
			{
				free(palabras[i]);
				i--;
			}
		}

	} while ((palabras[i] != NULL) && (i < n));
}

void mostrar_palabras(t_vec palabras, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("Palabra %i: %s", i + 1, palabras[i]);
	}
}

int main()
{
	int n;

	printf("Indique la cantidad de palabras a almacenar: ");
	scanf("%i", &n);
	getchar();

	t_vec palabras = malloc(n * sizeof(t_palabra));

	if (palabras != NULL)
	{
		ingresar_palabras(palabras, n);
		mostrar_palabras(palabras, n);

		free(palabras);
	}
	else
	{
		printf("No se pudo reservar memoria");
	}

	return 0;
}