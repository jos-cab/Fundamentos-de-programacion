/*
24) Escribir un subprograma que dada una fecha en formato aaaammdd la
convierta en los parámetros numéricos aaaa, mm y dd.
*/

#include <stdio.h>

void imprimir_fecha(int fecha)
{
	int año;
	int mes;
	int dia;

	año = fecha / 10000;
	mes = (fecha % 10000) / 100;
	dia = fecha % 100;

	printf("%04d/%02d/%02d\n", año, mes, dia);
}

int main()
{
	imprimir_fecha(20241204);
	imprimir_fecha(20240101);

	return 0;
}
