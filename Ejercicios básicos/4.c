/*
4) Calcular y mostrar la suma de los n primeros números naturales. 
Siendo n un número ingresado por el usuario.
Usar fórmula [ n.(n+1) ] / 2
*/

#include <stdio.h>

int main()
{
    unsigned int n;
    unsigned long resultado;

    printf("Ingrese un número para mostrar suma de los primeros n numeros naturales: ");
    scanf("%u", &n);
    
    resultado = (n * (n + 1)) / 2;

    printf("El resultado es: %lu", resultado);

    return 0;
}
