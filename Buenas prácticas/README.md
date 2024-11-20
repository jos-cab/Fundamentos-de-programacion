# Buenas prácticas a la hora de programar para la materia

1. Usar comentarios, pero no de más.

```C
// ❌
// Agrego la biblioteca para usar bool
#include <stdbool.h>

// ✅
// Doy vuelta el vector
for (i = 0; i < ML / 2; i++)
{
    aux = vector[i];
    vector[i] = vector[ML - i - 1];
    vector[ML - i - 1] = aux;
}

```

2. Nombrar variables descriptivamente, con el mismo formato y al inicio de la función.

```C
// ❌
int x, y, z;
int numero1, numero_2, tercerNumero;

// ...

int i;

for(i = 0; i < ML; i++)
    // ...

// ✅
int numero_1, numero_2, numero_3;
int i;

// ...

for(i = 0; i < ML; i++)
    // ...
```

3. Declarar las variables al inicio del scope (incluso las utilizadas por búcles).

```C
// ❌
int numero; // variable gloabal

void main()
{
    numero = 3;

    for(int i = 0; i < numero; i++)
        // ...
}

// ✅
void main()
{
    int numero, i; // variables locales
    numero = 3;

    for(i = 0; i < numero; i++)
        // ...
}
```

4. Usar el bucle correcto.

```C
// ❌
// Busco un número en una lista
int i;

for(i = 0; i < ML; i++)
    if(vector[i] == x)
        encontrado = true;

// ✅
int i;

i = 0;

while(!encontrado && i < ML) // Salgo si lo encontré
{
    if(vector[i] == x)
        encontrado = true;

    i++;
}
```

5. No modificar la variable de control de manera erronea.

```C
// ❌
for(i = a; i >= b; i--)
{
    // ...
    i = divisor; // cambio la variable de control
    // ...
}

// ✅
// La variable de control solo debe servir como contador
// O de manera tal que solo incremente o decremente en una cantidad fija
int i;

i = a;

while(i >= b)
{
    // ...

    i--; // decrementa una unidad
}
```

6. No usar breaks dentro de loops.

```C
// ❌
int i;

for(i = 0; i < ML; i++)
    if(vector[i] == x)
    {
        encontrado = true;
        break; // Salgo del bucle
    }
```

7. No usar continue.

```C
// ❌

for(i = 0; i < ML; i++)
    if(vector[i] % 2 == 0)
        hay_par = true;
    else
        continue; // Sigo con la siguiente iteración
```

8. No repetir código.

```C
// ❌
printf("Ingrese un número: ");
scanf(%i, &numero);

while(numero != 0)
{
    // ...
    printf("Ingrese un número: ");
    scanf(%i, &numero);
}

// ✅
do {
    printf("Ingrese un número: ");
    scanf(%i, &numero);
    // ...
} while(numero != 0);
```

9. Modularizar.

```C
// ❌
void encontrar_mayor_contar_pares_validar_fecha_y_preparar_cafe(/*...*/);

// ✅
int encontrar_mayor(/*...*/);
int obtener_cantidad_pares(/*...*/);
bool validar_fecha(/*...*/);
void preparar_cafe(/*...*/);
```

10. No tener varios puntos de retorno, excepto en funciones recursivas.

```C
// ❌
bool validar_fecha(int dia, int mes, int año)
{
    bool fecha_valida;

    fecha_valida = false;

    if (!(1 <= mes && mes <= 12))
        return false; // Ya se que la fecha está mal

    switch(mes)
        //...

    return fecha_valida;
}

// ✅
unsigned long int factorial(int n)
{
    if(n == 0)
        return 1;

    return (n * factorial(n - 1));
}
```

11. Los nombres de las funciones deben hacer precisamente lo que su nombre indica.

```C
// ❌
void ordenar_vector(t_vector vector, int ML)
{
    // ...

    printf("El vector ordenado es: ")
    for(i = 0; i < ML; i++)
        printf("%i ", vector[i]);
}

// ✅
void ordenar_y_mostrar_vector(t_vector vector, int ML)
{
    // ...

    printf("El vector ordenado es: ")
    for(i = 0; i < ML; i++)
        printf("%i ", vector[i]);
}
```

12. Las funciones cuyos parámetros incluyen al menos un puntero deben ser del tipo void.

```C
// ❌
int obtener_mayor_digito_y_frecuencia(int numero,
                                      int *mayor_digito)
{
    int frecuencia_mayor_digito, digito;

    // ...
    *mayor_digito = digito;
    // ...

    return frecuencia_mayor_digito;
}

// ✅
void obtener_mayor_digito_y_frecuencia(int numero,
                                       int *mayor_digito,
                                       int *frecuencia)
{
    int digito;

    // ...
    *mayor_digito = digito;
    // ...
    (*frecuencia)++; // Los paréntesis son necesarios
    // ...
}
```

---

Ver [Notas](https://github.com/jos-cabrera/Fundamentos-de-programacion/blob/main/Notas/README.md) para más info.
