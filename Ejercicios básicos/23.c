/*
23) Escribir un programa que simule el proceso de control de peso
y cantidad de personas que puede transportar un ascensor.

Vamos a suponer que nuestro ascensor puede soportar un máximo de 400 kg y hasta 6 personas.

Nuestra simulación debe proceder del siguiente modo:
- A medida que las personas ingresan al ascensor de a una a la vez, se registra el peso de la persona.
- Supondremos que el ingreso de 0 kg, indica que no hay más personas por subir al ascensor.
- Si en un determinado momento del ingreso de las personas, se supera el peso máximo,
el ascensor, advertirá mediante un mensaje, 
que indique que se ha excedido el peso máximo y nuestra simulación terminará.
- De igual modo, si el ascensor detecta que ha subido una séptima persona al ascensor,
deberá advertir de esto, y nuestra simulación terminará.

Por último, si habiéndose indicado que todas las personas están a bordo del ascensor 
y las condiciones establecidas se cumplen, el ascensor anunciará "ascensor en movimiento".
*/

#include <stdio.h>

#define PESO_MAXIMO 400
#define CANTIDAD_PERSONAS_MAXIMO 6

int main()
{
    unsigned short int cantidad_personas, peso_total, peso;

    cantidad_personas = 0;
    peso_total = 0;

    do
    {
        printf("Ingrese el peso de la nueva persona (0 para salir): ");
        scanf("%hu", &peso);
        
        if (peso > 0)
            cantidad_personas++;
        
        peso_total += peso;
    } while (peso != 0 && cantidad_personas <= CANTIDAD_PERSONAS_MAXIMO && peso_total <= PESO_MAXIMO);
    
    if (cantidad_personas > CANTIDAD_PERSONAS_MAXIMO)
        printf("Cantidad máxima de personas excedida");
    else if (peso_total > PESO_MAXIMO)
        printf("Peso máximo excedido");
    else
        printf("ascensor en movimiento");

    return 0;
}
