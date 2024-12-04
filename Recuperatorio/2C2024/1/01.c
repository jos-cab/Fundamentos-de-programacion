/*
1) Hacer una función que reciba por parámetro un numero y devuelva:
  • La suma de los divisores impares
  • La suma del conjunto de números desde 1 hasta el número recibido

Invocar la función (se daba como ej: numero = 9)
*/

void obtener_suma_divisores_impares_y_sumatoria(int numero,
                                                int *suma_divisores,
                                                int *sumatoria)
{
    int i;

    *suma_divisores = 0;
    *sumatoria = 0;

    // Supongo que 1 y numero cuentan como divisores
    // Importante empezar en 1 para no dividir por 0
    for (i = 1; i <= numero; i++)
    {
        // Si es divisor del número y es impar
        if ((numero % i == 0) && (i % 2 != 0))
            *suma_divisores += i;
        
        *sumatoria += i;
    }
}

int main()
{
    int numero, suma_divisores, sumatoria;

    numero = 9;

    obtener_suma_divisores_impares_y_sumatoria(numero,
                                               &suma_divisores,
                                               &sumatoria);

    return 0;
}
