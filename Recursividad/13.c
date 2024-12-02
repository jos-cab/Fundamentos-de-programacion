/*
13) Desarrollar una función recursiva que compruebe si un número es binario.
Un número binario está formado únicamente por ceros y unos
*/

#include <stdio.h>
#include <stdbool.h>

bool es_binario(int numero)
{
	int ultimo_digito = numero % 10;

	if (ultimo_digito != 0 && ultimo_digito != 1)
		return false;
	else if (numero == 0)
		return true;

	return es_binario(numero / 10);
}

int main()
{
	if (es_binario(1001301))
		printf("Es binario");
	else
		printf("No es binario");
	return 0;
}
