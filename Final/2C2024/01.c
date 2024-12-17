/*
1. Una librería posee un archivo denominado Stock.dat, cuyos registros contienen
el código de libro(entero), título (30 caracteres), rubro(25 caracteres),
stock (entero).

Se pide desarrollar un programa modular en lenguaje C que procese este archivo
y que permita:

a. Ingresar rubro y armar una tabla con aquellos libros del mismo rubro.

b. Mostrar aquellos que superen el promedio de stock de la tabla.

Asumir que la tabla tendrá como máximo 100 registros y que CABE EN MEMORIA.
*/

#include <stdio.h>
#include <string.h>

#define MF 100

typedef struct
{
	int codigo;
	char titulo[30];
	char rubro[25];
	int stock;
} t_libro;

typedef t_libro t_libros[MF];
typedef char t_rubro[25];

void generar_tabla_por_rubro(t_libros libros, int *ML, t_rubro rubro)
{
	FILE *archivo;
	t_libro aux;

	archivo = fopen("Stock.dat", "rb");
	*ML = 0;

	if (archivo != NULL)
	{
		while (!feof(archivo))
		{
			fread(&aux, sizeof(t_libro), 1, archivo);

			// Si no pongo !feof(archivo) lee dos veces el último libro de Stock.dat
			if ((!feof(archivo)) && (strcmp(aux.rubro, rubro) == 0))
			{
				libros[*ML] = aux;
				(*ML)++;
			}
		}

		fclose(archivo);
	}
	else
		printf("No se pudo abrir el archivo Stock.dat");
}

void obtener_rubro(t_rubro rubro)
{
	printf("Ingrese rubro: ");
	fgets(rubro, 25, stdin);

	rubro[strlen(rubro) - 1] = '\0'; // Borrar \n
}

int obtener_promedio_stock(t_libros libros, int ML)
{
	int i, promedio;

	for (i = 0; i < ML; i++)
		promedio += libros[i].stock;

	promedio /= ML;

	return promedio;
}

void mostrar_tabla_por_stock(t_libros libros, int ML, int promedio_stock)
{
	int i;

	printf("Libros con stock mayor al promedio:\n");

	for (i = 0; i < ML; i++)
		if (libros[i].stock > promedio_stock)
		{
			printf("Código: %i\n", libros[i].codigo);
			printf("Título: %s\n", libros[i].titulo);
			printf("Rubro: %s\n", libros[i].rubro);
			printf("Stock: %i\n", libros[i].stock);

			/*
				Forma alternativa:

				printf("%i %s %s %i\n", libros[i].codigo, libros[i].titulo, libros[i].rubro, libros[i].stock);
			*/
		}
}

int main()
{
	t_libros libros;
	int ML, promedio_stock;
	t_rubro rubro;

	obtener_rubro(rubro);
	generar_tabla_por_rubro(libros, &ML, rubro);

	if (ML > 0)
	{
		promedio_stock = obtener_promedio_stock(libros, ML);
		mostrar_tabla_por_stock(libros, ML, promedio_stock);
	}

	return 0;
}

/*
Contenidos de stock.dat:

1 Harry Potter y la piedra filos Fantasia 5
2 El nombre del viento Fantasia 10
3 El hobbit Fantasia 15
4 El señor de los anillos Fantasia 20
5 Guerra y Paz Novela 8
6 El aleph Cuentos 12
7 La metamorfosis Novela 18
8 El principito Cuentos 22
*/