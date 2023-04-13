/*
Las structs permiten almacenar un conjunto de variables que representan una identidad
de la vida real, como lo puede ser: una persona, un auto, etc.

struct NombreDelStruct
{
    variables
};

Declarar un struc en la main:
                            struct NombreStruct nombreVariable;

*/

#include <stdio.h>
#include <stdlib.h>

struct producto
{
    char descripcion[30];
    int codigo;
    int stock;
    float precio;
};

int main()
{
    struct producto p1;

    struct producto listaProd[10];

    listaProd[0].codigo = 5;
    
    p1.codigo = 1;

    printf("Ingrese la descripcion del producto: ");
    scanf("%s",p1.descripcion);

    printf("Ingrese el stock del producto: ");
    scanf("%d",&p1.stock);

    printf("Ingrese el precio del producto: ");
    scanf("%f",&p1.precio);

    printf("\nCaracteristicas del producto:\n");
    printf("Descripcion: %s\n",p1.descripcion);
    printf("Precio: %f\n",p1.precio);
    printf("Codigo: %d\n",p1.codigo);
    printf("Stock: %d\n",p1.stock);
    return EXIT_SUCCESS;
}