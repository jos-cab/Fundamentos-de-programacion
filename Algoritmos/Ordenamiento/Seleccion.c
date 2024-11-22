void seleccion(t_vector vector, int n)
{
    int i, j, aux;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (vector[i] > vector[j])
            {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
}