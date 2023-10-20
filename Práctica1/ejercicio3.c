#include <stdio.h>
#include <stdlib.h>

#define N 4

void carga (int [][N]);
void imprime (int [][N]);

int main()
{
    int matriz1[N][N];
    int matriz2[N][N];
    int matrizS[N][N];

    printf("\nMatriz 1:\n");
    carga(matriz1);

    printf("\nMatriz 2:\n");
    carga(matriz2);

    printf("\nMatriz suma:\n");
    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrizS[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    printf("\nMatriz 1:\n");
    imprime(matriz1);
    printf("\nMatriz 2:\n");
    imprime(matriz2);
    printf("\nMatriz suma:\n");
    imprime(matrizS);
    

    return EXIT_SUCCESS;
}

void carga (int m[][N])
{
    int i,j;

    printf("\nIngrese valores a la matriz:\n");

    for ( i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("\nPosicion [%d][%d]: ",i,j);
            scanf("%d",&m[i][j]);
        }
    } 
}

void imprime (int m[][N])
{
    int i,j;

    for ( i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    } 
}

