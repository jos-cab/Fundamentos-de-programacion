/*
9) Desarrollar un programa que solicite al usuario el ingreso de un numero
entero y lo muestre el resultado de sumar sus dígitos.
*/

#include <stdio.h>

int sumar_digitos(int numero)
{
	if (numero < 10)
		return numero;
	else
		return sumar_digitos(numero / 10) + (numero % 10);
}

int main()
{
	int numero;

	printf("Ingrese un numero: ");
	scanf("%d", &numero);

	printf("La suma de sus digitos es: %d", sumar_digitos(numero));

	return 0;
}