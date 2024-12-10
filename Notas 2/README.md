# Notas 2

## Cadenas

Las cadenas son vectores de caracteres con un carácter especial NULO ('\0') al final para indicar el fin de la cadena.

### Declaración, entrada y modificación

```C
// Se pueden declarar de las siguientes formas:

char cadena_1[15] = "Hola Mundo 1";
char cadena_2[] = "Hola Mundo 2";
char cadena_3[20];
char cadena_4[] = {'h', 'o', 'l', 'a', ' ', 'm', 'u', 'n', 'd', 'o', '\0'};
```

```C
// Leo de stdin (entrada por terminal) 20 caracteres y los guardo en "domicilio"
fgets(domicilio, 20, stdin);

// Cambio el 4 caracter (0 es el primero) de la cadena de domicilio por "X"
domicilio[3] = 'X'; // entre [] va la posición

// Limpio el buffer
fflush(stdin);

```

### String.h

`<string.h>` es una biblioteca con funciones útiles para manipular cadenas.

```C
strlen(cadena); // Devuelve la cantidad de caracteres (sin contar \0).
strcpy(cadena_destino, "valor"); // Copia un nuevo valor en la cadena destino.
strcat(cadena_1, cadena_2); // Concatena cadena_2 al final de cadena_1 (si hay espacio suficiente).
strcmp(cadena_1, cadena_2); // Compara dos cadenas.
// Retorna 0 si son iguales.
// Retorna un valor positivo si cadena_1 es mayor (antes en orden alfabético).
// Retorna un valor negativo si cadena_1 es menor.
strstr(cadena_2, cadena_1); // Busca cadena_1 dentro de cadena_2.
// Retorna un puntero a la primera aparición o NULL si no se encuentra.
```

## Archivos

Un archivo es una colección de datos relacionados, almacenados como una unidad en un dispositivo.

-   No tiene un tamaño fijo (es dinámico).
-   Su límite depende del medio de almacenamiento.

**Tipos de archivos**:

1. Binarios
2. De texto:
    - Delimitados por coma (CSV).
    - Sin delimitadores (TXT).
    - Con otros delimitadores (tabulaciones, longitud fija).

**Modalidad de acceso**:

1. Secuenciales:

    - Se procesan elemento por elemento, desde el inicio hasta el fin del archivo (EOF).
    - Los elementos existentes no pueden modificarse.
    - Solo es posible agregar elementos al final.

2. Directo o aleatorio:
    - Se accede directamente a un elemento específico mediante su posición.
    - Permite modificar elementos existentes y agregar nuevos al final.

```C
FILE *nombre; // Puntero de archivo

archivo = fopen("ruta/nombre_archivo", "modo_apertura"); // Apertura de archivo
/*
	Modos de Apertura:

	r: Solo lectura (el archivo debe existir).
	r+: Lectura y escritura (el archivo debe existir).
	w: Escritura (sobrescribe el archivo o lo crea si no existe).
	a: Agregar datos al final del archivo.
	b: Indica que el archivo es binario.
*/
```

```C
FILE *archivo;
archivo = fopen("productos.dat", "r+");
```

```C
// Lectura de archivo binario

fread(puntero, tamaño, cantidad, archivo); // Leo el archivo binario
/*
	puntero: Dirección donde se almacenará la información leída.
	tamaño: Cantidad de bytes a leer por elemento.
	cantidad: Número de elementos a leer.
	archivo: Puntero al archivo.
*/

// Ejemplo:
fread(&registro, sizeof(registro), 1, archivo);
// sizeof calcula el tamaño en bytes de una variable o registro.
```

```C
// Lectura de archivo de texto
fgetc(archivo); // Lee un caracter
fgets(cadena, cantidad, archivo); // lee línea por línea
fscanf(archivo, "%s", cadena); // Lee datos con formato
```

```C
// Escritura de archivos binarios
fwrite(puntero, tamaño, cantidad, archivo);

// Ejemplo:
fwrite(&registro, sizeof(registro), 1, archivo);
```

```C
// Escritura de archivos de texto
fputc(archivo);
fputs(cadena, archivo);
fprintf(archivo, "%s", cadena);
```

```C
FILE *archivo;
char caracter;

archivo = fopen("archivo.txt", "r");

if (archivo != NULL) // Verifico si se pudo abrir el archivo
{
	// La función feof devuelve 0 si alcanzó el final del archivo.
	// De lo contrario devuelve otro valor.
	while (!feof(archivo)) {
		caracter = fgetc(archivo);
		printf("%c", caracter);
	}

	fclose(archivo); // No olvidar cerrar el archivo
} else
{
	printf("No se puedo abrir el archivo.\n");
}
```

A demás `getchar()` es una funcion que detiene la ejecución del programa y espera a que el usuario teclee un caracter.

## Registros

También llamados estructuras, son tipo de datos que almacenan campos, y cada campo almacena datos del tipo declarado.

```C
struct alumno
{
	char nombre[30];
	int padron;
	int notas[3];
	float promedio;
	char mail[35];
};
```

```C
typedef struct
{
	char nombre[30];
	int padron;
	int notas[3];
	float promedio;
	char mail[35];
} alumno;

int main()
{
	alumno alumno_1; // Declaro un alumno

	alumno_1.notas[0] = 7; // Defino la primera nota del alumno

	return 0;
}
```

## Memoria dinámica

Es necesario incluir `<stdlib.h>`.

```C
int *numeros;
int cantidad_numeros;

// Luego del ingreso de cantidad_numeros

// Hago que numeros sea un vector de tamaño cantidad_numeros
numeros = malloc(cantidad_numeros * sizeof(int));

/*
	Existen también:

	calloc(): Solicita memoria inicializada en 0.
	calloc(cantidad_numeros, sizeof(int))

	realloc(): Cambia el tamaño de un bloque de memoria previamente asignado.
	realloc(numeros, sizeof(int) * cantidad_numeros)
*/

if (numeros != NULL) // Me fijo si no hubo errores al asignar la memoria
	free(numeros); // Importante liberar la memoria
else
	printf("No se pudo reservar la memoria");

```

---

Si no las leíste, te recomiendo leer [Buenas prácticas](../Buenas%20prácticas/).

Primera parte: [Notas](../Notas/).
