/*
5) Dados dos 2 listados de inscripción de alumnos a 3 turnos de una misma
materia, se pide generar un listado único ordenado por número de alumno.

La estructura de los listados es: número de alumno (5 dígitos), apellido y
nombre, turno (1, 2, 3).

Puede ocurrir que un alumno se haya inscripto en más de un turno por lo cual en
el listado generado deben aparecer todos los turnos en los que se inscribió en
un único registro de alumno con campo variable.

Los listados de entrada están ordenados por número de alumno.
*/

#include <stdio.h>

#define CANTIDAD_ALUMNOS 100
#define CANTIDAD_TURNOS 3
#define MAX_NOMBRE 35

typedef struct
{
	unsigned int legajo; // número de alumno
	char apellido[MAX_NOMBRE];
	char nombre[MAX_NOMBRE];
	unsigned int turno;
} alumno;

typedef alumno listado[CANTIDAD_ALUMNOS];

void juntar_listados(listado listado_1, int ML_listado_1, listado listado_2, int ML_listado_2, listado listado_unificado)
{
	int i, j;

	i = 0;
	j = 0;

	while ((i < ML_listado_1) || (j < ML_listado_2))
	{
		while ((listado_1[i].legajo < listado_2[j].legajo) && (i < ML_listado_1))
		{
			listado_unificado[i + j] = listado_1[i];
			i++;
		}

		while ((listado_2[j].legajo < listado_1[i].legajo) && (j < ML_listado_2))
		{
			listado_unificado[i + j] = listado_2[j];
			j++;
		}

		if (i == ML_listado_1)
		{
			while (j < ML_listado_2)
			{
				listado_unificado[i + j] = listado_2[j];
				j++;
			}
		}
		else if (j == ML_listado_2)
		{
			while (i < ML_listado_1)
			{
				listado_unificado[i + j] = listado_1[i];
				i++;
			}
		}
	}
}

void mostrar_listado(listado listado, int ML_listado)
{
	int i;

	printf("\n");
	for (i = 0; i < ML_listado; i++)
		printf("%i %s %s %i\n", listado[i].legajo, listado[i].apellido, listado[i].nombre, listado[i].turno);
}

int main()
{
	int ML_listado_1, ML_listado_2, ML_listado_alumnos_ordenado;

	listado listado_alumnos_1 = {
		{10001, "Garcia", "Juan", 1},
		{10001, "Garcia", "Juan", 2},
		{10002, "Rodriguez", "Pedro", 2},
		{10003, "Perez", "María", 3},
		{10005, "Martinez", "Jorge", 2},
		{10006, "Sanchez", "Laura", 3},
		{10009, "Fernandez", "Sofia", 3},
		{10009, "Fernandez", "Sofia", 1},
		{10010, "Ruiz", "Carlos", 2},
		{10010, "Ruiz", "Carlos", 1},
		{10013, "Flores", "Carmen", 2},
		{10013, "Flores", "Carmen", 3}};

	listado listado_alumnos_2 = {
		{10004, "Gonzalez", "Ana", 1},
		{10004, "Gonzalez", "Ana", 3},
		{10007, "Lopez", "Miguel", 1},
		{10008, "Diaz", "Fernando", 2},
		{10011, "Torres", "Elena", 3},
		{10012, "Ramirez", "Luis", 1},
		{10014, "Castro", "Alberto", 3},
		{10015, "Morales", "Julia", 1},
		{10016, "Ortiz", "Daniel", 2},
		{10017, "Gomez", "Silvia", 3},
		{10018, "Dominguez", "Ricardo", 1},
		{10019, "Vazquez", "Patricia", 2},
		{10020, "Herrera", "Adrian", 3}};

	ML_listado_1 = 12;
	ML_listado_2 = 13;

	listado listado_alumnos_ordenado;

	ML_listado_alumnos_ordenado = ML_listado_1 + ML_listado_2;

	juntar_listados(listado_alumnos_1, ML_listado_1, listado_alumnos_2, ML_listado_2, listado_alumnos_ordenado);
	mostrar_listado(listado_alumnos_ordenado, ML_listado_alumnos_ordenado);

	return 0;
}
