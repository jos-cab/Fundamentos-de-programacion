/*
3) Escribir una función que dado un número entero, devuelva una señal que indique
si dicho número es primo o no.
*/

#include <stdio.h>
#include <stdbool.h>

bool es_primo(int numero)
{
    int i;
    bool primo;

    i = 2;
    primo = true;

    while (i < numero / 2 && primo)
    {
        if (numero % i == 0)
            primo = false;
        else
            i++;
    }

    return primo;
}

int main()
{
    if (es_primo(3))
        printf("3 es primo");
    else
        printf("3 no es primo");

    printf("\n");

    if (es_primo(7))
        printf("7 es primo");
    else
        printf("7 no es primo");

    printf("\n");

    if (es_primo(10))
        printf("10 es primo");
    else
        printf("10 no es primo");

    printf("\n");

    if (es_primo(100))
        printf("100 es primo");
    else
        printf("100 no es primo");

    printf("\n");

    return 0;
}
