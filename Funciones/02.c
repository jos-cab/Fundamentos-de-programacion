/*
2. Escribir una función que reciba un valor y calcule el factorial del mismo.
Si no se puede calcular el factorial del valor recibido, la función deberá
devolver 0, de lo contrario deberá devolver el valor calculado. 
*/

#include <stdio.h>

unsigned long long int factorial(int n)
{
    unsigned long long int factorial;
    int i;

    if (n < 0)
        factorial = 0;
    else
        factorial = 1;

    for (i = 2; i <= n; i++)
        factorial *= i;
    
    return factorial;
}

int main()
{
    printf("3! = %llu\n", factorial(3));
    printf("2! = %llu\n", factorial(2));
    printf("1! = %llu\n", factorial(1));
    printf("0! = %llu\n", factorial(0));
    printf("-1! = %llu\n", factorial(-1));
    printf("10! = %llu\n", factorial(10));
    return 0;
}
