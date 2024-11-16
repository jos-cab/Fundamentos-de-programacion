/*
1) Se tienen los siguientes datos de los empleados de una empresa:
Apellido y Nombre (35 caracteres)
Fecha de Nacimiento (día, mes y año)
Fecha de Ingreso (día, mes y año)
Sueldo Básico

Se conoce la cantidad N de empleados y la fecha de procesamiento.

Se pide: Imprimir un listado con los apellidos y nombres de las personas que
cumplan años en el mes y calcular e informar una suma de regalo equivalente al
uno por mil del sueldo por cada año cumplido.
*/

#include <stdio.h>

#define MAX_CANTIDAD_EMPLEADOS 100
#define MAX_NOMBRE 35
#define MES_ACTUAL 11
#define AÑO_ACTUAL 2024

typedef struct
{
    char apellido[MAX_NOMBRE];
    char nombre[MAX_NOMBRE];
    
    unsigned short int dia_nacimiento;
    unsigned short int mes_nacimiento;
    unsigned short int año_nacimiento;

    unsigned short int dia_ingreso;
    unsigned short int mes_ingreso;
    unsigned short int año_ingreso;
    
    float sueldo_basico;
} empleado;

typedef empleado lista_empleados[MAX_CANTIDAD_EMPLEADOS];

int main()
{
    int i;
    unsigned short int ML = 10;
    
    /* Datos generados con IA */
    lista_empleados empleados = {
        { "Perez", "Juan", 15, 3, 1990, 1, 6, 2015, 45000.50 },
        { "Gomez", "Ana", 28, 8, 1985, 12, 10, 2010, 38000.00 },
        { "Lopez", "Carlos", 5, 11, 1980, 17, 3, 2018, 50000.75 },
        { "Martinez", "Laura", 22, 1, 1995, 3, 9, 2017, 42000.00 },
        { "Rodriguez", "Luis", 10, 4, 1992, 20, 7, 2020, 48000.00 },
        { "Fernandez", "Maria", 17, 11, 1987, 5, 5, 2013, 46000.00 },
        { "Diaz", "Javier", 2, 12, 1983, 1, 4, 2014, 49000.25 },
        { "Sanchez", "Monica", 30, 6, 1991, 10, 9, 2016, 47000.40 },
        { "Ramirez", "Andres", 11, 2, 1978, 6, 6, 2012, 52000.00 },
        { "Jimenez", "Patricia", 14, 5, 1989, 21, 3, 2019, 43000.00 }
    };

    for (i = 0; i < ML; i++)
        if (empleados[i].mes_nacimiento == MES_ACTUAL)
        {
            printf("%s %s\n", empleados[i].apellido, empleados[i].nombre);
            printf("Regalo: %i\n", 1000 * (AÑO_ACTUAL - empleados[i].año_ingreso));
        }

    return 0;
}