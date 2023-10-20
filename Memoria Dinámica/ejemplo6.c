#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenar (char **, int);
int main()
{
    int n;
    char **pal;
    char cad[31];
    size_t i;
    printf("Ingrese la cantidad de palabras que ingresará: ");
    scanf("%d",&n);

    if((pal = malloc(sizeof(char *) * n)) == NULL)
    {
        printf("Error al reservar memoria.\n");
        return EXIT_FAILURE;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nIngrese la palabra #%ld: ", i+1);
        scanf("%s",cad);

        if((pal[i] = malloc(sizeof(char) * strlen(cad)+1)) == NULL)
        {
            printf("Error al reservar memoria.\n");
            return EXIT_FAILURE;
        }

        strcpy(pal[i], cad);
    }

    printf("\nPalabras sin ordenar: \n");
    for ( i = 0; i < n; i++)
    {
        puts(pal[i]);
    }

    ordenar(pal, n);

    printf("\nPalabras ordenadas: \n");
    for ( i = 0; i < n; i++)
    {
        puts(pal[i]);
    }
    

    return EXIT_SUCCESS;
}

void ordenar(char **pal, int n)
{
    char *p;

    for (size_t i = 0; i < n-1; i++)
    {
        for (size_t j = i+1; j < n; j++)
        {
            if(strcmp(pal[i],pal[j]) > 0)
            {
                p = pal[i];
                pal[i] = pal[j];
                pal[j] = p;
            }
        }  
    }
}