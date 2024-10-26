/*
5. Tomá la solución del ejercicio anterior y analizá si elegiste el cliclo adecuado,
y si estás evitando realizar ciclos innecesarios.

Por ejemplo, algunas preguntas que te podrías hacer son:

a) Con sólo encontrar un divisor del número a evaluar distinto a uno y a sí mismo,
ya puedo afirmar que el número no es primo, tiene sentido seguir evaluando más divisores?

b) Teniendo en cuenta que todo número par a excepción del 2, no es primo, tiene sentido seguir en un ciclo,
si al calcular el resto de la división del número a evaluar por 2, el resultado es cero?

c) Puedo encontrar un divisor del número a evaluar que sea mayor al número a evaluar dividido 2?

Modificá la función escrita en el punto anterior, para que tenga en cuenta las situaciones planteadas.
*/

#include <stdbool.h>
#include <stdio.h>

bool es_primo(int n)
{
    int i = 2; // Comienzo evaluando si n es primo desde 2
    bool n_es_primo = true;

    if (n <= 1)
        n_es_primo = false;
    else
        while (i < (n / 2) && n_es_primo)
            if (n % i == 0)
                n_es_primo = false;
            else
                i++;

    return n_es_primo;
}

int main()
{
    if (es_primo(1))
        printf("1 es primo\n");
    else
        printf("1 no es primo\n");

    if (es_primo(2))
        printf("2 es primo\n");
    else
        printf("2 no es primo\n");

    if (es_primo(13))
        printf("13 es primo\n");
    else
        printf("13 no es primo\n");

    if (es_primo(47))
        printf("47 es primo\n");
    else
        printf("47 no es primo\n");

    if (es_primo(100))
        printf("100 es primo\n");
    else
        printf("100 no es primo\n");

    if (es_primo(-1))
        printf("-1 es primo\n");
    else
        printf("-1 no es primo\n");

    return 0;
}
