#include <stdio.h>
#include <stdlib.h>

int main()
{
    // int bi [2]   [3]
    //        fila  col
    int fila = 2;
    int columna = 3;
    int i,j;

    int **bi = malloc (fila * sizeof(int *));

    if (bi == NULL)
    {
        printf("No se pudo reservar memoria\n");

        return EXIT_FAILURE;
    }
    
    for ( i = 0; i < fila; i++)
    {
        *(bi + i) = malloc (columna * sizeof(int));
        if (*(bi + i) == NULL)
        {
            printf("No se pudo reservar memoria\n");
            return EXIT_FAILURE;
        }
    }

    int cont = 1;

    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < columna; j++)
        {
            *(*(bi + i) + j) =  cont++;      // o puede ser bi[i][j] = i + j
        }
    }
    
    for ( i = 0; i < fila; i++)
    {
        for( j = 0; j < columna; j++)
        {
            printf("%d \n", bi[i][j]);
        }
    }

    //liberamos la memoria de la ultima hasta la primera

    for ( i = 0; i < fila; i++)
    {
        free(*(bi + i));
    }

    free(bi);
    
    return EXIT_SUCCESS;

}
