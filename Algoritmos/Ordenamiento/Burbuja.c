void burbuja(t_vector vector, int n)
{
    int i, j, aux;

    for (i = 1; i < n; i++)
        for (j = 0; j < n - i; j++)
            if (vector[j] > vector[j + 1])
            {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
}