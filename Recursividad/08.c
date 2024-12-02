/*
8) Desarrollar una función recursiva que comprube si un numero pasado como
parámetro es capicúa.
*/

#include <stdio.h>
#include <stdbool.h>

// Las funciones calcular_numero_invertido y elevado pueden ser recursivas, pero
// para hacer más fácil la resolución y para evitar usar parámetros de más en la
// función es_capicua decidí hacerlas iterativas.

int calcular_numero_invertido(int numero)
{
	int invertido, digito;

	invertido = 0;

	while (numero > 0)
	{
		digito = numero % 10;
		numero /= 10;

		invertido = invertido * 10 + digito;
	}

	return invertido;
}

// Para la versión recursiva de la siguiente función ver ejercicio 11
int elevado(int base, int exponente)
{
	int resultado;

	resultado = 1;

	while (exponente > 0)
	{
		resultado *= base;
		exponente--;
	}

	return resultado;
}

bool es_capicua(int numero)
{
	int primer_digito, ultimo_digito;

	primer_digito = calcular_numero_invertido(numero) % 10;
	ultimo_digito = numero % 10;

	if ((primer_digito == 0) && (ultimo_digito == 0))
		return true;
	else if (primer_digito == ultimo_digito)
	{
		// Saco el primer dígito
		numero = calcular_numero_invertido(numero) / 10;
		numero = calcular_numero_invertido(numero);

		// Saco el ultimo dígito
		numero /= 10;

		return es_capicua(numero);
	}

	return false;
}

int main()
{
	int numero;

	numero = 151;

	if (es_capicua(numero))
		printf("%d Es capicua", numero);
	else
		printf("%d No es capicua", numero);

	return 0;
}
