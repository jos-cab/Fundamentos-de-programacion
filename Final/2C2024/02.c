/*
2. Escribir una función llamada "crear_estructura_dinamica" que reciba un
arreglo unidimensional de elementos enteros ya cargado, y su respectivo máximo
lógico.

La función debe devolver un puntero a una estructura dinámica que
contenga los elementos del arreglo recibido y utilice sólo el espacio de memoria
necesario.

Escribir un main que:
a. Invoque a la función utilizando como arreglo la siguiente declaración:
	int vector[100] = {48, 23, 2, 5, 18};

b. Haga una llamada a la función mostrar_estructura_dinamica a la que se le debe
pasar la estructura y la correspondiente cantidad de elementos a mostrar.

No tenés que desarrollar esta función, solo utilizarla adecuadamente.

Sólo se puede invocar esta función si el puntero no es nulo.
*/

#include <stdio.h>
#include <stdlib.h>

int *crear_estructura_dinamica(int vector[100], int ML)
{
	int i;
	int *nuevo_vector;

	nuevo_vector = malloc(ML * sizeof(int));

	if (nuevo_vector != NULL)
		for (i = 0; i < ML; i++)
			nuevo_vector[i] = vector[i];
	else
		printf("No se pudo reservar la memoria");

	return nuevo_vector;
}

/* No lo pide el enunciado, ignorar */

void mostrar_estructura_dinamica(int *vector, int ML)
{
	int i;

	for (i = 0; i < ML; i++)
		printf("%i ", vector[i]);
}

/* */

int main()
{
	int vector[100] = {48, 23, 2, 5, 18};
	int ML = 5;
	int *nuevo_vector = crear_estructura_dinamica(vector, ML);

	if (nuevo_vector != NULL)
	{
		mostrar_estructura_dinamica(nuevo_vector, ML);
		free(nuevo_vector);
	}

	return 0;
}
