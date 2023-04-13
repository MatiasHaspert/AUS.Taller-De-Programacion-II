/*
Desarrollar un programa para administrar un vector de 5 enteros.
En la función de carga e impresión utilizar la sintaxis de punteros para acceder a sus elementos (no utilizar la sintaxis de subíndice)
*/

#include <stdio.h>
#include <stdlib.h>

void carga(int *);
void imprimir(int *);

int main()
{
    int A[5];

    carga(A);

    imprimir(A);

    return EXIT_SUCCESS;
}

void carga(int *A)
{
    printf("Ingrese 5 elementos:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d)> ",i+1);
        scanf("%d",&*A);

        *A++;
    }
    
    
}

void imprimir(int *A)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",*A);

        *A++;
    }
    
}