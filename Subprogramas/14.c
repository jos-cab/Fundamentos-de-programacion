/*
14) Dado un listado de números enteros informar aquellos que sean primos, la
cantidad y la sumatoria de los mismos.
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
	if (es_primo(3))
		printf("3 es primo\n");
	else
		printf("3 no es primo\n");

	if (es_primo(7))
		printf("7 es primo\n");
	else
		printf("7 no es primo\n");

	if (es_primo(10))
		printf("10 es primo\n");
	else
		printf("10 no es primo\n");

	return 0;
}
