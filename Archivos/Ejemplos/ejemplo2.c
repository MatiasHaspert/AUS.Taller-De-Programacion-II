/*
Éste programa abrirá el archivo y agregara los datos al final
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *archi;

    archi = fopen ("nombres.txt","a"); // "a" abre el atchivo y agrega datos al final

    /*valida si el archivo se creo correctamente*/
    if(archi != NULL)
    {
        fputs("Laura Viñolo\n",archi);
        fputs("Juan Haspert\n",archi);

        if(fclose(archi) == 0)
        {
            printf("El archivo se cerro correctamente.\n");
        }
        else
        {
            printf("No se ha podido cerrar el archivo.\n");
        }        
    }
    else
    {
        printf("No se ha podido abrir el archivo.\n");
    }



    return EXIT_SUCCESS;
}