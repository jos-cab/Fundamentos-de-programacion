/*
4) Una empresa de venta de productos alimenticios posee los siguientes listados:

Listado de Stock:
Código de producto (entero de 4 cifras),
Cantidad en stock (real mayor que cero).

Listado de Productos:
Código de producto (entero de 4 cifras),
Descripción,
Precio unitario.

Listado de Ventas:
Código de producto (entero de 4 cifras),
Cantidad vendida en una venta.

Los listados de Stock y Productos están ordenados por código y no necesariamente
todos los registros de uno están en el otro.

El listado de ventas corresponde a un día y no está ordenado.

Se pide :
a) Listar por pantalla la cantidad total vendida por producto.
b) Listar por pantalla el monto de venta por producto y el monto total.
c) Listar por pantalla el stock actualizado por producto, eliminando de la
misma aquellos productos sin existencia y generando una lista aparte de
faltantes.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_DESCRIPCION 50
#define MAX_LISTA 100

typedef struct
{
	int codigo;
	int cantidad;
} stock_t;

typedef struct
{
	int codigo;
	char descripcion[MAX_DESCRIPCION];
	float precio_unitario;
} productos_t;

typedef struct
{
	int codigo;
	int cantidad;
} ventas_t;

typedef stock_t lista_stock_t[MAX_LISTA];
typedef productos_t lista_productos_t[MAX_LISTA];
typedef ventas_t lista_ventas_t[MAX_LISTA];

typedef int lista_ventas_por_producto_t[MAX_LISTA];
typedef productos_t lista_productos_faltantes_t[MAX_LISTA];

void calcular_cantidad_productos_vendidos(lista_ventas_t ventas, int ML_ventas, lista_productos_t productos_t, int ML_productos, lista_ventas_por_producto_t ventas_por_producto)
{
	int i, j, cantidad_vendida;

	for (i = 0; i < ML_productos; i++)
	{
		cantidad_vendida = 0;

		for (j = 0; j < ML_ventas; j++)
			if (ventas[j].codigo == productos_t[i].codigo)
				cantidad_vendida += ventas[j].cantidad;

		ventas_por_producto[i] = cantidad_vendida;
	}
}

void mostrar_cantidad_productos_vendidos(lista_productos_t productos, lista_ventas_por_producto_t ventas_por_producto, int ML_ventas_por_producto)
{
	int i;

	printf("Cantidad de productos vendidos por producto:\n");

	for (i = 0; i < ML_ventas_por_producto; i++)
		printf("%i %s %i\n", productos[i].codigo, productos[i].descripcion, ventas_por_producto[i]);
}

void mostrar_ventas_por_producto_y_total(lista_productos_t productos, lista_ventas_por_producto_t lista_ventas_por_producto, int ML_productos)
{
	int i;
	float monto_producto, monto_total;

	monto_total = 0;

	printf("Ventas por producto:\n");

	for (i = 0; i < ML_productos; i++)
	{
		// Se garantiza que lista_ventas_por_producto está ordenado a la par de productos
		monto_producto = productos[i].precio_unitario * lista_ventas_por_producto[i];

		printf("%i %s: %.2f\n", productos[i].codigo, productos[i].descripcion, monto_producto);

		monto_total += monto_producto;
	}

	printf("\nMonto total: %.2f\n", monto_total);
}

int buscar_producto(lista_productos_t productos, int ML_productos, int codigo)
{
	int i;
	bool encontrado;

	i = 0;

	while ((!encontrado) && (i < ML_productos))
	{
		if (productos[i].codigo == codigo)
			encontrado = true;
		else
			i++;
	}

	if (!encontrado)
		i = -1;

	return i;
}

void calcular_productos_faltantes(lista_stock_t stock, int ML_stock, lista_productos_t productos, int ML_productos, lista_ventas_por_producto_t ventas_por_producto, lista_productos_faltantes_t productos_faltantes, int *ML_productos_faltantes)
{
	int i, j, cantidad_productos_faltantes, indice_producto;

	// Usado para calcular ML_productos_faltantes y como índice para guardar
	// nuevos productos faltantes.
	cantidad_productos_faltantes = 0;

	for (i = 0; i < ML_stock; i++)
	{
		stock[i].cantidad -= ventas_por_producto[i];

		if (stock[i].cantidad <= 0)
		{
			indice_producto = buscar_producto(productos, ML_productos, stock[i].codigo);

			if (indice_producto != -1)
			{
				productos_faltantes[cantidad_productos_faltantes] = productos[indice_producto];
				cantidad_productos_faltantes++;
			}
			else
			{
				printf("ERROR: No se encontro el producto %i\n", stock[i].codigo);
			}
		}
	}

	*ML_productos_faltantes = cantidad_productos_faltantes;
}

void mostrar_productos_faltantes(lista_productos_faltantes_t productos_faltantes, int ML_productos_faltantes)
{
	int i;

	printf("Productos faltantes:\n");

	for (int i = 0; i < ML_productos_faltantes; i++)
		printf("%i %s\n", productos_faltantes[i].codigo, productos_faltantes[i].descripcion);
}

int main()
{
	int ML_stock, ML_productos, ML_ventas, ML_ventas_por_producto, ML_productos_faltantes;

	lista_stock_t stock = {
		{1001, 150},
		{1002, 40},
		{1003, 16},
		{1004, 50}};

	lista_productos_t productos = {
		{1001, "Pan", 10.00},
		{1002, "Fideos", 20.00},
		{1003, "Leche", 5.00},
		{1004, "Café", 8.00}};

	lista_ventas_t ventas = {
		{1004, 7},
		{1001, 8},
		{1002, 20},
		{1001, 3},
		{1003, 1},
		{1003, 5},
		{1004, 3},
		{1002, 20},
		{1003, 10}};

	lista_ventas_por_producto_t ventas_por_producto; // Hago una lista para simplificar la lista_ventas_t
	lista_productos_faltantes_t productos_faltantes;

	ML_stock = 4;
	ML_productos = 4;
	ML_ventas = 9;

	ML_ventas_por_producto = ML_productos;

	calcular_cantidad_productos_vendidos(ventas, ML_ventas, productos, ML_productos, ventas_por_producto);
	mostrar_cantidad_productos_vendidos(productos, ventas_por_producto, ML_ventas_por_producto);

	printf("\n");

	mostrar_ventas_por_producto_y_total(productos, ventas_por_producto, ML_ventas_por_producto);

	printf("\n");

	calcular_productos_faltantes(stock, ML_stock, productos, ML_productos, ventas_por_producto, productos_faltantes, &ML_productos_faltantes);
	mostrar_productos_faltantes(productos_faltantes, ML_productos_faltantes);
	return 0;
}
