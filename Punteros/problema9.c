/*
Confeccionar un programa que permita cargar un vector de 5 enteros y obtenga el mayor y el menor.
Implementar dos funciones:
1-Carga del vector
2-Otra función que reciba el vector y retorne el mayor y menor elemento del vector por medio de dos parámetros de tipo puntero:
void mayorMenor(int vec[TAMANO],int *pmayor,int *pmenor)
*/

#include <stdio.h>
#include <stdlib.h>

void carga(int []);
void mayorYmenor (int [], int *, int *);

int main()
{
    int A[5];
    int valorMayor;
    int valorMenor;

    carga(A);

    mayorYmenor(A,&valorMayor,&valorMenor);

    printf("El valor mas chico es %d.\n",valorMenor);
    printf("El valor mas grande es %d.\n",valorMayor);

    return EXIT_SUCCESS;
}

void carga(int A[])
{
    printf("Ingresa 5 enteros y te diré el mayor y menor:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d)> ",i+1);
        scanf("%d",&A[i]);
    }
    

}

void mayorYmenor (int A[],int *mayor, int *menor)
{
    int i;
    *mayor = A[0];
    *menor = A[0];

    for (i = 0; i < 5; i++)
    {
        if(A[i] > *mayor)
        {
            *mayor = A[i];
        }

        if(A[i] < *menor)
        {
            *menor = A[i];
        }
    }

    
}