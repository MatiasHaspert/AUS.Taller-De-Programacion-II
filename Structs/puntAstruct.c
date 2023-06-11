#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int numero;
    char calle[25];
    char nombre[20];

}direccion;

int main()
{
    direccion *pdir;

    pdir = malloc (sizeof(direccion));

    strcpy(pdir->calle,"Leandro Alem");

    pdir->numero = 1296;

    strcpy(pdir->nombre,"Matias");

    printf("Nombre: %s \nDireccion: %s \nNumero: %d \n",pdir->nombre,pdir->calle,pdir->numero);

    free(pdir);

    return EXIT_SUCCESS;
}