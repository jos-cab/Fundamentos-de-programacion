/*
23) Escribir un subprograma que dadas las coordenadas polares r y α devuelva
las correspondientes coordenadas rectangulares x = r cos α , y = r sen α.
*/

#include <stdio.h>
#include <math.h>

// Hago las funciones por si luego quiero hacerlas sin math.h

// NO FUNCIONA
/*double cos(double x)
{
	return cos(x);
}*/

double sen(double x)
{
	return sin(x);
}

void imprimir_coordenadas_rectangulares(double r, double a)
{
	double x, y;

	x = r * cos(a);
	y = r * sen(a);

	printf("Coordenadas rectangulares: x = %.2lf, y = %.2lf\n", x, y);
}

int main()
{
	double r, a;

	printf("Ingrese r: ");
	scanf("%lf", &r);

	printf("Ingrese a: ");
	scanf("%lf", &a);

	imprimir_coordenadas_rectangulares(r, a);

	return 0;
}
