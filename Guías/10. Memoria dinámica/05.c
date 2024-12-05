/*
5) Escribir un programa el cual reserve memoria dinámica para almacenar una
cantidad n de struct del tipo t_alumno.

El usuario debe ingresar la cantidad n.

Luego solicitar al usuario que ingrese los datos de los n alumnos y almacenarlos
en la memoria previamente reservada.

Mostrar luego todos los datos de todos los alumnos.

Liberar la memoria reservada al finalizar el programa.

typedef struct {
	int padron;
	char nombre[30];
	char apellido[30];
} t_alumno;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int padron;
	char nombre[30];
	char apellido[30];
} t_alumno;

void leer_datos(t_alumno *alumno)
{
	int i;

	printf("Ingrese el padron del alumno: ");
	scanf("%d", &alumno->padron);

	printf("Ingrese el nombre del alumno: ");
	scanf("%s", alumno->nombre);

	printf("Ingrese el apellido del alumno: ");
	scanf("%s", alumno->apellido);

	printf("\n");
}

void mostrar_datos(t_alumno **alumnos, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("Padron alumno %d: %d\n", i + 1, alumnos[i]->padron);
		printf("Nombre alumno %d: %s\n", i + 1, alumnos[i]->nombre);
		printf("Apellido alumno %d: %s\n", i + 1, alumnos[i]->apellido);
		printf("\n");
	}
}

int main()
{
	int n, i;
	t_alumno **alumnos;

	printf("Ingrese la cantidad de alumnos: ");
	scanf("%d", &n);

	// De no funcionar la siguiente línea casetear a t_alumno
	// alumnos =  (t_alumno *)malloc(n * sizeof(t_alumno))
	alumnos = malloc(n * sizeof(t_alumno));

	if (alumnos != NULL)
	{
		for (i = 0; i < n; i++)
		{
			// De no funcionar la siguiente linea casetear a t_alumno
			// alumnos[i] = (t_alumno *)malloc(sizeof(t_alumno));
			alumnos[i] = malloc(sizeof(t_alumno));

			if (alumnos[i] != NULL)
				leer_datos(alumnos[i]);
			else
				printf("No se pudo reservar memoria\n");
		}

		mostrar_datos(alumnos, n);

		free(alumnos);
	}
	else
	{
		printf("No se pudo reservar memoria\n");
	}

	return 0;
}