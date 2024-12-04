/*
9) Dos números se dicen amigos cuando uno de ellos es igual a la suma de todos
los divisores del otro excepto el mismo.

Ejemplo:
los números
220 (1+2+4+5+10+11+20+22+44+55+110=284) y
284 (1+2+4+71+142=220)
son amigos.

Se pide:
a) escribir una función booleana que llamada desde un programa, permita
discernir si dos números (parámetros) son amigos.
b) Usar otra función para calcular la suma de los divisores de un número
determinado.
c) Hacer referencia a dichas funciones desde un programa o desde otro
subprograma.
*/

#include <stdio.h>
#include <stdbool.h>

int suma_divisores(int n)
{
    int i, resultado;
    resultado = 0;

    for (i = 1; i < n; i++)
        if (n % i == 0)
            resultado += i;

    return resultado;
}

bool son_amigos(int n, int m)
{
    return ((n == suma_divisores(m)) || (m == suma_divisores(n)));
}

int main()
{
    if (son_amigos(220, 284))
        printf("220 y 284 son amigos");
    else
        printf("220 y 284 no son amigos");

    printf("\n");

    if (son_amigos(100, 200))
        printf("100 y 200 son amigos");
    else
        printf("100 y 200 no son amigos");

    printf("\n");

    return 0;
}
