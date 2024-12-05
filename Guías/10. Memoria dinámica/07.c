/*
7) Implementar una función que retorna un puntero a un vector de n struct del
tipo t_alumno, el cual apunta a un bloque de memoria dinámica, respetando la
siguiente declaración.

En caso de no poder reservar la memoria, retornar NULL.

t_alumno* crear_alumnos(int n);

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

t_alumno *crear_alumnos(int n)
{
	// return (t_alumno *)malloc(n * sizeof(t_alumno));
	return malloc(n * sizeof(t_alumno));
}

int main()
{
	int n;
	t_alumno *alumnos;

	n = 3;
	alumnos = crear_alumnos(n);

	if (alumnos != NULL)
	{
		printf("Alumnos creados conxito\n");

		free(alumnos);
	}
	else
	{
		printf("No se pudo reservar la memoria");
	}

	return 0;
}
