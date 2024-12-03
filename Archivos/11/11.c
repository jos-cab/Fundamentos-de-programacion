/*
11) Una empresa que transporta carga tiene en un archivo los siguientes datos
de cada viaje:
a. Nro de patente de del camión
b. Destino
c. Costo del viaje
d. Peso de la carga en KG

El archivo está ordenado por nro. de patente.

Se pide:
a. Informar el nro. de patente del camión que realizó más viajes
b. Informar cuántos viajes se realizaron al destino “Córdoba”
c. Grabar en un archivo, para cada camión, número de patente y cantidad de kg.
Transportados en total.
*/

#include <stdio.h>
#include <string.h>

#define MAX_VIAJES 100

typedef struct
{
	int patente;
	char destino[20];
	float costo;
	float peso;
} viaje_t;

typedef viaje_t lista_viajes_t[MAX_VIAJES];

void leer_viajes(lista_viajes_t viajes, int *ML)
{
	FILE *archivo_viajes;

	*ML = 0;
	archivo_viajes = fopen("viajes.txt", "r");

	while (!feof(archivo_viajes))
	{
		fscanf(archivo_viajes, "%d %s %f %f", &viajes[*ML].patente, viajes[*ML].destino, &viajes[*ML].costo, &viajes[*ML].peso);
		(*ML)++;
	}

	fclose(archivo_viajes);
}

void mostrar_patente_mas_viajes(lista_viajes_t viajes, int ML)
{
	int patente_actual, cantidad_viajes_actual;
	int patente_mas_viajes, mayor_cantidad_viajes;

	patente_mas_viajes = viajes[0].patente;
	mayor_cantidad_viajes = 1;
	cantidad_viajes_actual = 1;

	for (int i = 1; i < ML; i++)
	{
		if (viajes[i].patente == viajes[i - 1].patente)
		{
			cantidad_viajes_actual++;
		}
		else
		{
			if (cantidad_viajes_actual > mayor_cantidad_viajes)
			{
				mayor_cantidad_viajes = cantidad_viajes_actual;
				patente_mas_viajes = viajes[i - 1].patente;
			}
			cantidad_viajes_actual = 1;
		}
	}

	if (cantidad_viajes_actual > mayor_cantidad_viajes)
	{
		mayor_cantidad_viajes = cantidad_viajes_actual;
		patente_mas_viajes = viajes[ML - 1].patente;
	}

	printf("\nLa patente del camion con mas viajes es: %d", patente_mas_viajes);
}

void mostrar_viajes_cordoba(lista_viajes_t viajes, int ML)
{
	int viajes_cordoba;

	viajes_cordoba = 0;

	for (int i = 0; i < ML; i++)
		if (strcmp(viajes[i].destino, "Cordoba") == 0)
			viajes_cordoba++;

	printf("\nSe realizaron %d viajes a Cordoba", viajes_cordoba);
}

void guardar_kg_total_por_camion(lista_viajes_t viajes, int ML)
{
	FILE *archivo_kg;
	int i, patente_anterior;
	float kg_total = 0;

	patente_anterior = -1;
	archivo_kg = fopen("kg_total_por_camion.txt", "w");

	for (i = 0; i < ML; i++)
	{
		if (viajes[i].patente != patente_anterior)
		{
			if (patente_anterior != -1)
				fprintf(archivo_kg, "%d %.1f\n", patente_anterior, kg_total);

			patente_anterior = viajes[i].patente;
			kg_total = 0;
		}

		kg_total += viajes[i].peso;
	}

	fprintf(archivo_kg, "%d %.1f\n", patente_anterior, kg_total);

	fclose(archivo_kg);
}

int main()
{
	lista_viajes_t viajes;
	int ML;

	leer_viajes(viajes, &ML);
	mostrar_patente_mas_viajes(viajes, ML);
	mostrar_viajes_cordoba(viajes, ML);
	guardar_kg_total_por_camion(viajes, ML);

	return 0;
}
