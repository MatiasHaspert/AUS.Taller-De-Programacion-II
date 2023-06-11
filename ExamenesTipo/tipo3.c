#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **expandir(int **matriz, int filas, int cols);
int main()
{
    int f,c;
    int **matriz=NULL;
    int i,j;

    printf("Ingrese la cantidad de filas que desee: ");
    scanf("%d",&f);
    printf("Ingrese la cantidad de columnas que desee: ");
    scanf("%d",&c);

    matriz = malloc (sizeof(int *) * f);
    for (int i = 0; i < f; i++)
    {
        matriz[i] = malloc (sizeof(int) * c);
    }    

    srand(time(NULL));
    for (i = 0; i < f; i++)
    {
        for (j = 0; j < c; j++)
        {
            matriz[i][j] = 1 + rand() %9;
        } 
    }

    printf("\nMatriz original:\n");    
    for (i = 0; i < f; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ",matriz[i][j]);
        }

        printf("\n"); 
    }

    matriz = expandir(matriz,f,c);

    printf("\nMatriz nueva:\n");
    for ( i = 0; i < f+1; i++)
    {
        for(j = 0; j < c+1;j++)
        {
            printf("%d ",matriz[i][j]);
        }

        printf("\n");
    }
    

    for ( i = 0; i < f; i++)
    {
        free(matriz[i]);
    }
    
    free(matriz);


    return EXIT_SUCCESS;
}

int **expandir(int **matriz, int filas, int cols)
{
    int i,j;
    int **mExpandir;
    mExpandir = malloc (sizeof(int *) * filas+1);

    for ( i = 0; i < filas+1; i++)
    {
        mExpandir[i] = malloc (sizeof(int) * cols+1);
        for ( j = 0; j < cols+1; j++)
        {
            if (i < filas && j < cols)
            {
                mExpandir[i][j] = matriz[i][j];
            }
            else
            {
                mExpandir[i][j] = 0;
            }            
        }        
    }
    
    return mExpandir;

}
