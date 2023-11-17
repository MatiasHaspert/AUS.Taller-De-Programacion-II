#include <stdio.h>
#include <stdlib.h>

int **crear_matriz(int , int);
char **crear_matriz_caracteres(int, int, int **);
void libera(void **, int);

int main()
{
    int **matrizInt;
    int i, j;
    int fila = 4, col = 3;

    matrizInt = crear_matriz(col,fila);

    for(i = 0; i < fila; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ",matrizInt[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    char **matrizChar = crear_matriz_caracteres(col,fila,matrizInt);
    for(i = 0; i < fila; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%c ",matrizChar[i][j]);
        }
        printf("\n");
    } 

    libera(matrizInt,fila);
    libera(matrizChar,fila);
    return EXIT_SUCCESS;
}

int **crear_matriz(int col , int fila)
{
    int i, j;

    int **m = malloc(sizeof(int *) * fila);
    for(i = 0; i < fila; i++)
    {
        m[i] = malloc(sizeof(int) * col);
        for (j = 0; j < col; j++)
        {
            m[i][j] = i+j+2;
        }
    }

    return m;
}

char **crear_matriz_caracteres(int col, int fila, int **matrizInt)
{
    int i, j;

    char **m = malloc(sizeof(char *) * fila);
    for(i = 0; i < fila; i++)
    {
        m[i] = malloc(sizeof(char) * col);
        for (j = 0; j < col; j++)
        {
            m[i][j] = matrizInt[i][j]+70;
        }
    }

    return m;
}

void libera(void **matriz, int fila)
{
    for (int i = 0; i < fila; i++)
    {
        free(matriz[i]);
    }

    free(matriz);
    
}
