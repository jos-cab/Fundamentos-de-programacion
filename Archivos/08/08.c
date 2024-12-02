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
	int cantidad_monosilabos = 0;
	int cantidad_palabras = 0;
	int longitud_palabra = 0;
	int longitud_total = 0;

	archivo_texto = fopen("./texto_sin_espacios.txt", "r");

	/*	while (!feof(archivo_texto))
		{
			caracter = fgetc(archivo_texto);

			if (0 < caracter && caracter <= 255)
			{
				switch (caracter)
				{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					cantidad_monosilabos++;
					break;

				case ' ':
				case '\n':
					if (longitud_palabra > 0)
					{
						longitud_total += longitud_palabra;
						cantidad_palabras++;
					}

					longitud_palabra = 0;
					break;
				}
			}

			longitud_palabra++;
		}
	*/
	fclose(archivo_texto);

	printf("Cantidad de monosilabos: %d\n", cantidad_monosilabos);
	printf("Cantidad de palabras: %d\n", cantidad_palabras);
	if (cantidad_palabras > 0)
		printf("Longitud promedio de las palabras: %d\n", longitud_total / cantidad_palabras);
	return 0;
}