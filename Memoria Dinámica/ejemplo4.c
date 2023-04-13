/*
Ingresar por teclado un entero que represente la cantidad de elementos que debe crearse un vector. Crear el vector en forma dinámica,
cargar e imprimir sus datos. Hacer todo en la main.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamaño;
    int *pu;
    int i;

    printf("Ingrese cuantos elementos tendrá el vector: ");
    scanf("%d",&tamaño);

    pu = malloc (sizeof(int) * tamaño); // asignamos la memoria multiplicando el tamaño del tipo de dato por la variable 

    printf("Ingrese valores al vector:\n");

    for ( i = 0; i < tamaño; i++)
    {
        printf("Valor %d)> ",i+1);
        scanf("%d", &pu[i]);
    }
    
    printf("\nValores ingresados:\n");

    for (i=0; i < tamaño; i++)
    {
        printf("%d ",pu[i]);
    }
    
    free(pu);

    return EXIT_SUCCESS;

}