/*
Matriz Transpuesta

#Escriba un programa utlizando memoria din ́amica que cree la transpuesta de una matriz.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void matrizAleatoria(int **, int, int);
void imprimir (int**, int, int);
int** reservaMemoria (int **,int ,int);


int main()
{
    int fila,col;
    int **matriz;
    int i,j;
    

    printf("Ingrese la cantidad de filas que desee tener la matriz: ");
    scanf("%d",&fila);

    printf("Ingrese la cantidad de columnas que desee tener la matriz: ");
    scanf("%d",&col);

    matriz = reservaMemoria(matriz,fila,col);
    

    printf("\nMatriz original:\n");
    matrizAleatoria(matriz,fila,col);
    imprimir(matriz,fila,col);

    printf("\nMatriz transpuesta:\n");

    for ( j = 0; j < col; j++)
    {
        for ( i = 0; i < fila; i++)
        {
            printf("%d ",matriz[i][j]);
        }
        
        printf("\n");
    }    
    


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
