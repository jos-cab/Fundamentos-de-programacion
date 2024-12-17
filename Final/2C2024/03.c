/*
3. Hacer una función recursiva que devuelva la sumatoria desde 1 hasta n.
En el caso de que n sea menor o igual a 0 retornar 0.
*/

int sumatoria(int n)
{
	if (n <= 0)
		return 0;

	return n + sumatoria(n - 1);
}