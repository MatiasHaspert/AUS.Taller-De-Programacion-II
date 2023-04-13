/*
Programa que realiza la suma de dos matrices de N x N.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamaño = 0;
    int matriz1[tamaño][tamaño];
    int matriz2[tamaño][tamaño];
    int i,j;

    printf("Teclea el tamaño de la matriz: ");
    scanf("%d",&tamaño);

    printf("Ingresa valores a la matriz 1:\n");

    for(i = 0; i < tamaño; i++)
    {
        for (j = 0; j < tamaño; j++)
        {
            printf("Fila %d - Columna %d: ",i,j);
            scanf("%d",&matriz1[i][j]);
        }
        
    }
    
    printf("Ingresa valores a la matriz 2:\n");

    for(i = 0; i < tamaño; i++)
    {
        for (j = 0; j < tamaño; j++)
        {
            printf("Fila %d - Columna %d: ",i,j);
            scanf("%d",&matriz2[i][j]);
        }
        
    }

    printf("\nMatriz 1:\n");

    for ( i = 0; i < tamaño; i++)
    {
        for ( j = 0; j < tamaño; j++)
        {
            printf("%d ",matriz1[i][j]);
        }

        printf("\n");
        
    }

    printf("\nMatriz 2:\n");

    for ( i = 0; i < tamaño; i++)
    {
        for ( j = 0; j < tamaño; j++)
        {
            printf("%d ",matriz2[i][j]);
        }
        
        printf("\n");
    }


    printf("\nSuma:\n");
    
    for ( i = 0; i < tamaño; i++)
    {
        for ( j = 0; j < tamaño; j++)
        {
            printf("%d ",matriz1[i][j] + matriz2[i][j]);
        }
        
        printf("\n");
    }


    return EXIT_SUCCESS;
}


    


