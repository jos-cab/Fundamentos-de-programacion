/*
6) Se tiene un archivo de números telefónicos cuyos registros son de la forma:
Característica de localidad (4 dígitos)
Característica central (3 dígitos)
Número (4 dígitos)

Dado un número que representa una característica de localidad, listar todos los
números telefónicos con dicha característica.

Suponer los siguientes casos:
a) El archivo no cabe en memoria y está desordenado.
b) El archivo no cabe en memoria y está ordenado según números telefónicos
crecientes.
*/

#include <stdio.h>

#define LOCALIDAD 1234

int main()
{
	FILE *archivo_numeros_telefonicos;
	int caracteristica_localidad, caracteristica_central, numero;

	archivo_numeros_telefonicos = fopen("./numeros_telefonicos.txt", "r");

	while (!feof(archivo_numeros_telefonicos))
	{
		fscanf(archivo_numeros_telefonicos, "%d %d %d", &caracteristica_localidad, &caracteristica_central, &numero);
		if (caracteristica_localidad == LOCALIDAD)
		{
			printf("%04d %03d %04d\n", caracteristica_localidad, caracteristica_central, numero);
		}
	}

	fclose(archivo_numeros_telefonicos);

	return 0;
}
