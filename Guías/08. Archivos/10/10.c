/*
10) Una escuela tiene en el archivo ARCHIVO.DAT, los siguientes datos de sus
alumnos: NOMBRE, AÑO, DIVISION, PROMEDIO GENERAL.

El archivo está ordenado en forma creciente por año y división.

Se pide:
• Imprimir un listado por año y división con los nombres de los alumnos y sus
promedios.
• Informar, al final del proceso, el nombre del alumno con mejor promedio de la
escuela.
• Grabar en un archivo los siguientes datos de cada año y división:
AÑO, DIVISION, CANTIDAD DE ALUMNOS
*/

/*
	NOTA: para este ejercicio se puede hacer todo en un solo bucle, pero decidí
	usar funciones para no dejar todo en el main. A parte de no hacer todo junto
	para mejorar la legibilidad.
*/

#include <stdio.h>

#define MAX_ALUMNOS 100

typedef struct
{
	char nombre[20];
	int año;
	int division;
	float promedio;
} alumno;

typedef alumno lista_alumnos_t[MAX_ALUMNOS];

void leer_alumnos(lista_alumnos_t alumnos, int *ML)
{
	FILE *archivo_alumnos;

	archivo_alumnos = fopen("archivo.dat", "r");

	*ML = 0;

	while (!feof(archivo_alumnos))
	{
		fscanf(archivo_alumnos, "%s %d %d %f", alumnos[*ML].nombre, &alumnos[*ML].año, &alumnos[*ML].division, &alumnos[*ML].promedio);
		(*ML)++;
	}

	fclose(archivo_alumnos);
}

void imprimir_alumnos_por_año_y_division(lista_alumnos_t alumnos, int ML)
{
	int i, año, division;

	año = 0;
	division = 0;

	printf("\nListado por año y division de alumnos y promedios\n");

	for (i = 0; i < ML; i++)
	{
		if (alumnos[i].año != año)
		{
			año = alumnos[i].año;
			printf("\nAÑO: %d", alumnos[i].año);
		}

		if (alumnos[i].division != division)
		{
			division = alumnos[i].division;
			printf("\nDIVISION: %d\n\n", alumnos[i].division);
		}

		printf("%s %.2g\n", alumnos[i].nombre, alumnos[i].promedio);
	}
}

void imprimir_mejor_promedio(lista_alumnos_t alumnos, int ML)
{
	alumno alumno_mejor_promedio;
	int i;

	alumno_mejor_promedio = alumnos[0];

	for (i = 1; i < ML; i++)
		if (alumnos[i].promedio > alumno_mejor_promedio.promedio)
			alumno_mejor_promedio = alumnos[i];

	printf("\nEl/La alumno/a con mejor promedio es: %s", alumno_mejor_promedio.nombre);
}

void guardar_cantidad_alumnos_por_año_y_division(lista_alumnos_t alumnos, int ML)
{
	FILE *archivo_alumnos;
	int i, año, division, cantidad_alumnos;

	archivo_alumnos = fopen("alumnos_por_año_y_division.txt", "w");
	i = 0;

	while (i < ML)
	{
		año = alumnos[i].año;

		while ((alumnos[i].año == año) && (i < ML))
		{
			cantidad_alumnos = 0;
			division = alumnos[i].division;

			while ((alumnos[i].division == division) && (i < ML))
			{
				cantidad_alumnos++;
				i++;
			}

			fprintf(archivo_alumnos, "%d %d %d\n", año, division, cantidad_alumnos);
		}
	}

	fclose(archivo_alumnos);
}

int main()
{
	lista_alumnos_t alumnos;
	int ML;

	leer_alumnos(alumnos, &ML);
	imprimir_alumnos_por_año_y_division(alumnos, ML);
	imprimir_mejor_promedio(alumnos, ML);
	guardar_cantidad_alumnos_por_año_y_division(alumnos, ML);

	return 0;
}