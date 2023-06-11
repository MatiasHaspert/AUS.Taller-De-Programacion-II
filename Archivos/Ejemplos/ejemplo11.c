/*
leo las palabras del archivo binario escribir.txt
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cadena[2][20];

    FILE *archi;

    if((archi = fopen("escribir.txt","rb")) == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return EXIT_SUCCESS;
    }

    for (int i = 0; i < 2; i++)
    {
        fread(cadena[i],sizeof(char),sizeof(cadena),archi);
    }

    printf("Palabras leídas del archivo:\n");
    for (int i = 0; i < 2; i++)
    {
        printf("\n%s ",cadena[i]);
    }
        
    return EXIT_SUCCESS;
}