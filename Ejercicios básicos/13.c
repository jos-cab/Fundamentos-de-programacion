/*
13) Solicitar un número entero positivo al usuario y calcular su factorial.

En el caso de ingresar un número negativo mostrar un mensaje que diga 
“no se puede calcular el factorial del número ingresado”.

Recordar que por definición factorial(0)=1 y factorial(1)=1
*/

#include <stdio.h>

void main()
{
    int numero, factorial, i;
    factorial = 1;

    printf("Ingrese número entero positivo para calcular su factorial: ");
    scanf("%i", &numero);

    if (numero < 0)
        printf("no se puede calcular el factorial del número ingresado");
    else
    {
        for (i = 1; i <= numero; i++)
            factorial *= i;

        printf("%i! = %i", numero, factorial);
    }
}
