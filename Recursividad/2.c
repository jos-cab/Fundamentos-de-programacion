/*
2) Desarrollar un programa que calcule y muestre por pantalla los primeros N
términos de la sucesión de Fibonacci en forma recursiva.
*/

#include <stdio.h>

int fibonacci(int n)
{
    if (n == 1)
        return 1;
    else if (n < 1)
        return 0;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    printf("0: %d\n", fibonacci(0));
    printf("1: %d\n", fibonacci(1));
    printf("2: %d\n", fibonacci(2));
    printf("3: %d\n", fibonacci(3));
    printf("4: %d\n", fibonacci(4));
    printf("15: %d\n", fibonacci(15));
    return 0;
}
