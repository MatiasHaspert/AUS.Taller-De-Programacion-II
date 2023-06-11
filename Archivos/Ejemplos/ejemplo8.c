/*
Realice un programa en C que leyendo el archivo NOMBRES.DAT cree uno
nuevo llamado APELLIDOS.DAT y se escriba apellido y nombre en vez de
nombre y apellido como estaba en el original.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[25];
    char apellido[25];
    FILE *archi;
    FILE *archi2;

    if((archi = fopen("nombres.txt","r+")) == NULL )
    {
        printf("No se pudo abrir el archivo.\n");
        EXIT_FAILURE;
    }

    if((archi2 = fopen("apellidos.txt","w+")) == NULL )
    {
        printf("No se pudo abrir el archivo.\n");
        EXIT_FAILURE;
    }

    while(fscanf(archi, "%s %s", nombre, apellido) != EOF)
    {
        fprintf(archi2, "%s %s\n", apellido, nombre);
    }

    if(!fclose(archi))
    {
        printf("\nArchivo cerrado.\n");
    }
    else
    {
        printf("\nError al cerrar el archivo.\n");
    }

    if(!fclose(archi2))
    {
        printf("\nArchivo cerrado.\n");
    }
    else
    {
        printf("\nError al cerrar el archivo.\n");
    }    








    return EXIT_SUCCESS;
}