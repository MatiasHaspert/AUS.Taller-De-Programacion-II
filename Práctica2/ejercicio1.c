/*
Determinante de una matriz:

--Escribir un programa para calcular el determinante de una matriz:
--Solicite la dimension por teclado
--Solicite la memoria para el almacenamiento
--Ingrese por teclado los coeficientes con valores
--Desarrolle una funcion que realice el calculo
*/

#include <stdio.h>
#include <stdlib.h>

int determinante_Matriz ( int, int** );
int main()
{
    int tam;
    int i,j;

    printf("||Determinante de una matriz||\n");
    printf("Ingrese el tamaño de la matriz NxN: ");
    scanf("%d",&tam);

    int **matriz = malloc (tam * sizeof(int*)); // tam (la cantidad de direcciones de memoria, es decir, los punteros)

    if (matriz == NULL)
    {
        printf("No se pudo reservar memoria.\n");
        return EXIT_FAILURE;
    }

    for ( i = 0; i < tam; i++)
    {
        *(matriz + i) = malloc (tam * sizeof(int)); // almaceno una posicion a lo que apunta matriz

        if(*(matriz + i) == NULL)
        {
            printf("No se pudo reservar memoria.\n");
            return EXIT_FAILURE;
        }
    }

    printf("Ingrese valores a la matriz determinante:\n");

    for ( i = 0; i < tam; i++)
    {
        for ( j = 0; j < tam; j++)
        {
            printf("%d - %d)> ",i,j);
            scanf("%d", &matriz[i][j]);
        } 
    }

    int determinante = determinante_Matriz(tam,matriz);

    printf("El resultado de la matriz determinante es %d.\n",determinante);

    for ( i = 0; i < tam; i++)
    {
        free(*(matriz + i));
    }

    free(matriz);
     
    return EXIT_SUCCESS;
}

int determinante_Matriz ( int tam, int **matriz)
{
    int determinante = 1;
    int matrizAux;

    if( tam == 2)
    {
        determinante = (matriz[0][0] * matriz [1][1]) - (matriz[0][1] * matriz [1][0]); 
    }
    else
    {
        for(int k=0;k<tam-1;k++)  //recorrer la diagonal
        {
            determinante *= matriz[k][k];

            if(matriz[k][k]==0)
            {
                return EXIT_FAILURE;
            }
            else
            {
                for(int i = k+1; i < tam ;i++) //recorrer fila
                {
                    matrizAux =- matriz[i][k];

                    for(int j = k; j< tam ;j++)
                    {
                        matriz[i][j]= matriz[i][j] + matrizAux * matriz[k][j] / matriz[k][k];
                    }
                }
            }
        }

        determinante *= matriz[tam-1][tam-1];
    }
    
    return determinante;
}