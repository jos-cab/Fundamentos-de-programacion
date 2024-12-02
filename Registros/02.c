/*
2) Se tienen datos de empleados de una empresa según la siguiente estructura:

Apellido, Nombre.
Legajo
Dirección: Calle, N°, Localidad, Provincia, Código Postal.
Fecha de Nacimiento: Día, Mes, Año.
Fecha de Ingreso: Día, Mes, Año.

Se pide hacer un programa que almacene los datos de todos los empleados en una
tabla en memoria y que permita obtener un listado ordenado por pantalla según
distintos ítems, como, por ejemplo, por Apellido y Nombre, por número de legajo,
por edad, por antigüedad, por localidad.

Utilizar un esquema tipo menú.
*/

#include <stdio.h>
#include <string.h>

#define MAX_CANTIDAD_EMPLEADOS 100
#define MAX_NOMBRE 35
#define AÑO_ACTUAL 2024
#define MES_ACTUAL 12
#define DIA_ACTUAL 1

typedef struct
{
    char apellido[MAX_NOMBRE];
    char nombre[MAX_NOMBRE];

    unsigned short int legajo;

    char calle[MAX_NOMBRE];
    unsigned short int numero_calle;
    char localidad[MAX_NOMBRE];
    char provincia[MAX_NOMBRE];
    unsigned short int codigo_postal;

    unsigned short int dia_nacimiento;
    unsigned short int mes_nacimiento;
    unsigned short int año_nacimiento;

    unsigned short int dia_ingreso;
    unsigned short int mes_ingreso;
    unsigned short int año_ingreso;
} empleado;

typedef empleado lista_empleados[MAX_CANTIDAD_EMPLEADOS];

void mostrar_empleados(lista_empleados empleados, int ML)
{
    int i;

    printf("Nombre completo, Legajo, Domicilio, Localidad, Provincia, Código Postal, Fecha de nacimiento, Fecha de ingreso\n\n");

    for (i = 0; i < ML; i++)
    {
        printf("%s %s, %i, %s %i, %s, %s, %i, %i/%i/%i, %i/%i/%i\n",
               empleados[i].apellido, empleados[i].nombre, empleados[i].legajo,
               empleados[i].calle, empleados[i].numero_calle,
               empleados[i].localidad, empleados[i].provincia,
               empleados[i].codigo_postal, empleados[i].dia_nacimiento,
               empleados[i].mes_nacimiento, empleados[i].año_nacimiento,
               empleados[i].dia_ingreso, empleados[i].mes_ingreso,
               empleados[i].año_ingreso);
    }
}
void ordenar_empleados_por(int campo, lista_empleados empleados, int ML)
{
    int i, j;
    int comparacion;
    empleado temp;

    comparacion = 0;

    for (i = 0; i < ML - 1; i++)
        for (j = 0; j < ML - i - 1; j++)
        {
            switch (campo)
            {
            case 1:
                comparacion = strcmp(empleados[j].apellido, empleados[j + 1].apellido) ||
                              (strcmp(empleados[j].apellido, empleados[j + 1].apellido) == 0 &&
                               strcmp(empleados[j].nombre, empleados[j + 1].nombre));
                break;
            case 2:
                comparacion = empleados[j].legajo > empleados[j + 1].legajo;
                break;
            case 3:
                comparacion = empleados[j].año_nacimiento >
                                  empleados[j + 1].año_nacimiento ||
                              (empleados[j].año_nacimiento ==
                                   empleados[j + 1].año_nacimiento &&
                               empleados[j].mes_nacimiento >
                                   empleados[j + 1].mes_nacimiento) ||
                              (empleados[j].año_nacimiento ==
                                   empleados[j + 1].año_nacimiento &&
                               empleados[j].mes_nacimiento ==
                                   empleados[j + 1].mes_nacimiento &&
                               empleados[j].dia_nacimiento >
                                   empleados[j + 1].dia_nacimiento);
                break;
            case 4:
                comparacion = empleados[j].año_ingreso >
                                  empleados[j + 1].año_ingreso ||
                              (empleados[j].año_ingreso ==
                                   empleados[j + 1].año_ingreso &&
                               empleados[j].mes_ingreso >
                                   empleados[j + 1].mes_ingreso) ||
                              (empleados[j].año_ingreso ==
                                   empleados[j + 1].año_ingreso &&
                               empleados[j].mes_ingreso ==
                                   empleados[j + 1].mes_ingreso &&
                               empleados[j].dia_ingreso >
                                   empleados[j + 1].dia_ingreso);
                break;
            case 5:
                comparacion = strcmp(empleados[j].localidad, empleados[j + 1].localidad);
                break;
            }

            if (comparacion > 0)
            {
                temp = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = temp;
            }
        }
}

int main()
{
    int campo_num;
    int ML;

    ML = 10;

    /* Datos generados con IA */
    lista_empleados empleados = {
        {"Pérez", "Juan", 1001, "Calle Falsa", 123, "Buenos Aires", "Buenos Aires", 1000, 15, 5, 1985, 1, 3, 2010},
        {"Gómez", "Ana", 1002, "Av. Libertador", 456, "CABA", "Buenos Aires", 1001, 22, 8, 1990, 5, 6, 2015},
        {"Lopez", "Carlos", 1003, "Diagonal Norte", 789, "La Plata", "Buenos Aires", 1900, 30, 11, 1980, 15, 1, 2012},
        {"Martínez", "Lucía", 1004, "Callejón del Sol", 321, "Rosario", "Santa Fe", 2000, 3, 7, 1987, 10, 10, 2014},
        {"Rodríguez", "Pedro", 1005, "Ruta 9", 45, "San Miguel", "Buenos Aires", 1665, 10, 3, 1982, 20, 1, 2018},
        {"Fernández", "Laura", 1006, "Av. Santa Fe", 2020, "Mar del Plata", "Buenos Aires", 7600, 14, 9, 1992, 12, 5, 2017},
        {"Álvarez", "Martín", 1007, "Calle Vuelta", 789, "Mendoza", "Mendoza", 5500, 5, 12, 1986, 7, 4, 2013},
        {"Hernández", "Elena", 1008, "Calle Paraná", 100, "Tucumán", "Tucumán", 4000, 17, 6, 1994, 6, 8, 2019},
        {"Sánchez", "Raúl", 1009, "Av. 9 de Julio", 501, "CABA", "Buenos Aires", 1002, 22, 11, 1980, 15, 7, 2016},
        {"Díaz", "Sofía", 1010, "Calle Brasil", 231, "Salta", "Salta", 4400, 8, 3, 1991, 1, 2, 2020}};

    printf("Ingrese el número del campo por el cual desea ordenar los empleados:\n");
    printf("1. Nombre y Apellido\n2. Legajo\n3. Edad\n4. Antigüedad\n5. Localidad\n");
    printf("\n> ");
    scanf("%d", &campo_num);

    ordenar_empleados_por(campo_num, empleados, ML);
    mostrar_empleados(empleados, ML);

    return 0;
}
