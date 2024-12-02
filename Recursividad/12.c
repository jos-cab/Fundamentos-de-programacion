/*
12) Desarrollar un programa que muestre los primeros N números naturales. El
numero N lo debe ingresar el usuario.
*/

#include <stdio.h>

void mostrar_numeros(int n)
{
	if (n > 0)
	{
		mostrar_numeros(n - 1);
		printf("%d ", n);
	}
}

int main()
{
	int n;

	printf("Ingrese un numero: ");
	scanf("%d", &n);

	mostrar_numeros(n);

	return 0;
}