#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char c;
    char *cadena;
}char_string;

int cantidad (char_string *frase);
int * ocurrencias (char_string *frase, int cantidad);

int main()
{
    char_string *frase = malloc(sizeof(char_string));
    frase->cadena = malloc(sizeof(char) * 100);

    printf("Ingresa una frase: ");
    fgets(frase->cadena,100,stdin);

    printf("Ingresa un caracter a buscar en la frase: ");
    scanf("%c",&frase->c);
    
    printf("\nCantidad de veces que aparecio %c en la frase: %d veces\n",frase->c, cantidad(frase));

    int *ocu;
    ocu = ocurrencias(frase,cantidad(frase));

    int i = 0;
    printf("Posiciones en los que se ubica el caracter ingresado en la frase:\n");
    while (i < cantidad(frase))
    {
        printf("%d ",ocu[i]);
        i++;
    }
    printf("\n");
    free(ocu);
    free(frase->cadena);
    free(frase);
    
    return EXIT_SUCCESS;
}


int cantidad (char_string *frase)
{
    int i = 0;
    int cont = 0;

    while (frase->cadena[i] != '\0')
    {
        if(frase->cadena[i] == frase->c)
            cont++;

        i++;    
    }
    
    return cont;
}

int *ocurrencias (char_string *frase, int cantidad)
{
    int *ocu = malloc(sizeof(int) * cantidad);
    int i = 0;
    int cont = 0;
    while (frase->cadena[i] != '\0')
    {
        if(frase->cadena[i] == frase->c)
        {
            ocu[cont] = i+1;
            cont++;
        }
        i++;    
    }

    return ocu;
}

