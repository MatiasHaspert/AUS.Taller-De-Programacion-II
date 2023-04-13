/*
Escriba un programa que cree la transpuesta de una matriz.
*/

#include <stdio.h>
#include <stdlib.h>



int main()
{
    int reglones;
    int columnas;
    int i,j;

    printf("Teclea el número de reglones: ");
    scanf("%d",&reglones);

    printf("Tecla el numero de columnas: ");
    scanf("%d",&columnas);

    int matriz[reglones][columnas];

    printf("\nIngresa valores a la matriz:\n");

    for ( i = 0; i < reglones; i++)
    {
        for ( j = 0; j < columnas; j++)
        {
            printf("Fila %d - Columna %d: ",i,j);
            scanf("%d",&matriz[i][j]);
        }
        
    }
    

    printf("\nMatriz original:\n");

    for ( i = 0; i < reglones; i++)
    {
        for ( j = 0; j < columnas; j++)
        {
            printf("%d ",matriz[i][j]);
        }
        
        printf("\n");
    }

    printf("\nMatriz transpuesta:\n");

    for ( j = 0; j < columnas; j++)
    {
        for ( i = 0; i < reglones; i++)
        {
            printf("%d ",matriz[i][j]);
        }
        
        printf("\n");
    }
    
    


    

    return EXIT_SUCCESS;
}

