/*
Escriba un programa que genere la matriz identidad de tamaño N x N.
*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int tamaño;
    int i,j;

    printf("Ingrese el tamaño que desee de la matriz: ");
    scanf("%d",&tamaño);

    for ( i = 0; i < tamaño; i++)
    {
        for ( j = 0; j < tamaño; j++)
        {
            printf("1");
        }

        printf("\n");   
    }
    



    return EXIT_SUCCESS;
}

