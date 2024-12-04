/*
15) Dada una serie de números ingresados de a uno.
Indicar mayor, menor y promedio de la serie.
El ingreso de números finaliza cuando el usuario ingresa 0.
*/

#include <stdio.h>

int main()
{
    int numero, mayor, menor;
    unsigned short int cantidad;
    float promedio;

    // Primer ingreso para guardar mayor y menor
    printf("Ingrese número (0 para salir): ");
    scanf("%i", &numero);
    mayor = numero;
    menor = numero;
    promedio = numero;
    cantidad = 1;
    
    while (numero != 0)
    {
        printf("Ingrese número (0 para salir): ");
        scanf("%i", &numero);

        if (numero != 0)
        {
            if (numero < menor)
                menor = numero;
            else if (numero > mayor)
                mayor = numero;
            
            promedio += numero;
            cantidad++;
        }
    }
    
    if (cantidad != 0)
    {
        promedio /= cantidad;
    }

    printf("El mayor de la serie es: %i \n", mayor);
    printf("El menor de la serie es: %i \n", menor);
    printf("El promedio de la serie es: %.2g \n", promedio);

    return 0;
}
