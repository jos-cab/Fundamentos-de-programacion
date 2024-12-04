/*
21) Escribir un subprograma que dados a y b devuelva el cociente y el resto de
la división entera, sin utilizar los operadores correspondientes al lenguaje.

Validar los tipos de datos de entrada.
*/

#include <stdio.h>
#include <stdbool.h>

int cociente(int a, int b)
{
	int resultado;
	bool resultado_negativo;

	resultado_negativo = (a < 0) != (b < 0);

	if (a < 0)
		a = -a;

	if (b < 0)
		b = -b;

	while (a >= b)
	{
		a -= b;
		resultado++;
	}

	if (resultado_negativo)
		resultado *= -1;

	return resultado;
}

int resto(int a, int b)
{
	int resultado;
	bool resultado_negativo;

	resultado_negativo = (a < 0) != (b < 0);

	if (a < 0)
		a = -a;

	if (b < 0)
		b = -b;

	while (a >= b)
		a -= b;

	resultado = a;

	if (resultado_negativo)
		resultado *= -1;

	return resultado;
}

int main()
{
	int a, b;

	printf("Ingrese un número: ");
	scanf("%d", &a);
	printf("Ingrese otro número: ");
	scanf("%d", &b);

	if (b == 0)
	{
		printf("No se puede dividir por cero\n");
	}
	else
	{
		printf("Cociente: %d\n", cociente(a, b));
		printf("Resto: %d\n", resto(a, b));
	}
	return 0;
}
