/*
Suma de matrices

# Usando Memoria dinamica escriba un programa que realiza la suma de dos matrices de N x N.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void matrizAleatoria(int **, int, int);
void imprimir (int**, int, int);
int** reservaMemoria (int **,int ,int);
void sumaDeMatrices(int **, int **, int, int);

int main()
{
    int fila,col;
    int **matriz1;
    int **matriz2;

    printf("Ingrese la cantidad de filas que desee tener la matriz: ");
    scanf("%d",&fila);

    printf("Ingrese la cantidad de columnas que desee tener la matriz: ");
    scanf("%d",&col);

    matriz1 = reservaMemoria(matriz1,fila,col);
    matriz2 = reservaMemoria(matriz2,fila,col);

    printf("\nMatriz 1:\n");
    matrizAleatoria(matriz1,fila,col);
    imprimir(matriz1,fila,col);

    printf("\nMatriz 2:\n");
    matrizAleatoria(matriz2,fila,col);
    imprimir(matriz2,fila,col);

    printf("\nSuma de matrices:\n");
    sumaDeMatrices(matriz1,matriz2,fila,col);

    return EXIT_SUCCESS;    
}

int** reservaMemoria (int **matriz, int fila, int col)
{
    int i;

    matriz = malloc (fila * sizeof(int*));

    if (matriz == NULL)
    {
        printf("No se pudo reservar memoria.\n");
        return NULL;
    }

    for ( i = 0; i < fila; i++)
    {
        *(matriz + i) = malloc (col * sizeof(int)); // a cada columna le reservo memoria

        if (*(matriz + i) == NULL)
        {
            printf("No se pudo reservar memoria.\n");
            return NULL; 
        }
    }

    return matriz;

}

void matrizAleatoria(int **matriz, int fila,int col)
{
    int i,j;

    srand(getpid());

    for ( i = 0; i < fila; i++)
    {
        for ( j = 0; j < col; j++)
        {
            matriz[i][j] = 1 + rand() %20;
        }
        
    }
    
}

void imprimir (int **matriz,int fila, int col)
{
    int i,j;

    for ( i = 0; i < fila; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ",matriz[i][j]);
        }
        
        printf("\n");
    }    
}

void sumaDeMatrices(int **matriz1, int **matriz2, int fila, int col)
{
    int **matrizSuma;
    int i,j;

    matrizSuma = reservaMemoria(matrizSuma,fila,col);

    for(i = 0; i < fila; i++)
    {
        for(j = 0; j < col; j++)
        {
            matrizSuma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    imprimir(matrizSuma,fila,col);
}