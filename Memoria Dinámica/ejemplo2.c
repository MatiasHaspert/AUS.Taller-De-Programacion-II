#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * ingreso () 
{
    char frase [256];
    printf("Ingrese una frase: ");

    scanf( "%[^,'\n']",frase);

    char *frase1 = (char *) malloc(strlen(frase)) ;

    strcpy (frase1,frase);

    return frase1 ;
}

int main()
{
    char *frase = ingreso();

    printf("Frase ingresada: %s.\n",frase);

    printf("Frase modificada : %s - largo %d \n",frase, (int)strlen(frase));

    free(frase);

    return EXIT_SUCCESS;
}