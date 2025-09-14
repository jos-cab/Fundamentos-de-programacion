/*
19) Diseñar un algoritmo que calcule la aproximación del seno:
sen(x)= x - (x^3)/3! + (x^5)/5 - (x^7)/7! + ..........

Nota: Una buena aproximación está dada por el desarrollo de 10 términos como
mínimo.
*/

#include <stdio.h>

#define TERMINOS 10
#define PI 3.1415

float elevado(float base, int exponente)
{
	float resultado = 1;

	while (exponente > 0)
	{
		resultado *= base;
		exponente--;
	}

	return resultado;
}

float factorial(float n)
{
	float resultado;
	int i;

	resultado = 1;

	for (i = 2; i <= n; i++)
		resultado *= (float)i;

	return resultado;
}

float seno(float x)
{
	int i;
	float resultado, aux;

	resultado = 0;

	for (i = 0; i < TERMINOS; i++)
	{
		if (i % 2 == 0)
			resultado += elevado(x, (2 * i) + 1) / factorial((2 * i) + 1);
		else
			resultado -= elevado(x, (2 * i) + 1) / factorial((2 * i) + 1);
	}

	// Para evitar errores de redondeo
	// 2 son la cantidad de decimales que quiero mostrar en el resultado

	aux = resultado * (elevado(10, 2));

	if (-1 < aux && aux < 1)
		resultado = 0;

	return resultado;
}

int main()
{
	printf("sen(0) = %.2f\n", seno(0));
	printf("sen(pi/2) = %.2f\n", seno(PI / 2));
	printf("sen(pi) = %.2f\n", seno(PI));
	printf("sen(2 * pi) = %.2f\n", seno(2 * PI));
	printf("sen(-(pi / 2)) = %.2f\n", seno(-(PI / 2)));
	printf("sen(1 / 2) = %.2f\n", seno(0.5));
	printf("sen(0.99 * PI) = %.2f\n", seno(0.99 * PI));

	return 0;
}