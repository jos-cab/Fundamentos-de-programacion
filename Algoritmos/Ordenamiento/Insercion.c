void insercion(t_vector vector, int n)
{
    int i, j, aux;

    for (i = 1; i < n; i++)
    {
        aux = vector[i];
        j = i - 1;

        while ((j >= 0) && (aux < vector[j]))
        {
            vector[j + 1] = vector[j];
            j--;
        }

        vector[j + 1] = aux;
    }
}