/*
3. Escribir una función que reciba un valor n, entero, y devuelva la suma de los valores entre 0 y n. 
*/

#include <stdio.h>

unsigned long long suma_naturales(int n)
{
    unsigned long long suma = 0;
    int i;

    // Alternativamente se puede usar la fórmula: [ n.(n+1) ] / 2
    for (i = 0; i <= n; i++)
        suma += i;

    return suma;
}

int main()
{
    printf("La suma natural de -1: %d\n", suma_naturales(-1));   
    printf("La suma natural de 0: %d\n", suma_naturales(0));   
    printf("La suma natural de 1: %d\n", suma_naturales(1));
    printf("La suma natural de 2: %d\n", suma_naturales(2));
    printf("La suma natural de 10: %d\n", suma_naturales(10));

    return 0;
}
