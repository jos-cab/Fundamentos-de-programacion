/*
10) Desarrollar un programa que solicite al usuario el ingreso de un numero
entero y calcule el máximo común divisor de forma recursiva.
*/

#include <stdio.h>

int maximo_comun_divisor(int numero_1, int numero_2)
{
	int aux, maximo_divisor;

	if (numero_2 > numero_1)
	{
		aux = numero_2;
		numero_2 = numero_1;
		numero_1 = aux;

		return maximo_comun_divisor(numero_1, numero_2);
	}
	else if (numero_2 != 0)
	{
		aux = numero_1 % numero_2;
		numero_1 = numero_2;
		numero_2 = aux;

		return maximo_comun_divisor(numero_1, numero_2);
	}

	return numero_1;
}

int main()
{
	int numero_1, numero_2;

	printf("Ingrese el primer numero: ");
	scanf("%d", &numero_1);

	printf("Ingrese el segundo numero: ");
	scanf("%d", &numero_2);

	printf("El maximo comun divisor es: %d", maximo_comun_divisor(numero_1, numero_2));

	return 0;
}