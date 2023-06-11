/*
El programa escribe los valores del 1 a 100 en un archivo
en disco 
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *archi;
    int i;

    archi = fopen("numeros.txt","wt"); // "wt" crea un archivo para escritura (w,crea un archivo de estritura) (t,es de tipo texto)
    /*válida que el archivo se haya creado correctamente*/
    if(archi != NULL)
    {
        for ( i = 1; i <= 100 ; i++)
        {
            /*se escriben los numeros*/
            fprintf(archi,"%d ",i);
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





}