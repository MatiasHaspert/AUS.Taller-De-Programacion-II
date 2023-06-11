#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenar (char **, int );
int main()
{
    int n,i;

    printf("Ingrese la cantidad de palabras: ");
    scanf("%d",&n);

    //reservo memoria para las palabras(sería tipo un array de caracteres) char pal[n][2000]
    char **pal = malloc(n * sizeof(char *));
    if(pal == NULL)
    {
        printf("Error al reservar memoria.\n");
        return EXIT_FAILURE;
    }

    char cad[31];

    for ( i = 0; i < n; i++)
    {
        printf("Ingrese la palabra %d)> ",i+1);
        scanf("%s",cad);

        if((pal[i] = malloc ((strlen(cad)+1) * sizeof(char))) == NULL) //strlen + 1 porque la funcion no cuenta el caracter de finalizacion de la cadena
        {
            printf("Error al reservar memoria en la palabra %d.\n",i+1);
            return EXIT_FAILURE;
        }

        strcpy(pal[i],cad);
    }

    ordenar(pal,n);

    printf("\nPalabras ordenadas alfabéticamente:\n");
    for(i = 0; i < n; i++) puts(pal[i]);

    for(i = 0; i < n; i++)free(pal[i]); //liberamos el espacio para cada una de las palabras

    free(pal);
    

    return EXIT_SUCCESS;
}

void ordenar (char **pal, int n)
{
    char *temp;
    int j,i;

    for(i = 0; i < n-1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(strcmp(pal[i],pal[j]) > 0)
            {
                temp = pal[i];
                pal[i] = pal[j];
                pal[j] = temp;
            }
        }
    }
}