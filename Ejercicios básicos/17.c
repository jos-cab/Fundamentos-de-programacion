/*
17) Generar un dibujo por pantalla con el siguiente patrón solicitando al usuario la altura.
Ejemplo: altura=5 debe dibujar por pantalla:
*
**
***
****
*****
*/

#include <stdio.h>

void main()
{
    int altura, i, j;

    printf("Ingrese una altura para dibujar un triángulo: ");
    scanf("%i", &altura);

    for (i = 1; i <= altura; i++)
    {
        for (j = 1; j <= i; j++)
            printf("*");
        
        printf("\n");
    }
}
