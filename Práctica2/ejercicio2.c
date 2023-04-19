/*
Producto Escalar
Genera una nueva matriz al que se le multiplica cada elemento por un valor
(escalar):

# Solicite el valor escalar y la dimension de la matriz por teclado.
# Solicite memoria para el almacenamiento.
# Llene la matriz con valores aleatorios.
# Desarrolle una funcion que realice el calculo y devuelva un puntero a la nueva matriz
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void matrizAleatoria(int **, int, int);
int** producto_Escalar_Matriz ( int , int , int , int ** );
void imprimir (int**, int, int);

int main()
{
    int fila,col, valorEscalar;
    int i,j;

    printf(">>PRODUCTO ESCALAR DE UNA MATRIZ<<\n");

    printf("Ingrese la cantidad de filas que desee tener la matriz: ");
    scanf("%d",&fila);

    printf("Ingrese la cantidad de columnas que desee tener la matriz: ");
    scanf("%d",&col);

    printf("\nIngrese el valor escalar: ");
    scanf("%d",&valorEscalar);

    int **matriz = malloc (fila * sizeof(int*));

    if (matriz == NULL)
    {
        printf("No se pudo reservar memoria.\n");
        return EXIT_FAILURE;
    }

    for ( i = 0; i < fila; i++)
    {
        *(matriz + i) = malloc (col * sizeof(int)); // a cada columna le reservo memoria

        if (*(matriz + i) == NULL)
        {
            printf("No se pudo reservar memoria.\n");
            return EXIT_FAILURE; 
        }
    }
    
    matrizAleatoria(matriz,fila,col);

    printf("\nMatriz aleatoria:\n");

    imprimir(matriz,fila,col);

    matriz = producto_Escalar_Matriz(fila,col,valorEscalar,matriz);

    printf("\nProducto escalar de una matriz:\n");

    imprimir(matriz,fila,col);

    for ( i = 0; i < fila; i++)
    {
        free(*(matriz + i));
    }

    free(matriz);
    
    
    return EXIT_SUCCESS;
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

int** producto_Escalar_Matriz ( int fila, int col, int esc, int **matriz)
{
    int i,j;

    for ( i = 0; i < fila; i++)
    {
        for ( j = 0; j < col; j++)
        {
            matriz[i][j] = matriz[i][j] * esc;
        }
    }

    return matriz;
    

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