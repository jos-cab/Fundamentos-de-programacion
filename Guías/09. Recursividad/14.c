/*
14) Desarrollar una función recursiva que imprima por pantalla un rectángulo a
partir de los valores de la base y la altura ingresados por teclado.
*/

#include <stdio.h>

void imprimir_linea(int base)
{
	if (base > 0)
	{
		printf("*");
		imprimir_linea(base - 1);
	}
}

void imprimir_rectangulo(int base, int altura)
{
	if (altura > 0)
	{
		imprimir_linea(base);
		printf("\n");
		imprimir_rectangulo(base, altura - 1);
	}
}

int main(int argc, char const *argv[])
{
	printf("Ingrese la base: ");
	int base;
	scanf("%d", &base);

	printf("Ingrese la altura: ");
	int altura;
	scanf("%d", &altura);

	printf("\n");

	imprimir_rectangulo(base, altura);
	return 0;
}
