/*
20) Un pastor cuenta sus ovejas.

Le sobra siempre una si las cuenta de la siguiente forma:
de 3 en 3, de 5 en 5, de 6 en 6 o de 9 en 9.

En cambio si las cuenta de 7 en 7 no le sobra ninguna.

Se pide escribir un programa que le permita obtener ese valor, sabiendo que el
número de ovejas no supera el millar.
*/

#include <stdio.h>

int obtener_resto(int numero, int divisor)
{
	return numero % divisor;
}

int main()
{

	int ovejas;

	ovejas = 1;

	while ((ovejas < 1000) &&
		   (obtener_resto(ovejas, 3) != 1 ||
			obtener_resto(ovejas, 5) != 1 ||
			obtener_resto(ovejas, 6) != 1 ||
			obtener_resto(ovejas, 9) != 1 ||
			obtener_resto(ovejas, 7) != 0))
		ovejas++;

	printf("Ovejas: %i\n", ovejas);

	return 0;
}