/*
7) Desarrollar un programa que muestre la suma de los primeros N números
naturales.

El numero N lo debe ingresar el usuario.
*/

#include <stdio.h>

int suma_naturales(int n)
{
	if (n > 0)
		return n + suma_naturales(n - 1);

	return 0;
}

int main(int argc, char const *argv[])
{
	int n;

	printf("Ingrese un numero: ");
	scanf("%d", &n);

	// Se puede hacer:
	// printf("La suma de los primeros %d numeros naturales es: %d\n", n, (n * (n + 1)) / 2);
	// Pero esta es la guía de recursividad.

	printf("La suma de los primeros %d numeros naturales es: %d\n", n, suma_naturales(n));

	return 0;
}
