/*
1) Escribir un programa el cual reserve memoria dinámica para almacenar un
número entero (int), le solicite al usuario el ingreso de un número y se asigna
dicho valor en la memoria reservada, luego mostrar dicho valor por pantalla.

Liberar la memoria reservada al finalizar el programa.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *puntero;

	puntero = malloc(sizeof(int));

	if (puntero != NULL)
	{
		printf("Ingrese un numero: ");
		scanf("%d", puntero);

		printf("El numero ingresado es: %d", *puntero);
		free(puntero);
	}
	else
	{
		printf("No se pudo reservar la memoria");
	}

	return 0;
}
