/*
2) Hacer una función que invierta un vector, además del vector se pasará por
parámetro su máximo lógico.

• Solamente hacer el intercambio si es necesario
• Hacer un contador de cuantos cambios se hicieron

Ej: 165467, sale 764561
El contador deberá resultar en 2

El 6 con 6 no deberá hacer un intercambio
*/

#include <stdio.h>

#define MF 20

typedef int t_vector[MF];

int invertir_vector(t_vector vector, int ML)
{
	int i;
	int intercambios = 0;
	int aux;

	for (i = 0; i < (ML / 2); i++)
	{
		if (vector[i] != vector[ML - 1 - i])
		{
			aux = vector[i];
			vector[i] = vector[ML - i - 1];
			vector[ML - i - 1] = aux;

			intercambios++;
		}
	}

	return intercambios;
}

void mostrar_vector(t_vector vector, int ML)
{
	int i;

	for (i = 0; i < ML; i++)
		printf("%i ", vector[i]);
}

int main()
{
	t_vector vector = {1, 6, 5, 4, 6, 7};
	int ML = 6;
	int intercambios;

	printf("Vector original:\n");
	mostrar_vector(vector, ML);

	intercambios = invertir_vector(vector, ML);

	printf("\nVector invertido:\n");
	mostrar_vector(vector, ML);
	printf("\nSe intercambiaron %i elementos", intercambios);

	return 0;
}
