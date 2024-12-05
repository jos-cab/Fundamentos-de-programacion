/*
4) Escribir un programa el cual reserve memoria dinámica para almacenar un
struct del tipo t_alumno.

Luego solicitar al usuario que ingrese los datos del alumno y almacenarlos en la
memoria previamente reservada.

Mostrar luego todos los datos del alumno.

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
	printf("Ingrese el padron del alumno: ");
	scanf("%d", &alumno->padron);

	printf("Ingrese el nombre del alumno: ");
	scanf("%s", alumno->nombre);

	printf("Ingrese el apellido del alumno: ");
	scanf("%s", alumno->apellido);
}

void mostrar_datos(t_alumno *alumno)
{
	printf("Padron: %d\n", alumno->padron);
	printf("Nombre: %s\n", alumno->nombre);
	printf("Apellido: %s\n", alumno->apellido);
}

int main()
{
	t_alumno *alumno;

	alumno = malloc(sizeof(t_alumno));

	if (alumno != NULL)
	{
		leer_datos(alumno);
		mostrar_datos(alumno);

		free(alumno);
	}
	else
	{
		printf("No se pudo reservar la memoria");
	}

	return 0;
}
