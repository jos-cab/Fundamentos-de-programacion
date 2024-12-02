# Notas

## Variables

Las variables son usadas para guardar datos ingresados por usuarios o para guardar resultados de operaciones.

```C
#include <stdio.h>

/*
    La función main() es la función principal de cualquier programa en C.
    Puede retornar un valor entero (int) o no retornar nada (void).

    En general, int main() se usa para que el programa indique un código de
    salida al sistema operativo (0 significa que todo salió bien).
*/


int main()
{
    // Todas las variables que se utilizarán se deben definir al inicio
    // Por defecto las variables no definidas (ya sea manualmente con el
    // operador " = " o por entrada del usuario) tienen un valor "basura", aleatorio.
    int numero, cuadrado;

    printf("Ingrese un número: ");
    scanf("%i", &numero);
    // Importante el ampersand (&) para guardar datos ingresados con scanf
    // Se explicará mejor en el apartado de punteros

    printf("número ingresado: %i", numero);

    printf("\n"); // Imprimo salto de línea (Es como apretar la tecla enter)

    cuadrado = numero * numero;

    printf("%i al cuadrado es: %i", numero, cuadrado);

    return 0;
}
```

### Variables de control

Las variables de control (acumuladores) son variables que deben ser **inicializadas** y **actualizadas** de manera uniforme. Hacen que los bucles terminen cuando se deja de satisfacer una **condición**

```C
// Por convención se le llama a la variable de control i. De necesitar más
// se llamarán j, k, ...
int i;

i = 0; // Inicializo la variable de control

// Es importante saber cuando usar for, while y do while
while (i < 10) // Es importante controlar que la condición no genere un bucle infinito
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

## Condiciones de igualdad

Las condiciones de igualdad son diferentes a las asignaciones.

```C
int numero;

numero = 3; // uso =

if(numero == 3) // uso ==
    printf("El número es igual a 3");

// " = " es para asignar
// " == " es para comparar
```

## Funciones

Las funciones tienen un tipo de retorno y un único punto de retorno, a excepción de las funciones recursivas.
sirven para no repetir código, modularizar y hacer más legible nuestros programas.

```C
// Las funciones tienen este aspecto:

tipo nombre_de_funcion(parametros)
{
    cuerpo_de_la_funcion

    return retorno_de_la_funcion // punto de retorno
}
```

-   Tipo: el tipo de dato a retornar (int, void, float, double, long, etc.).

-   Nombre_de_funcion: el nombre la función, util para saber qué hace la función y luego ser llamada en otro lugar del programa.

-   Parametros: variables que se van a utilizar en esa función y que se consiguen externamente a la función.

-   Cuerpo de la funcion: instrucciones propias de la función.

-   Retorno de la funcion: el valor que va a devolver como resultado la función.

Las funciones que no tendrán interacción con el usuario y que su objetivo sea devolver algún valor entonces deberán tener un tipo definido (diferente de void).

Las funciones pueden tener diferentes cantidades de valores retornados según haga falta:

-   Ningún valor: deben ser del tipo void.
-   Un solo valor: deben tener un tipo definido distinto a void.
-   Más de un valor: deben ser de tipo void y recibir como parámetros punteros (se explicará mejor en el apartado de punteros)

### Ejemplos de funciones

```C
void saludar() // No devuelve nada
{
    printf("Hola!\n");
}
```

```C
int sumar(int numero_1, int numero_2) // Devuelve un solo valor de tipo entero
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
```

¿Por qué está mal la última función?

1. El nombre de la función, "resultado", no es claro. Es mejor usar un nombre que describa lo que hace, como "sumar".
2. Las variables "a" y "b" no son descriptivas. Es preferible usar nombres como "numero_1" y "numero_2", que indican claramente su propósito.

Aunque en este caso el código es simple, en funciones más complejas es fundamental mejorar la legibilidad para evitar confusión. Por eso, es preferible utilizar nombres descriptivos y, si es necesario, usar variables intermedias.

En lo personal prefiero no abreviar nombres, como por ejemplo "numero_1" en vez de "num1", porque termina de ser completamente claro el propósito de mis variables o funciones.

```C
// El tipo long int es más grande que int, por lo que puedo hacer cálculos
// con números más grandes
long int factorial(int n)
{
    int i;
    long int resultado;

    resultado = 1;

    // Empiezo en 2 porque así me ahorro multiplicar por 1
    for (i = 2; i <= n; i++) // Importante no empezar en 0
        resultado *= i;

    return resultado;
}
```

```C
#define CANTIDAD_NOTAS 3

float promedio(float nota_1, float nota_2, float nota_3)
{
    float resultado;

    resultado = (nota_1 + nota_2 + nota_3) / CANTIDAD_NOTAS;

    return resultado;
}
```

## Punteros

Los punteros son tipos de variables en donde se guardan direcciones de memoria.
**Importante:** no usar punteros para todo, solo para ingresos de datos o para devolver más de un valor por función.

```C
#include <stdio.h>

int main()
{
    int numero;
    int *puntero; // Declaro el puntero

    numero = 3;

    puntero = &numero; // Al puntero le asigno la dirección de la variable numero

    printf("%i \n", *puntero); // Imprimo lo que hay en la dirección guardada en puntero
    printf("%p \n", puntero); // Imprimo la dirección de memoria guardada en puntero

    return 0;
}

/*
    int *puntero: variable que guarda direcciones de memoria
    &numero: con ampersand tomo la dirección de memoria de la variable número
    *puntero: con asterisco verifico el contenido dentro de la dirección de memoria
*/

/*
    Ej:
    numero está guardada en "8C77FFF724"
    a puntero le asigno "8C77FFF724" (con &)
    muestro lo que hay en "8C77FFF724" (con *)
*/
```

```C
// Leer primero la función main para mejor comprensión

#include <stdbool.h> // Biblioteca para utilizar valores booleanos (true y false)

// De la siguiente manera puedo devolver más de un valor con una función
void es_par_es_positivo(int numero, bool *es_par, bool *es_positivo)
{
    *es_par = numero % 2 == 0; // En la dirección de memoria (enviadas en main) guardo true o false
    *es_positivo = numero > 0;
}

int main()
{
    bool es_par, es_positivo;
    int numero;

    numero = 3;

    // A la función le mando las direcciones de memoria de esas variables
    es_par_es_positivo(numero, &es_par, &es_positivo);

    return 0;
}
```

## Arreglos

Los arreglos son estructuras en donde se pueden guardar datos como lo hacen las variables, pero de una forma ordenada y en mayor cantidad. Pueden ser de tamaño dinámico (se explicará más adelante) o estático, con máximos lógicos y físicos.

```C
#define MF 10 // Máximo físico de 10 elementos

typedef int t_vector[MF]; // Defino vector de máximo 10 elementos

int main()
{
    t_vector vector = {1, 2, 3}; // Hago un vector con 3 elementos
    int ML = 3; // El máximo lógico es la cantidad de elementos definidos en el vector

    return 0;
}

// MF: Cantidad máxima de elementos (no se puede alterar una vez iniciado el programa)
// ML: Cantidad utilizada de elementos (no puede ser mayor a MF)
```

```C
/*
    Notar que tanto los vectores como las matrices (como estructuras de
    cualquier número de dimensiones) no necesitan & para ser modificados por una
    función, ya que siempre se envía un puntero con su referencia.
*/
void invertir_vector(t_vector vector, int ML)
{
    int i, aux;

    /*
        Recorro hasta la mitad del vector porque intercambio la primera mitad
        con la segunda mitad.
        El primero con el último, el segundo con el anteúltimo, etc.
    */

    for (i = 0; i <= ML / 2; i++)
    {
        // Intercambio los elementos
        aux = vector[i];
        vector[i] = vector[ML - 1 - i];
        vector[ML - 1 - i] = aux;
    }
}
```

```C
#include <stdio.h>

#define MF_F 5  // Máximo de 5 filas
#define MF_C 15 // Máximo de 15 columnas

typedef char t_matriz[MF_F][MF_C]; // Matriz de caracteres de máximo 5 filas x 15 columnas

/*
    En este ejemplo la función cargar datos ingresa datos hasta que se ingrese
    un -1.

    La función cargar_datos es de tipo void porque no necesito devolver nada.
*/

void cargar_datos(t_matriz matriz)
{
    int i, j, elemento;

    i = 0;
    elemento = 0; // Lo defino para poder hacer la primera comparación del while

    while ((i < MF_F) && (elemento != -1)) // Por cada fila
    {
        j = 0;

        while ((j < MF_C) && (elemento != -1)) // Por cada elemento de cada fila
        {
            scanf("%i", &elemento); // Ingreso el elemento [i][j]

            /*
                Cuando elemento sea "-1" se guardará en la matríz.
                Para luego saber dónde termina la matríz sin usar máximos
                lógicos recorro hasta encontrar ese -1.
            */

            matriz[i][j] = elemento;

            j++;
        }

        i++;
    }

    // Importante hacer un seguimiento de las variables de control a la hora de
    // programar para que el programa no termine antes ni después.
}
```

## Modularización

El objetivo de modularizar es poder reutilizar el código y simplificar el código. Un módulo debe tener pocas instrucciones, e intentar que cada uno realice una acción específica (sin modularizar de más).

```C
// Sugiero leer el código desde main

#include <stdio.h>
#include <stdbool.h>

void ingresar_numeros(int *numero_1, int *numero_2)
{
    scanf("%i", numero_1);
    scanf("%i", numero_2);

    if (*numero_1 < 0 || *numero_2 < 0)
        printf("Los números deben ser positivos");
    else if (*numero_1 > *numero_2)
        printf("El primer número debe ser mayor o igual al segundo\n\n");
}

bool es_primo(int n)
{
    bool primo;
    int i;

    primo = true;
    i = 2;

    do
        if (n % i == 0)
            primo = false;
        else
            i++;
    while (primo && i < n / 2);

    return primo;
}

// Calculo los numeros primos que hay entre 2 números
void calcular_primos(int numero_1, int numero_2)
{
    int i;

    for (i = numero_1; i < numero_2; i++)
        if (es_primo(i)) // Llamo a otro módulo
            printf("%i ", i);
}

int main()
{
    int numero_1, numero_2;

    ingresar_numeros(&numero_1, &numero_2);
    calcular_primos(numero_1, numero_2);

    return 0;
}
```

---

Si no las leíste, te recomiendo leer [Buenas prácticas](https://github.com/jos-cabrera/Fundamentos-de-programacion/tree/main/Buenas%20pr%C3%A1cticas).

Segunda parte: [Notas 2](https://github.com/jos-cabrera/Fundamentos-de-programacion/tree/main/Notas%202).
