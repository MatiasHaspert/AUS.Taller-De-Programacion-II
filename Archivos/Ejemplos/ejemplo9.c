/*
Haga una copia exacta del archivo NOMBRES.DAT pero el nuevo que sea
binario.
*/

#include <stdio.h>
#include <stdlib.h>
void closefich (FILE *);
int main()
{
    FILE *archi, *archi2;

    if((archi = fopen("nombres.txt","r")) == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return EXIT_FAILURE;
    }

    if((archi2 = fopen("./nombresBin","w+b")) == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return EXIT_FAILURE;
    }

    int letra;
    letra = fgetc(archi);
    while(!feof(archi))
    {
        fputc(letra,archi2);
        letra = fgetc(archi);
    }

    closefich(archi);
    closefich(archi2);
    
    return EXIT_SUCCESS;
}

void closefich (FILE *archi)
{
    if(!fclose(archi))
    {
        printf("El archivo se cerro correctamente.\n");
    }
    else
    {
        printf("Error al cerrar el archivo.\n");
    }
}