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

5. Las funciones tienen un tipo de retorno y un único tipo de retorno, a excepción de las funciones recursivas.

```C
// Las funciones tienen este aspecto:

tipo nombre_de_funcion(parametros)
{
    cuerpo_de_la_funcion

    return retorno_de_la_funcion
}

// Las funciones sirven para no repetir código, modularizar y hacer más legible
// nuestros programas

// Tipo: el tipo de dato a retornar (int, void, float, double, long, etc.).
// nombre_de_funcion: el nombre la función, util para saber qué hace la función
// y luego ser llamada en otro lugar del programa.
// parametros: variables que se van a utilizar en esa función y que se consiguen
// externamente a la función.
// cuerpo_de_la_funcion: instrucciones propias de la función
// retorno_de_la_funcion: el valor que va a devolver como resultado la función

// NOTA: Las variables pueden no retornar nada (deben ser del tipo void),
// devolver un valor (deben tener un tipo definido distinto a void), o retornar
// más de un valor (se explicará después, deben ser de tipo void y recibir como
// parámetros punteros).
```

## Ejemplos de funciones

```C
void saludar()
{
    printf("Hola!\n");
}
```

```C
int sumar(int numero_1, int numero_2)
{
    int resultado;

    resultado = numero_1 + numero_2;

    return resultado;
}

// NOTA: El siguiente código hace idénticamente lo mísmo que el anterior, pero
// es buena práctica hacer el código lo más legible posible

int resultado(int a, int b)
{
    return a + b;
}

// "resultado" no me dice qué hace la función.
//
// las variables se llaman a y b pero es más limpio describir que son números
// en vez de retornar diréctamente puedo crear una variable para definir dónde
// voy a guardar el resultado de mi operación, en vez de retornar lo que
// devuelve un cálculo.
//
// En este ejemplo es sencillo entender qué hace el código, pero con código más
// largo se puede llegar a complicar la lectura, por eso es mejor la primera
// solución.
```
