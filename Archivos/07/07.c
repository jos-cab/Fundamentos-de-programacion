/*
7) Leer un archivo de caracteres que representa un texto formado por oraciones
terminadas en punto.

Copiarlo en otro archivo eliminando los espacios superfluos.
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
	FILE *archivo_texto, *archivo_texto_sin_espacios;
	char caracter;
	bool espacio_leido, punto_leido;
	int i; // indice por línea

	archivo_texto = fopen("./texto.txt", "r");
	archivo_texto_sin_espacios = fopen("./texto_sin_espacios.txt", "w");

	espacio_leido = false;
	punto_leido = false;

	i = 0;

	while (!feof(archivo_texto))
	{
		caracter = fgetc(archivo_texto);

		if (0 < caracter && caracter <= 255)
			if (caracter != '\t' && caracter != ' ')
			{
				fputc(caracter, archivo_texto_sin_espacios);

				if (caracter == '\n')
					i = 0;
				else
				{
					i++;
					if (caracter == '.')
						punto_leido = true;
				}

				espacio_leido = false;
			}
			else if ((i > 0 && !espacio_leido) || (!punto_leido))
			{
				fputc(' ', archivo_texto_sin_espacios);
				espacio_leido = true;
				i++;
			}
	}

	fclose(archivo_texto);
	fclose(archivo_texto_sin_espacios);

	return 0;
}
