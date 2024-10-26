/*
14) Una empresa de transporte de pasajeros de larga distancia posee micros de 4
categorías y viaja a 250 localidades de zonas turísticas del país.

No necesariamente todas las temporadas se habilitan las 4 categorías, ni hay
viajes a todas las localidades posibles.

a) Se dispone de un registro de todos los pasajes vendidos en una temporada consistente en:
código de categoría (a, b, c, d),
código de destino (1 a 250 )

y de un listado ordenado por código del nombre de cada localidad de destino.

Se pide informar:
.(1) La cantidad de pasajeros por localidad, por categoría.
.(2) La cantidad de pasajeros por localidad.
.(3) La cantidad de pasajeros por categoría.
.(4) El nombre de la localidad a la que viajó la mayor cantidad de pasajeros.
.(5) El nombre de la localidad a la que viajó la menor cantidad de pasajeros.
*/

#include <stdio.h>

#define MFDESTINO 250
#define MFCATEGORIA 4
#define MFVENTAS 100

typedef int TRegistro[MFCATEGORIA][MFDESTINO];
typedef int TVentas[MFVENTAS][2]; //{{categoria, destino}, {categoria, destino}, ...}
typedef int TCantDestino[MFDESTINO];
typedef int TCantCategoria[MFCATEGORIA];

void vaciar_registro(TRegistro registro)
{
    int i, j;

    for (i = 0; i < MFCATEGORIA; i++)
        for (j = 0; j < MFDESTINO; j++)
            registro[i][j] = 0;
}

void llenar_registro(TRegistro registro, TVentas ventas, int mlventas)
{
    int i, categoria, destino; // categoria y destino son variables para hacer más legible el código

    for (i = 0; i < mlventas; i++)
    {
        // Para rellenar la matriz le resto 1 a categoría y a destino, así uso la primera fila y columna.
        // Esto me permite ingresar en las ventas [1, 1] y se ve reflejado en el registro como [0, 0]
        categoria = ventas[i][0] - 1;
        destino = ventas[i][1] - 1;

        registro[categoria][destino]++;
    }
}

void mostrar_registro(TRegistro registro)
{
    int i, j;

    printf("Cantidad de pasajeros por destino por categoría. \n");
    printf("Filas: categorías, columnas: destinos \n");

    for (i = 0; i < MFCATEGORIA; i++)
    {
        for (j = 0; j < MFDESTINO; j++)
            printf("%d ", registro[i][j]);

        printf("\n");
    }
}

void mostrar_cantidad_destino_categoria(TCantDestino cantidad_pasajeros_destino, TCantCategoria cantidad_pasajeros_categoria)
{
    int i;

    printf("\n");
    printf("Cantidad de pasajeros por destino\n");
    for (i = 0; i < MFDESTINO; i++)
        printf("%d ", cantidad_pasajeros_destino[i]);

    printf("\n");
    printf("Cantidad de pasajeros por categoría\n");
    for (i = 0; i < MFDESTINO; i++)
        printf("%d ", cantidad_pasajeros_categoria[i]);
}

void obtener_cantidad_pasajeros_destino(TRegistro registro, TCantDestino cantidad_pasajeros_destino)
{
    int i, j;

    for (i = 0; i < MFCATEGORIA; i++)
    {
        cantidad_pasajeros_destino[i] = 0;

        for (j = 0; j < MFDESTINO; j++)
            cantidad_pasajeros_destino[i] += registro[j][i];
    }
}

int obtener_cantidad_pasajeros_categoria(TRegistro registro, TCantCategoria cantidad_pasajeros_categoria)
{
    int i, j;

    for (i = 0; i < MFCATEGORIA; i++)
    {
        cantidad_pasajeros_categoria[i] = 0;

        for (j = 0; j < MFDESTINO; j++)
            cantidad_pasajeros_categoria[i] += registro[i][j];
    }
}

void mostrar_mayor_menor_cantidad_pasajeros_destino(int mayor, int menor)
{
    printf("\n");
    printf("Mayor cantidad de pasajeros por destino: %d\n", mayor);
    printf("Menor cantidad de pasajeros por destino: %d\n", menor);
}

void obtener_mayor_menor_cantidad_pasajeros_destino(TCantCategoria cantidad_pasajeros_destino, int *mayor_cantidad, int *menor_cantidad)
{
    int i, indice_mayor, indice_menor;

    *mayor_cantidad = cantidad_pasajeros_destino[0];
    *menor_cantidad = cantidad_pasajeros_destino[0];
    indice_mayor = 0;
    indice_menor = 0;

    for (i = 0; i < MFDESTINO; i++)
        if (cantidad_pasajeros_destino[i] > *mayor_cantidad)
        {
            *mayor_cantidad = cantidad_pasajeros_destino[i];
            indice_mayor = i;
        }
        else if (cantidad_pasajeros_destino[i] < *menor_cantidad)
        {
            *menor_cantidad = cantidad_pasajeros_destino[i];
            indice_menor = i;
        }

    // sumo 1 para obtener el nombre del destino
    *mayor_cantidad = indice_mayor + 1;
    *menor_cantidad = indice_menor + 1;
}

int main()
{
    TRegistro registro;
    TVentas ventas = {{1, 1}, {1, 1}, {2, 3}, {3, 2}, {2, 1}, {3, 1}, {2, 2}}; // categoria: 1 = a, 2 = b, 3 = c, 4 = d. destino: 1 - 250
    TCantDestino cantidad_pasajeros_destino;
    TCantCategoria cantidad_pasajeros_categoria;

    int mlventas, mayor_cantidad_destino, menor_cantidad_destino;
    mlventas = 7;

    vaciar_registro(registro);
    llenar_registro(registro, ventas, mlventas);
    mostrar_registro(registro);

    obtener_cantidad_pasajeros_categoria(registro, cantidad_pasajeros_categoria);
    obtener_cantidad_pasajeros_destino(registro, cantidad_pasajeros_destino);

    mostrar_cantidad_destino_categoria(cantidad_pasajeros_destino, cantidad_pasajeros_categoria);

    obtener_mayor_menor_cantidad_pasajeros_destino(cantidad_pasajeros_destino, &mayor_cantidad_destino, &menor_cantidad_destino);

    mostrar_mayor_menor_cantidad_pasajeros_destino(mayor_cantidad_destino, menor_cantidad_destino);

    return 0;
}
