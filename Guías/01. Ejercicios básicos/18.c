/*
18) Se realiza una encuesta para estimar el grado de aceptación de los productos x e y en el mercado.
A cada encuestado se le pregunta si consume el producto x y si consume el producto y.
La respuesta puede ser sí o no.

Se pide calcular e informar el porcentaje de consumidores de:
a) del producto x
b) del producto y
c) del producto x solamente
d) del producto y solamente
e) de ambos productos
f) de ninguno de los productos
*/

#include <stdio.h>

int main()
{
    unsigned short int cantidad_consumidores;
    unsigned short int cantidad_consumidores_x;
    unsigned short int cantidad_consumidores_y;
    unsigned short int cantidad_consumidores_solo_y;
    unsigned short int cantidad_consumidores_solo_x;
    unsigned short int cantidad_consumidores_ambos;
    unsigned short int cantidad_consumidores_ninguno;
    
    char desea_continuar, consume_x, consume_y;

    cantidad_consumidores = 0;
    cantidad_consumidores_x = 0;
    cantidad_consumidores_y = 0;
    cantidad_consumidores_solo_x = 0;
    cantidad_consumidores_solo_y = 0;
    cantidad_consumidores_ambos = 0;
    cantidad_consumidores_ninguno = 0;

    do
    {
        cantidad_consumidores++;

        // Pregunto si consume x
        do
        {
            printf("Usted consume el producto x? (s/n): ");
            scanf(" %c", &consume_x); // El espacio antes de %c es necesario
        } while (consume_x != 's' && consume_x != 'n');
        
        // Pregunto si consume y
        do
        {
            printf("Usted consume el producto y? (s/n): ");
            scanf(" %c", &consume_y); // El espacio antes de %c es necesario
        } while (consume_y != 's' && consume_y != 'n');

        // Incremento cantidad de consumidores en x e y de ser necesario
        if (consume_x == 's')
            cantidad_consumidores_x++;

        if (consume_y == 's')
            cantidad_consumidores_y++;

        // Incremento cantidad de consumidores solo de x, solo de y, ambos o 
        // ninguno
        if (consume_x == 's' && consume_y == 's')
            cantidad_consumidores_ambos++;
        else if (consume_x == 's' && consume_y == 'n')
            cantidad_consumidores_solo_x++;
        else if (consume_x == 'n' && consume_y == 's')
            cantidad_consumidores_solo_y++;
        else
            cantidad_consumidores_ninguno++;
        
        // Pregunto si desea continuar
        do
        {
            printf("Desea continuar? (s/n): ");
            // El espacio antes de %c es necesario
            scanf(" %c", &desea_continuar);
        } while (desea_continuar != 's' && desea_continuar != 'n');

    } while (desea_continuar == 's');

    // a)
    printf("El porcentaje de consumidores de x es: %.2f%% \n", 
        ((float) cantidad_consumidores_x / cantidad_consumidores) * 100); 

    // b)
    printf("El porcentaje de consumidores de y es: %.2f%% \n",
        ((float) cantidad_consumidores_y / cantidad_consumidores) * 100); 

    // c)
    printf("El porcentaje de consumidores solamente de x es: %.2f%% \n",
        ((float) cantidad_consumidores_solo_x / cantidad_consumidores) * 100); 

    // d)
    printf("El porcentaje de consumidores solamente de y es: %.2f%% \n", 
        ((float) cantidad_consumidores_solo_y / cantidad_consumidores) * 100); 

    // e)
    printf("El porcentaje de consumidores de ambos productos es: %.2f%% \n", 
        ((float) cantidad_consumidores_ambos / cantidad_consumidores) * 100); 

    // f)
    printf("El porcentaje de consumidores de ningún producto es: %.2f%% \n",
        ((float) cantidad_consumidores_ninguno / cantidad_consumidores) * 100); 

    return 0;
}
