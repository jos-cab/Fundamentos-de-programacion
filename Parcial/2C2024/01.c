/*
1) Escribir una función que dado un numero ingresado devuelva el digito mas 
grande y la cantidad de veces que aparece.

Ej: 15838
El digito mas grande es 8 y aparece 2 veces.

Realizar un programa que invoque la función.
*/

void obtener_mayor_digito_con_repeticiones(int numero, 
                                           int *mayor_digito,
                                           int *repeticiones_mayor_digito)
{
    int ultimo_digito;

    *mayor_digito = 0; // Como mínimo mayor_dígito puede ser 0
    *repeticiones_mayor_digito = 1;

    do
    {
        // Obtengo el último dígito y lo elimino del número
        ultimo_digito = numero % 10; 
        numero /= 10;
        
        if (ultimo_digito > *mayor_digito)
        {
            *mayor_digito = ultimo_digito;
            *repeticiones_mayor_digito = 1;
        } else if (ultimo_digito == *mayor_digito)
            (*repeticiones_mayor_digito)++; // Son importantes los paréntesis
    } while (numero > 0);
    
}

int main()
{
    int numero, mayor_digito, repeticiones_mayor_digito;

    numero = 15838; // Dudé en hacer una entrada de datos

    obtener_mayor_digito_con_repeticiones(numero, 
                                          &mayor_digito,
                                          &repeticiones_mayor_digito);

    // El ejercicio solo pide invocar a la función, en ningún momento mostrar
    // Algún resultado 

    return 0;
}
