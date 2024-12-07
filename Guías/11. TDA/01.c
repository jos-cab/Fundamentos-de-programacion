/*
1) Desarrollar un TDA de tipo t_cuadrado que tiene definidas las siguientes
primitivas.

Se pide:
• Especificar pre y post condiciones de las primitivas definidas.
• Implementar las primitivas

typedef struct {
	double x_coord;
	double y_coord;
	double lado;
} t_cuadrado;

void crear(double x, double y, double lado, t_cuadrado c);

double perimetro(t_cuadrado c);

double area(t_cuadrado c);

void redimensionar(t_cuadrado c, double factor);

bool punto_interno(t_cuadrado c, double x, double y);
*/

#include <stdio.h>
#include <stdbool.h>

typedef struct
{
	double x_coord;
	double y_coord;
	double lado;
} t_cuadrado;

void crear(double x, double y, double lado, t_cuadrado c)
{
	if (lado > 0)
	{
		c.x_coord = x;
		c.y_coord = y;
		c.lado = lado;
	}
}

double perimetro(t_cuadrado c)
{
	return 4 * c.lado;
}

double area(t_cuadrado c)
{
	return c.lado * c.lado;
}

void redimensionar(t_cuadrado c, double factor)
{
	c.lado *= factor;
}

bool punto_interno(t_cuadrado c, double x, double y)
{
	return (x >= c.x_coord && x <= c.x_coord + c.lado) &&
		   (y >= c.y_coord && y <= c.y_coord + c.lado);
}

int main()
{

	return 0;
}
