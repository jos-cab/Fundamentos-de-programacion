void insercion(t_vector vector, int n)
{
    int k, i, aux;

    for (k = 1; k < n; k++)
    {
        aux = vector[k];
        i = k - 1;

        while ((i >= 0) && (aux < vector[i]))
        {
            vector[i + 1] = vector[i];
            i--;
        }
    }
}