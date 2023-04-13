/*
Confeccionar un programa que permita cargar e imprimir un vector de 5 elementos de tipo float.
Utilizar la sintaxis de punteros en los parámetros de las funciones.
*/

#include <stdio.h>
#include <stdlib.h>

void carga(float *);
void imprimir(float *);

int main()
{
    //float A[5];
    //carga(A);
    //imprimir(A);

    int arr[] = {1,2,3,4,5};

    int *pu = arr;

    printf("arr: %p\n",arr);
    printf("arr: %p\n",&arr);
    printf("arr: %p\n",&arr[0]);

    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }

    for ( int i = 0; i < 5; i++)
    {
        printf("*(pu + %d) = %d\n",i,*pu++);
    }
    
    

    return EXIT_SUCCESS;
}

void carga(float *A)
{
    printf("Ingrese valores float al array:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d)> ", i + 1);
        scanf("%f", &A[i]);
    }
}

void imprimir(float *A)
{
    printf("Valores ingresados:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%f  ", A[i]);
    }
}