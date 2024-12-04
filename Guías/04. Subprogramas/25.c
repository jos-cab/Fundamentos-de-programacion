/*
25) Escribir un subprograma que dado un tiempo expresado en segundos, devuelva
los parámetros numéricos horas, minutos y segundos.
*/

#include <stdio.h>

void imprimir_tiempo(int segundos)
{
	int horas, minutos;

	horas = segundos / 3600;
	minutos = (segundos % 3600) / 60;
	segundos = (segundos % 3600) % 60;

	printf("Horas: %i, minutos: %i, segundos: %i\n", horas, minutos, segundos);
}

int main(int argc, char const *argv[])
{
	imprimir_tiempo(3600);
	imprimir_tiempo(3601);
	imprimir_tiempo(4321);

	return 0;
}
