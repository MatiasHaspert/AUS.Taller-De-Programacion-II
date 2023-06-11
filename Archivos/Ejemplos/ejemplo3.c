/*
Abre el archivo para lectura
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[25];
    char apellido[25];

    FILE *archi;

    archi = fopen("nombres.txt","rt"); // "r" para leer archivos, "t" de tipo texto

    if(archi != NULL)
    {
        fscanf(archi,"%s  %s",nombre,apellido);

        while (!feof(archi))
        {
            printf("Nombre leído: %s. Apellido leído: %s.\n",nombre,apellido);
            fscanf(archi,"%s  %s",nombre,apellido);
        }

        if(!fclose(archi))
        {
            printf("Se ha cerrado correctamente el archivo.\n");
        }
        else
        {
            printf("No se ha podido cerrar correctamente el archivo.\n");
        }
    }
    else
    {
        printf("No se pudo crear el archivo.\n");
    }

    return EXIT_SUCCESS;
}