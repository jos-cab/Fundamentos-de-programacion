/*
20) Escribir un programa que permita al usuario ingresar los montos de las 
compras de un cliente y que al finalizar informe por pantalla el importe total 
a pagar, teniendo en cuenta que si éste supera los $1000 se le debe aplicar un
10% de descuento.

Se desconoce la cantidad de datos que se van a ingresar.

La carga de datos finaliza cuando el usuario ingresa el monto 0 (cero).

Se debe validar que no se ingresen montos negativos indicando al usuario monto
invalido.
*/

#include <stdio.h>

int main()
{
    unsigned long int total;
    int monto;

    total = 0;

    do
    {
        do
        {
            printf("Ingrese monto del producto (0 para salir): ");
            scanf("%i", &monto);

            if (monto < 0)
                printf("El monto debe ser positivo\n");
            
        } while (monto < 0);
        
        total += monto;

    } while (monto != 0);
    
    if (total > 1000)
        total *= 0.9; // 10% de descuento

    printf("El total a pagar es: %lu", total);

    return 0;
}