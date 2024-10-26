/*
15) Dada una serie de números ingresados de a uno.
Indicar mayor, menor y promedio de la serie.
El ingreso de números finaliza cuando el usuario ingresa 0.
*/

#include <stdio.h>

void main()
{
    int numero, mayor, menor, cantidad;
    float promedio;
    mayor = -2147483648; // Menor entero posible para 32 bits
    menor = 2147483647;  // Mayor entero posible para 32 bits
    promedio = 0;
    cantidad = 0;

    do
    {
        printf("Ingrese número (0 para salir): ");
        scanf("%i", &numero);

        if (numero != 0)
        {
            if (numero < menor)
                menor = numero;
            if (numero > mayor)
                mayor = numero;
            
            promedio += numero;
            cantidad++;
        }
    } while (numero != 0);
    
    if (cantidad == 0)
    {
        menor = 0;
        mayor = 0;
    } else
    {
        promedio /= cantidad;
    }

    printf("El mayor de la serie es: %i \n", mayor);
    printf("El menor de la serie es: %i \n", menor);
    printf("El promedio de la serie es: %.2f \n", promedio);
}
