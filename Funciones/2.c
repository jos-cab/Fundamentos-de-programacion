/*
2. Escribir una función que reciba un valor y calcule el factorial del mismo.
Si no se puede calcular el factorial del valor recibido, la función deberá devolver 0,
de lo contrario deberá devolver el valor calculado. 
*/

#include <stdio.h>

unsigned long long factorial(int n)
{
    unsigned long long factorial = 1;
    int i;

    if (n >= 0)
        for (i = 2; i <= n; i++)
            factorial *= i;
    else
        factorial = 0;
    
    
    return factorial;
}

int main()
{
    printf("2! = %llu\n", factorial(2));
    printf("1! = %llu\n", factorial(1));
    printf("0! = %llu\n", factorial(0));
    printf("-1! = %llu\n", factorial(-1));
    return 0;
}
