int binaria(t_vector vector, int x, int n)
{
    int izquierda, medio, derecha;
    bool encontrado;

    encontrado = false;
    izquierda = 0;
    derecha = n - 1;

    if ((vector[izquierda] <= x) && (x <= vector[derecha]))
    {
        while ((izquierda <= derecha) && !encontrado)
        {
            medio = (izquierda + derecha) / 2;

            if (vector[medio] == x)
                encontrado = true;
            else if (vector[medio] < x)
                izquierda = medio + 1;
            else // vector[medio] > x
                derecha = medio - 1;
        }

        if (!encontrado)
            medio = -1;
    }
    else
        medio = -1;

    return medio;
}