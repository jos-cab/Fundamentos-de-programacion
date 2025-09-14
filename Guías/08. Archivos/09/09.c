/*
9) Se tiene un archivo con los siguientes datos de los empleados de una empresa:
Apellido y Nombre (35 caracteres),
Fecha de Nacimiento (día, mes y año),
Fecha de Ingreso (día, mes y año)
y Sueldo Básico

Se conoce la fecha de procesamiento.

Se pide:
a) Imprimir un listado con los apellidos y nombres de las personas que cumplan
años en el mes.

b) Calcular e informar una suma de regalo equivalente al uno por mil del sueldo
por cada año cumplido.
*/

#include <stdio.h>

#define MAX_CANTIDAD_EMPLEADOS 100
#define MAX_NOMBRE 35
#define MES_ACTUAL 11
#define AÑO_ACTUAL 2024

typedef struct
{
	char apellido[MAX_NOMBRE];
	char nombre[MAX_NOMBRE];

	unsigned short int dia_nacimiento;
	unsigned short int mes_nacimiento;
	unsigned short int año_nacimiento;

	unsigned short int dia_ingreso;
	unsigned short int mes_ingreso;
	unsigned short int año_ingreso;

	float sueldo_basico;
} empleado;

typedef empleado lista_empleados[MAX_CANTIDAD_EMPLEADOS];

void leer_empleados(lista_empleados empleados, int *ML)
{
	int i;
	FILE *archivo_empleados;

	archivo_empleados = fopen("empleados.txt", "r");
	i = 0;

	while (!feof(archivo_empleados))
	{
		fscanf(archivo_empleados, "%s %s %hu %hu %hu %hu %hu %hu %f",
			   empleados[i].apellido,
			   empleados[i].nombre,
			   &empleados[i].dia_nacimiento,
			   &empleados[i].mes_nacimiento,
			   &empleados[i].año_nacimiento,
			   &empleados[i].dia_ingreso,
			   &empleados[i].mes_ingreso,
			   &empleados[i].año_ingreso,
			   &empleados[i].sueldo_basico);
		i++;
	}

	*ML = i;

	fclose(archivo_empleados);
}

void mostrar_cumpleañeros_y_regalo(lista_empleados empleados, int ML)
{
	int i;

	printf("Los cumpleanos del mes y sus regalos son:\n\n");

	for (i = 0; i < ML; i++)
		if (empleados[i].mes_nacimiento == MES_ACTUAL)
		{
			printf("%s %s\n", empleados[i].apellido, empleados[i].nombre);
			printf("Regalo: %i\n", 1000 * (AÑO_ACTUAL - empleados[i].año_ingreso));
			printf("\n");
		}
}

int main()
{
	int ML;
	lista_empleados empleados = {};

	leer_empleados(empleados, &ML);
	mostrar_cumpleañeros_y_regalo(empleados, ML);

	return 0;
}