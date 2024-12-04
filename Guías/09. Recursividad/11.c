/*
11) Desarrollar un programa que solicite al usuario el ingreso de 2 números A y
B y calcule la potencia de A elevado a la B de forma recursiva.
*/

#include <stdio.h>

int elevado(int base, int exponente)
{
	if (exponente == 0)
		return 1;

	return base * elevado(base, exponente - 1);
}

int main()
{
	int base, exponente;

	printf("Ingrese la base: ");
	scanf("%d", &base);

	printf("Ingrese el exponente: ");
	scanf("%d", &exponente);

	printf("El resultado es: %d\n", elevado(base, exponente));

	return 0;
}