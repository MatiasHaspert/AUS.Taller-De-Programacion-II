/*
Lectura de un archivo
fseek() permite leer un archivo hasta un punto espec ́ıfico. Su formato es
simple:
fseek(puntero a archivo, numero entero long, origen);
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *archi;
    int letra;
    archi = fopen("abc.txt","w+");

    if(archi != NULL)
    {
        /*escribe las letras usando ascii*/
        for (letra = 65; letra <= 90; letra++)
        {
            putc(letra,archi);
        }

        /*Posiciona al puntero en el 3er bytes ("3L" porque recibe un entero largo)*/
        fseek(archi,3L,SEEK_SET);
        letra = getc(archi);

        /*imprimo la letra leida del archivo*/
        printf("\nPrimera letra leída: %c.\n",letra);

        /*Posiciono al puntero en el 10mo bytes*/
        fseek(archi,10L,SEEK_SET);
        letra = getc(archi);
        printf("\nSegunda letra leída: %c.\n",letra);
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