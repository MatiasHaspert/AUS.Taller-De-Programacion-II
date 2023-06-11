/*
Realizar un programa en C que realice la lectura del archivo del ejemplo
utilizando la funcion getc().
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    FILE *archi;
    int letra;

    /*abro el archivo*/
    if((archi = fopen("nombres.txt","rt")) == NULL)
    {
        printf("No se puedo abrir el archivo.\n");
        return EXIT_FAILURE;
    }

    letra = fgetc(archi);
    while (!feof(archi))
    {
        printf("\nNombre y Apellido: %c.",letra);
        letra = fgetc(archi);    
    }

    if(!fclose(archi))
    {
        printf("\nArchivo cerrado.\n");
    }
    else
    {
        printf("\nError al cerrar el archivo.\n");
    }
 

    return EXIT_SUCCESS;
}