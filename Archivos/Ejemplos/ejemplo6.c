/*
Lee el archivo "abc.txt" de adelante hacia atras
*/
#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *archi;
    int i; // lee el archivo del último al primero
    int letra;


    archi = fopen("abc.txt","r");

    if(archi != NULL)
    {
        fseek(archi,1L,SEEK_END);
        for (i = 0; i <= 25; i++)
        {
            /*Al utilizar SEEK CUR el programa va retrocediendo 2 Bytes desde la posicion del puntero actual*/
            fseek(archi,-2L,SEEK_CUR);
            letra = getc(archi);
            printf("Letra leída: %c.\n",letra);
        }
        
    }
    else
    {
        printf("Error!\n");
    }


    if (fclose(archi) == 0)
    {
        printf("Se cerro el archivo.\n");
    }
    else
    {
        printf("Error al cerrar el archivo.\n");
    }
    


    return EXIT_SUCCESS;
}