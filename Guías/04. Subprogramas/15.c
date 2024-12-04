/*
15) Dado un listado de números enteros informar los n primeros números primos
que aparezcan y su sumatoria.
*/

#include <stdio.h>
#include <stdbool.h>

bool es_primo(int n)
{
	bool primo;
	int i;

	primo = true;
	i = 2;

	while ((i < n / 2) && primo)
		if (n % i == 0)
			primo = false;
		else
			i++;

	return primo;
}

int main()
{
	int n, numero, cantidad_primos, sumatoria_primos; // n es la cantidad de primos a encontrar

	sumatoria_primos = 0;
	cantidad_primos = 0;

	printf("Ingrese la cantidad de números primos a encontrar: ");
	scanf("%d", &n);

	printf("Ingrese los números enteros (termina con un número negativo):\n");

	do
	{
		scanf("%d", &numero);

		if (es_primo(numero))
		{
			cantidad_primos++;
			sumatoria_primos += numero;

			printf("Primo encontrado: %d\n", numero);
		}
	} while ((cantidad_primos < n) && (numero >= 0));

	if (cantidad_primos > 0)
	{
		printf("\nSe encontraron %d números primos.\n", cantidad_primos);
		printf("La sumatoria de los primos es: %d\n", sumatoria_primos);
	}
	else
	{
		printf("No se encontraron números primos.\n");
	}

	return 0;
}
