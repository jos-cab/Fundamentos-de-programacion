/*
16) Escribir un programa que descomponga a un número en sus factores
primos.
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

void descomponer_en_primos(int numero)
{
	int i;

	printf("%i: ", numero);

	while (numero > 1)
	{
		i = 2;

		while (!es_primo(i) || (numero % i != 0))
		{
			i++;
		}

		printf("%i ", i);
		numero /= i;
	}

	printf("\n");
}

int main()
{
	printf("Numeros descompuestos por sus factores primos:\n");

	descomponer_en_primos(12);
	descomponer_en_primos(11);
	descomponer_en_primos(100);
	descomponer_en_primos(52);

	return 0;
}
