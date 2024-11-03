/*
9) Solicitar al usuario el ingreso de una temperatura (puede tener decimales por ejemplo 24.5)
y la unidad en la que se encuentra (siendo solo un carácter F ó C).

Luego el programa debe mostrar la temperatura ingresada, convertida en la otraunidad.

La relación entre temperaturas Celsius y Fahrenheit está dada por la fórmula: C=5.0 / 9.0 * (F − 32)
*/

#include <stdio.h>

int main()
{
    float temperatura, conversion;
    char unidad;

    printf("Ingrese unidad de temperatura (C o F): ");
    scanf("%c", &unidad);
    printf("Ingrese temperatura: ");
    scanf("%f", &temperatura);

    switch (unidad)
    {
        case 'C':
            conversion = (9.0 / 5.0) * temperatura + 32;
            printf("La temperatura es igual a %.2f°F", conversion);
            break;
            
        case 'F':
            conversion = 5.0 / 9.0 * (temperatura - 32);
            printf("La temperatura es igual a %.2f°C", conversion);
            break;
        
        default:
            printf("Unidad inválida");
            break;
    }

    return 0;
}
