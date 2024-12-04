/*
22) Escribir un subprograma que dadas 2 coordenadas rectangulares (x,y) devuelva
las correspondientes coordenadas polares

r = ( x2 + y2 )½
y α = arctg ( y / x ).
*/

#include <stdio.h>
#include <math.h>

// Hago las funciones por si luego quiero hacerlas sin math.h

double elevado(double x, double y)
{
	return pow(x, y);
}

double arctg(double x)
{
	return atan(x);
}

void imprimir_coordenadas_polares(double x, double y)
{
	double r, a;

	// Elevo a la 0.5 para sacar raíz cuadrada
	r = elevado((elevado(x, 2) + elevado(y, 2)), 0.5);
	a = arctg(y / x);

	printf("Coordenadas polares: r = %.2lf, a = %.2lf\n", r, a);
}

int main()
{
	double x, y;

	printf("Ingrese x: ");
	scanf("%lf", &x);

	printf("Ingrese y: ");
	scanf("%lf", &y);

	imprimir_coordenadas_polares(x, y);

	return 0;
}
