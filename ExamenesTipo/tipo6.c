#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * eco(const char *);

int main()
{
    char *cadena = eco("Perro");

    printf("%s",cadena);

    free(cadena);
    return EXIT_SUCCESS;
}

char *eco(const char *cad)
{
    int longitud = strlen(cad);
    char *cadena = malloc(sizeof(char) * (longitud+4));

    char ultimo_caracter = cad[longitud-1];
    int i = 0;
    while(i < longitud+4)
    {
        if(i < longitud-1)
        {
            cadena[i] = cad[i];
        }
        else
        {
            cadena[i] = ultimo_caracter;
        }
        i++;
    }
    cadena[i] = '\0';

    return cadena;
}