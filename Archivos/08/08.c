/*
8) Leer un archivo de caracteres que representa un texto formado por oraciones
terminadas en punto.

Calcular la cantidad de monosílabos que hay en el texto, la longitud promedio de
las palabras y la cantidad de palabras.
*/

#include <stdio.h>

int main()
{
	FILE *archivo_texto;
	char caracter;

	int cantidad_monosilabos, cantidad_palabras, longitud_palabra, longitud_total, longitud_actual;

	cantidad_monosilabos = 0;
	cantidad_palabras = 0;
	longitud_palabra = 0;
	longitud_total = 0;

	archivo_texto = fopen("./texto_sin_espacios.txt", "r");

	while (!feof(archivo_texto))
	{
		caracter = fgetc(archivo_texto);

		if (0 < caracter && caracter <= 255)
		{
			if (('a' <= caracter && caracter <= 'z') || ('A' <= caracter && caracter <= 'Z'))
			{
				longitud_palabra++;
			}
			else if (longitud_palabra > 0)
			{
				longitud_total += longitud_palabra;

				// TODO: Hacer una función para hacer la comprobación de monosílabos
				if (longitud_palabra < 3)
					cantidad_monosilabos++;

				longitud_palabra = 0;
				cantidad_palabras++;
			}
		}
	}

	fclose(archivo_texto);

	printf("Cantidad de monosilabos: %d\n", cantidad_monosilabos);
	printf("Cantidad de palabras: %d\n", cantidad_palabras);
	if (cantidad_palabras > 0)
		printf("Longitud promedio de las palabras: %.2g\n", (float)longitud_total / cantidad_palabras);
	return 0;
}