/*
4. Escribir una función que reciba un número y devuelva un valor booleano indicando
si el número recibido es ó no primo.
Si desconoce como devolver un valor booleano, puede devolver 0, en caso de No ser primo; y 1, si lo es.
*/

#include <stdbool.h>
#include <stdio.h>

bool es_primo(int n)
{
    int i;
    bool n_es_primo = true;

    if (n <= 1)
        n_es_primo = false;
    else
        for (i = 2; i < n; i++)
            if (n % i == 0)
                n_es_primo = false; 
        
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
