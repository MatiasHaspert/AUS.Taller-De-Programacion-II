#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct 
{ 
    short filas, col; 
    int **matriz;

}matrix;

void carga_matriz (matrix*);
void imprime_matriz (matrix*);
void inicializarMatriz(matrix *, int , int );
matrix * suma_matrices(matrix *, matrix *);
void liberar_matriz(matrix *);

int main()
{
    matrix m1;
    matrix m2;
    matrix *p_m1 = &m1;
    matrix *p_m2 = &m2;
    matrix *m3;
    int fil,col;

    printf("Ingrese la cantidad de filas que desee: ");
    scanf("%d",&fil);
    printf("Ingrese la cantidad de columnas que desee: ");
    scanf("%d",&col);

    inicializarMatriz(p_m1,fil,col);
    inicializarMatriz(p_m2,fil,col);

    carga_matriz(p_m1);
    carga_matriz(p_m2);

    printf("Matriz 1:\n");
    imprime_matriz(p_m2);

    printf("Matriz 2:\n");
    imprime_matriz(p_m2);

    m3 = suma_matrices(p_m1,p_m2);

    printf("\nMatriz suma:\n");
    imprime_matriz(m3);

    liberar_matriz(p_m1);
    liberar_matriz(p_m2);
    liberar_matriz(m3);

    return EXIT_SUCCESS;
}

void inicializarMatriz(matrix *m, int filas, int columnas)
{
    int i;
    m->filas = filas;
    m->col = columnas;
    m->matriz = malloc(filas * sizeof(int *));
    for (i = 0; i < filas; i++)
    {
        m->matriz[i] = malloc(columnas * sizeof(int));
    }
}

void carga_matriz (matrix *m)
{
    srand(time(NULL));

    int i,j;
    for (i = 0; i < m->filas; i++)
    {
        for ( j = 0; j < m->col; j++)
        {
            m->matriz[i][j] = 1 + rand() %10;
        }        
    }       
}

void liberar_matriz(matrix *m)
{
    for (int i = 0; i < m->filas; i++)
    {
        free(m->matriz[i]);
    }
    
    free(m->matriz);
}

void imprime_matriz(matrix *m)
{
    int i,j;

    for ( i = 0; i < m->filas; i++)
    {
        for ( j = 0; j < m->col; j++)
        {
            printf("%d ",m->matriz[i][j]);
        }
        
        printf("\n");
    }
    
}

matrix * suma_matrices(matrix *m1, matrix *m2)
{
    matrix *m3;
    m3 = malloc(sizeof(matrix));
    inicializarMatriz(m3,m1->filas,m1->col);

    for (int i = 0; i < m1->filas; i++)
    {
        for (int j = 0; j < m1->col; j++)
        {
            m3->matriz[i][j] = m1->matriz[i][j] + m2->matriz[i][j];
        }
        
    }
    
    return m3;

}