/*
24) Un juego de un parque de diversiones, debe realizar los siguientes controles
antes de comenzar a funcionar:
- Sólo pueden participar quienes tengan una altura entre 1.60 m y 1.90 m
- El peso total de los participantes no debe superar las 1.5 toneladas
- La capacidad máxima de participantes es de 20

Debemos programar una simulación de estos controles, para ello nuestro programa
debe solicitar a medida que va a ingresar al juego un nuevo participante, su
peso y su altura.

En caso de detectar que la altura del participante no cumple con lo requerido,
se debe enviar el siguiente mensaje:
“Altura del participante fuera de rangopermitido”;
y se debe continuar con el siguiente participante.

A medida que se procesan los ingresos de participantes,
se debe controlar que el peso acumulado de los participantes no exceda el total
permitido.
Si lo excediera, debe enviar el mensaje:
“Peso total excedido, el participante no puede subir”,
dicho participante será ignorado y se continúa solicitando nuevos ingresos.

En el caso que suban personas acumulando un peso exacto de 1500 el juego puede
comenzar automáticamente.

También a medida que se procesan los ingresos de participantes,
se debe controlar que la cantidad de participantes no exceda el máximo
establecido, por ello, si se alcanza el máximo, se debe informar:
“Cantidad máxima de participantes alcanzada”
y el juego podrá comenzar automáticamente si cumple con el resto.

Por último, podría ser que suban menos personas que la capacidad máxima,
entonces, utilizar el último ingreso de los pesos como corte de ingreso de
participantes, considerando que si se ingresa 0 como peso, indica, que no hay
más participantes.

Pruebas a considerar:
Prueba 1
Participantes:
1 - Peso [Kg]: 90 - Altura [cm]: 180
2 - Peso [Kg]: 110 - Altura [cm]: 170
3 - Peso [Kg]: 90 - Altura [cm]: 150 (Se ignora altura no permitida)
4 - Peso [Kg]: 0 (Inicia el juego con 2 participantes)

Prueba 2
Participantes:
1 - Peso [Kg]: 60 - Altura [cm]: 160
Luego suben 12 participantes de 120 Kg y 190 cm
(Inicia el juego automaticamente por alcanzar el peso máximo)

Prueba 3
Participantes:
1 - Peso [Kg]: 100 - Altura [cm]: 175
Luego suben 11 participantes de 120 Kg y 190 cm
13 - Peso [Kg]: 100 - Altura [cm]: 175
(Se ignora porque se excede el pesomáximo del juego)
14 - Peso [Kg]: 0 (Inicia el juego con 12 participantes)

Prueba 4
Participantes:
Suben 20 participantes de 70 Kg y 160 cm
(Inicia el juego automaticamente por alcanzar la cantidad máxima permitida)
*/

#include <stdio.h>

#define CANTIDAD_MAXIMA_PARTICIPANTES 20
#define ALTURA_MINIMA 160
#define ALTURA_MAXIMA 190
#define PESO_TOTAL_MAXIMO 1500

int main()
{
    unsigned short int altura_centimetros;
    unsigned short int peso;
    unsigned short int cantidad_participantes;
    unsigned short int peso_total;

    cantidad_participantes = 0;
    peso_total = 0;

    do
    {
        printf("Ingrese el peso (0 para salir): ");
        scanf("%hu", &peso);

        if (peso != 0)
            if (peso_total + peso > PESO_TOTAL_MAXIMO)
            {
                printf(
                    "Peso total excedido, el participante no puede subir \n");
            }
            else
            {
                peso_total += peso;
                
                printf("Ingrese altura en centímetros: ");
                scanf("%hu", &altura_centimetros);

                if ((altura_centimetros < ALTURA_MINIMA) ||
                    (altura_centimetros > ALTURA_MAXIMA))
                {
                    printf(
                        "Altura del participante fuera de rango permitido \n");
                } else
                {
                    cantidad_participantes++;
                    if(cantidad_participantes == CANTIDAD_MAXIMA_PARTICIPANTES)
                        printf("Cantidad máxima de participantes alcanzada \n");
                }
            }
        
        printf("\n");
        
    } while ((peso != 0) && 
             (peso_total < PESO_TOTAL_MAXIMO) && 
             (cantidad_participantes < CANTIDAD_MAXIMA_PARTICIPANTES));

    // NOTA: El juego iniciará igual de no ingresar ningún participante. 
    // El problema no toma en cuenta esto.
    if (peso_total <= PESO_TOTAL_MAXIMO)
    {
        if (peso_total == PESO_TOTAL_MAXIMO)
            printf(
                "Iniciando juego automáticamente por alcanzar peso máximo \n");
        
        printf("Iniciando juego con %hu participantes",
            cantidad_participantes);
    } else
        printf("No se puede iniciar el juego por superar el peso máximo");

    return 0;
}
