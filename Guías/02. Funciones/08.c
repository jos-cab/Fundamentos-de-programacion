/*
8. El producto de Wallis es una expresión matemática,
utilizada para representar el valor del número Pi,
que fue descubierta por John Wallis en 1655 y que establece que:

Multiplicatoria de
((2 * n) / (2 * (n - 1))) * ((2 * n) / (2 * (n + 1))) = PI / 2

Escribir una función, que reciba por parámetro, el valor más alto a utilizar en
el cálculo (n).

La función debe calcular el valor de Pi utilizando la fórmula de Wallis
y devolver el valor de Pi obtenido.

Proba la función, utilizando al menos, como valor de n, 100, 1000 y 10000.

Fuente de consulta: https://es.wikipedia.org/wiki/Producto_de_Wallis
*/

#include <stdio.h>

double calcular_pi(unsigned long long int n)
{
    double producto;
    // unsigned long long int necesario para ir hasta n
    unsigned long long int i;

    producto = 1;

    for (i = 1; i <= n; i++)
        producto *= (double)(2 * i) / (2 * i - 1) * (2 * i) / (2 * i + 1);

    return 2 * producto;
}

int main()
{
    printf("PI (producto wallis con n = 100): %lf\n", calcular_pi(100));
    printf("El (producto wallis con n = 1000): %lf\n", calcular_pi(1000));
    printf("El (producto wallis con n = 10000): %lf\n", calcular_pi(10000));
    printf("El (producto wallis con n = 100000): %lf\n", calcular_pi(100000));
    printf("El (producto wallis con n = 1000000): %lf\n", calcular_pi(1000000));
    
    return 0;
}
