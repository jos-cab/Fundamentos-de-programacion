# Notas

1. Las variables son usadas para guardar datos ingresados por usuarios o para guardar resultados de operaciones.

**Importante:** las variables deben ser definidas o por el usuario (scanf) o manualmente.
No se pueden imprimir o hacer comparaciones con variables que no tienen ningún valor, porque por defecto C les asigna un valor "basura".
Esto quiere decir que en general una variable no definida guarda un número random.

```C
#include <stdio.h>

// Es posible también hacer que la función main sea de tipo void, en tal caso no
// es necesario retornar 0.

// Se explicará mejor después el tema de retornos en funciones.

// Por ahora lo más importante es que int (entero) debe retornar un número
// y void (vacío) no devuelve nada.

int main()
{
    // Todas las variables que se utilizarán se deben definir al inicio
    int numero, cuadrado;

    printf("Ingrese un número: ");
    scanf("%i", &numero);
    // Importante el ampersand (&) para guardar datos ingresados con scanf

    printf("número ingresado: %i", numero);

    printf("\n"); // Imprimo salto de línea (Es como apretar la tecla enter)

    cuadrado = numero * numero;

    printf("%i al cuadrado es: %i", numero, cuadrado);

    return 0;
}
```

2. Las variables de control (acumuladores) son variables que deben ser **inicializadas** y **actualizadas** de manera uniforme. Hacen que los bucles terminen cuando se deja de satisfacer una **condición**

```C
// Por convención se le llama a la variable de control i. De necesitar más
// se llamarán j, k, ...
int i;

i = 0; // Inicializo la variable de control

// Es importante saber cuando usar for, while y do while
while(i < 10) // Es importante controlar que la condición no genere un bucle infinito
    i++; // Nunca olvidar actualizar la variable de control para no generar bucle infinito

// En el bucle anterior la variable de control tomará valores de 0 a 9
```

```C
int i;

i = 3;

do
{
    i++;
} while(i <= 5);
// La diferencia entre while y do while es que do while primero realiza una
// iteración y luego hace la comparación.

// En el bucle anterior la variable de control tomará valores de 3 a 5
```

```C
int i;

// En el bucle for se definen los tres pasos subrallados en negrita:
// definición, condición, actualización
// Pero la declaración de la variable debe estar afuera

// No hacer: for(int i = 0; i < 3; i++)

// Tampoco se debe actualizar la variable de control dentro del bucle for

for(i = 0; i < 3; i++)
    // ...

// En el bucle anterior la variable de control tomará valores de 0 a 2

for(i = 0; i < 10; i += 2)
    // ...

// En el bucle anterior la variable de control tomará los valores: 0, 2, 4, 6 y 8
```

3. Las condiciones de igualdad son diferentes a las asignaciones.

```C
int numero;

numero = 3; // uso =

if(numero == 3) // uso ==
    printf("El número es igual a 3");

// " = " es para asignar
// " == " es para comparar
```
