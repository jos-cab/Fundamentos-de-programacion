/*
3) Con una matriz de char ya cargada devolver:
  •Cantidad de vocales
  •Cantidad de numeros
*/

#define MF_F 150
#define MF_C 2500

typedef char Tmatriz[MF_F][MF_C];

void obtener_cantidad_vocales_y_numeros(Tmatriz matriz,
                                        int ML_F, int ML_C,
                                        int *cantidad_vocales,
                                        int *cantidad_numeros)
{
    int i, j;

    *cantidad_vocales = 0;
    *cantidad_numeros = 0;

    for (i = 0; i < ML_F; i++)
        for (j = 0; j < ML_C; j++)
        {
            switch (matriz[i][j])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    (*cantidad_vocales)++;
                    break;
            }

            // también se puede juntar en el switch anterior
            if ('0' <= matriz[i][j] && matriz[i][j] <= '9')
                (*cantidad_numeros)++;
            
        }
    
}