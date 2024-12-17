#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int codigo;
	char titulo[30];
	char rubro[25];
	int stock;
} t_libro;

int main(void)
{
	FILE *archivo;
	t_libro aux = {.codigo = 1, .titulo = "Harry Potter y la piedra filos", .rubro = "Fantasia", .stock = 5};
	t_libro aux2 = {.codigo = 2, .titulo = "El nombre del viento", .rubro = "Fantasia", .stock = 10};
	t_libro aux3 = {.codigo = 3, .titulo = "El hobbit", .rubro = "Fantasia", .stock = 15};
	t_libro aux4 = {.codigo = 4, .titulo = "El señor de los anillos", .rubro = "Fantasia", .stock = 20};
	t_libro aux5 = {.codigo = 5, .titulo = "Guerra y Paz", .rubro = "Novela", .stock = 8};
	t_libro aux6 = {.codigo = 6, .titulo = "El aleph", .rubro = "Cuentos", .stock = 12};
	t_libro aux7 = {.codigo = 7, .titulo = "La metamorfosis", .rubro = "Novela", .stock = 18};
	t_libro aux8 = {.codigo = 8, .titulo = "El principito", .rubro = "Cuentos", .stock = 22};

	archivo = fopen("Stock.dat", "wb");

	if (archivo != NULL)
	{
		fwrite(&aux, sizeof(t_libro), 1, archivo);
		fwrite(&aux2, sizeof(t_libro), 1, archivo);
		fwrite(&aux3, sizeof(t_libro), 1, archivo);
		fwrite(&aux4, sizeof(t_libro), 1, archivo);
		fwrite(&aux5, sizeof(t_libro), 1, archivo);
		fwrite(&aux6, sizeof(t_libro), 1, archivo);
		fwrite(&aux7, sizeof(t_libro), 1, archivo);
		fwrite(&aux8, sizeof(t_libro), 1, archivo);

		fclose(archivo);
	}
	else
		printf("No se pudo abrir el archivo Stock.dat");

	return 0;
}
