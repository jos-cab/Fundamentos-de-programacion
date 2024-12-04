/*
18) Escribir un programa para cambiar un número binario de cuatro cifras a un
número de base 10.

a) Los datos a leer son 4 números de un dígito cada uno
b) El dato es un solo número de 4 cifras
*/

#include <stdio.h>

long elevado(int base, int exponente)
{
	long resultado = 1;

	while (exponente > 0)
	{
		resultado *= base;
		exponente--;
	}

	return resultado;
}

int binario_a_decimal(int binario)
{
	int resultado, exponente;

	resultado = 0;
	exponente = 0;

	while (binario > 0)
	{
		resultado += (binario % 10) * elevado(2, exponente);
		binario /= 10;
		exponente++;
	}

	return resultado;
}

int main()
{
	printf("Ingrese un número binario de cuatro cifras: ");
	int binario;
	scanf("%d", &binario);

	printf("El número en base 10 es: %d", binario_a_decimal(binario));
	return 0;
}
