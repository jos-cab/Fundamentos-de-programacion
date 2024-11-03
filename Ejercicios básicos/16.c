/*
16) Dado un número entero positivo ingresado por el usuario, procesarlo e indicar:
(realizar un programa diferente para cada caso)
a) La cantidad de dígitos pares e impares que lo componen.
b) El menor y el mayor dígito del número.
Recordar uso de división y módulo:
Ejemplo:
111 / 10 = 11
111 % 10 = 1
*/

#include <stdio.h>

int main()
{
    unsigned short int numero, cantidad_pares, cantidad_impares, menor, mayor, digito;

    cantidad_pares = 0;
    cantidad_impares = 0;
    // El menor se va a terminar actualizando ya que el mayor número de un dígito ingresado
    // puede ser como mucho 9.
    // Lo contrario sucede con el mayor dígito.
    menor = 9;
    mayor = 0;

    printf("Ingrese un número para saber: \n");
    printf("a) cantidad de dígitos pares e impares que lo componen \n");
    printf("b) El menor y el mayor dígito del número \n");
    
    printf("Número: ");
    scanf("%hu", &numero);

    while (numero > 0)
    {
        digito = numero % 10;

        if (digito % 2 == 0)
            cantidad_pares++;
        else
            cantidad_impares++;

        if (digito < menor)
            menor = digito;

        if (digito > mayor)
            mayor = digito;
        
        numero /= 10;
    }

    printf("a)\n");
    printf("Cantidad de dígitos pares: %i\n", cantidad_pares);
    printf("Cantidad de dígitos impares: %i\n", cantidad_impares);
    printf("\n");
    printf("b)\n");
    printf("Menor: %i\n", menor);
    printf("Mayor: %i\n", mayor);

    return 0;
}