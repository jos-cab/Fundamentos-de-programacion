/*
17) Escribir un programa que determine el máximo común divisor entre dos
números.
*/

#include <stdio.h>

int mcd(int numero_1, int numero_2)
{
	int aux, maximo_divisor;

	if (numero_2 > numero_1)
	{
		aux = numero_2;
		numero_2 = numero_1;
		numero_1 = aux;
	}

	while (numero_2 != 0)
	{
		aux = numero_1 % numero_2;
		numero_1 = numero_2;
		numero_2 = aux;
	}

	maximo_divisor = numero_1;

	return maximo_divisor;
}

int main()
{
	printf("MDC(2, 4) = %d\n", mcd(2, 4));
	printf("MDC(10, 15) = %d\n", mcd(10, 15));
	printf("MDC(35, 10) = %d\n", mcd(35, 10));
	printf("MDC(3, 7) = %d\n", mcd(3, 7));
	printf("MDC(100, 25) = %d\n", mcd(100, 25));
	printf("MDC(8, 12) = %d\n", mcd(8, 12));

	return 0;
}
