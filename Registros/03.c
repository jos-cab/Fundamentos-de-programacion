/*
3) Dada la estructura de datos del problema anterior, escribir el algoritmo de
búsqueda binaria para la búsqueda de un dato correspondiente a los
campos de Apellido, Nombre o número de legajo, a elección del usuario.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CANTIDAD_EMPLEADOS 100
#define MAX_NOMBRE 35

typedef struct
{
	char apellido[MAX_NOMBRE];
	char nombre[MAX_NOMBRE];

	unsigned short int legajo;

	char calle[MAX_NOMBRE];
	unsigned short int numero_calle;
	char localidad[MAX_NOMBRE];
	char provincia[MAX_NOMBRE];
	unsigned short int codigo_postal;

	unsigned short int dia_nacimiento;
	unsigned short int mes_nacimiento;
	unsigned short int año_nacimiento;

	unsigned short int dia_ingreso;
	unsigned short int mes_ingreso;
	unsigned short int año_ingreso;
} empleado;

typedef empleado lista_empleados[MAX_CANTIDAD_EMPLEADOS];

void buscar_dato_en_empleados(int dato_numerico, char dato_texto[MAX_NOMBRE], int campo, lista_empleados empleados, int ML, empleado *empleado_encontrado)
{
	int izquierda, medio, derecha;
	bool encontrado;

	encontrado = false;

	izquierda = 0;
	derecha = ML - 1;

	// TODO: verificar que el campo ingresado sea correcto
	while ((!encontrado) && (izquierda <= derecha))
	{
		medio = (izquierda + derecha) / 2;

		switch (campo)
		{
		case 1:
			encontrado = strcmp(empleados[medio].apellido, dato_texto) == 0;
			break;
		case 2:
			encontrado = strcmp(empleados[medio].nombre, dato_texto) == 0;
			break;
		case 3:
			encontrado = empleados[medio].legajo == dato_numerico;
			break;
		}

		if (!encontrado)
		{
			switch (campo)
			{
			case 1:
				if (strcmp(empleados[medio].apellido, dato_texto) < 0)
					izquierda = medio + 1;
				else
					derecha = medio - 1;
				break;
			case 2:
				if (strcmp(empleados[medio].nombre, dato_texto) < 0)
					izquierda = medio + 1;
				else
					derecha = medio - 1;
				break;
			case 3:
				if (empleados[medio].legajo < dato_numerico)
					izquierda = medio + 1;
				else
					derecha = medio - 1;
				break;
			}
		}
		else
			*empleado_encontrado = empleados[medio];
	}
}

void imprimir_empleado(empleado empleado)
{
	printf("Apellido, Nombre, Legajo, Domicilio, Localidad, Provincia, Código Postal, Fecha de nacimiento, Fecha de ingreso\n\n");
	printf("%s %s, %i, %s %i, %s, %s, %i, %i/%i/%i, %i/%i/%i\n", empleado.apellido, empleado.nombre, empleado.legajo,
		   empleado.calle, empleado.numero_calle, empleado.localidad, empleado.provincia, empleado.codigo_postal,
		   empleado.dia_nacimiento, empleado.mes_nacimiento, empleado.año_nacimiento, empleado.dia_ingreso,
		   empleado.mes_ingreso, empleado.año_ingreso);
}

int main()
{
	int dato_numerico, campo, ML;
	char dato_texto[MAX_NOMBRE];
	empleado empleado_encontrado = {"", "", 0, "", 0, "", "", 0, 0, 0, 0, 0, 0, 0};

	ML = 10;
	dato_numerico = 0;
	dato_texto[0] = '\0';

	/* Datos generados con IA */
	// Borré los acentos porque strcmp no reconoce los acentos
	// Ordenados por nombre
	lista_empleados empleados = {
		{"Gomez", "Ana", 1002, "Av. Libertador", 456, "CABA", "Buenos Aires", 1001, 22, 8, 1990, 5, 6, 2015},
		{"Lopez", "Carlos", 1003, "Diagonal Norte", 789, "La Plata", "Buenos Aires", 1900, 30, 11, 1980, 15, 1, 2012},
		{"Hernandez", "Elena", 1008, "Calle Paraná", 100, "Tucumán", "Tucumán", 4000, 17, 6, 1994, 6, 8, 2019},
		{"Perez", "Juan", 1001, "Calle Falsa", 123, "Buenos Aires", "Buenos Aires", 1000, 15, 5, 1985, 1, 3, 2010},
		{"Fernandez", "Laura", 1006, "Av. Santa Fe", 2020, "Mar del Plata", "Buenos Aires", 7600, 14, 9, 1992, 12, 5, 2017},
		{"Martinez", "Lucia", 1004, "Callejón del Sol", 321, "Rosario", "Santa Fe", 2000, 3, 7, 1987, 10, 10, 2014},
		{"Alvarez", "Martin", 1007, "Calle Vuelta", 789, "Mendoza", "Mendoza", 5500, 5, 12, 1986, 7, 4, 2013},
		{"Rodriguez", "Pedro", 1005, "Ruta 9", 45, "San Miguel", "Buenos Aires", 1665, 10, 3, 1982, 20, 1, 2018},
		{"Sanchez", "Raul", 1009, "Av. 9 de Julio", 501, "CABA", "Buenos Aires", 1002, 22, 11, 1980, 15, 7, 2016},
		{"Diaz", "Sofia", 1010, "Calle Brasil", 231, "Salta", "Salta", 4400, 8, 3, 1991, 1, 2, 2020}};

	printf("Ingrese el campo por el cual desea buscar a un empleado:\n");
	printf("1. Apellido\n2. Nombre\n3. Legajo\n");
	printf("\n> ");
	scanf("%d", &campo);

	printf("\n");

	printf("Ingrese el dato a buscar:\n");
	printf("\n> ");

	if (campo == 1 || campo == 2)
		scanf("%s", &dato_texto);
	else
		scanf("%d", &dato_numerico);

	buscar_dato_en_empleados(dato_numerico, dato_texto, campo, empleados, ML, &empleado_encontrado);

	if (empleado_encontrado.legajo != 0)
		imprimir_empleado(empleado_encontrado);
	else
		printf("No se encontró el empleado\n");

	return 0;
}
