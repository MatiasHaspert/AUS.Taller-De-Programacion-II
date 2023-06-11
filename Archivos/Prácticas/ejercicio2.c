/*
dado un archivo "suma.txt" que contiene numeros enteros, indicar la suma de los enteros positivos
y la suma de los enteros negativos(guardarlos en el mismo archivo)
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *archi;            

    if((archi = fopen("suma.txt","r+")) == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return EXIT_FAILURE;
    }

    int x, sumapos = 0, sumaneg = 0;

    while(!feof(archi))
    {
        fscanf(archi,"%d",&x);
        if(x >= 0)sumapos += x;        
        else sumaneg += x;     
    }
    /*y como archi ya se encuentra en el final del archivo se los escribimos*/

    fprintf(archi,"\nLa suma de los enteros positivos es: %d.",sumapos);
    fprintf(archi,"\nLa suma de los enteros negativos es: %d.",sumaneg);

    if(!fclose(archi)) printf("El archivo %s se cerro correctamente.\n","suma.txt");
    else printf("Error.\n");

    return EXIT_SUCCESS;
}