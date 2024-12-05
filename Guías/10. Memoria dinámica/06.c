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

int main()
{
	t_alumno *alumno;

	alumno = crear_alumno();

	if (alumno != NULL)
	{
		printf("Alumno creado con éxito\n");

		free(alumno);
	}
	else
	{
		printf("No se pudo reservar la memoria");
	}

	return 0;
}
