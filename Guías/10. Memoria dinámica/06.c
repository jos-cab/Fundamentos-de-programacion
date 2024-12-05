/*
6) Implementar una función que retorna un puntero a un struct del tipo t_alumno,
el cual apunta a un bloque de memoria dinámica, respetando la siguiente
declaración.

En caso de no poder reservar la memoria, retornar NULL.

t_alumno* crear_alumno();

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

t_alumno *crear_alumno()
{
	return malloc(sizeof(t_alumno));
}

void ingresar_datos(t_alumno *alumno)
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

	alumno = crear_alumno();

	if (alumno != NULL)
	{
		ingresar_datos(alumno);
		mostrar_datos(alumno);

		free(alumno);
	}
	else
	{
		printf("No se pudo reservar la memoria");
	}

	return 0;
}
