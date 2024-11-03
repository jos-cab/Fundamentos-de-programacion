/*
13) Solicitar un número entero positivo al usuario y calcular su factorial.

En el caso de ingresar un número negativo mostrar un mensaje que diga 
“no se puede calcular el factorial del número ingresado”.

Recordar que por definición factorial(0)=1 y factorial(1)=1
*/

#include <stdio.h>

int main()
{
    int i;
    short int numero;
    unsigned long long int factorial;
    
    factorial = 1;

    printf("Ingrese número entero positivo para calcular su factorial: ");
    scanf("%hi", &numero);

    if (numero < 0)
        printf("no se puede calcular el factorial del número ingresado");
    else
    {
        for (i = 1; i <= numero; i++)
            factorial *= i;

        printf("%hi! = %llu", numero, factorial);
    }

    return 0;
}
