/*
1) Desarrollar un programa que calcule la factorial de un número en forma
recursiva.
*/

#include <stdio.h>

int factorial(int n)
{

    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

int main()
{
    printf("5! = %d\n", factorial(5));
    printf("1! = %d\n", factorial(1));
    printf("0! = %d\n", factorial(0));
    return 0;
}
