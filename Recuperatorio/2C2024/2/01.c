/*
1) Hacer una función que invierta un número positivo, este se pasa por parámetro
Ej: entra 1567, sale 7651
*/

#include <stdio.h>

int invertir_numero(int numero)
{
	int numero_invertido = 0;

	while (numero > 0)
	{
		numero_invertido *= 10;
		numero_invertido += numero % 10;
		numero /= 10;
	}

	return numero_invertido;
}

int main()
{
	int numero = 1567;

	printf("%i", invertir_numero(numero));
	return 0;
}
