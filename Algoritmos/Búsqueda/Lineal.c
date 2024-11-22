int lineal(t_vector vector, int x, int n)
{
    int i;
    bool encontrado;

    i = 0;
    encontrado = false;

    while ((i < n) && !encontrado)
    {
        encontrado = vector[i] == x;

        if (!encontrado)
            i++;
    }

    return i;
}