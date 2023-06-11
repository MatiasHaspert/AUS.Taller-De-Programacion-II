/*
Dado los siguientes prototipos, hacer un programa en que se pida una frase y una letra.
1. La funcion cantidad retornara el numero de veces que se encuentra la letra en la frase.
2. La funcion ocurrencias retornara las posiciones en las que se encuentran dicha letra en la frase.
OBS: No debe usar las funciones de string.h para el parseo de la cadena.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char c;
char *cadena;
} char_string;

int cantidad (char_string *frase);
int *ocurrencias(char_string *frase, int cantidad);

int main()
{
    char_string frase;
    char_string *p_frase = &frase;
    int cant=0;
    int *posiciones;
    p_frase->cadena = "hola que tal";
    p_frase->c = 'a';
    
    cant = cantidad(p_frase);

    printf("La cantidad de veces que aparece el cáracter '%c' en la frase son %d.\n",p_frase->c,cant);

    posiciones = ocurrencias(p_frase,cant);

    for (int i = 0; i < cant; i++)
    {
        printf("Posición: [%d] \n",posiciones[i]);
    }
    
    free(posiciones);
    
    return EXIT_SUCCESS;
}

int cantidad (char_string *frase)
{
    int cont = 0;
    int i = 0;

    while(frase->cadena[i] != '\0')
    {
        if(frase->cadena[i] == frase->c)
        {
            cont++;
        }

        i++;
    }

    return cont;
}


int *ocurrencias(char_string *frase, int cantidad)
{
    int *ocurrencias = malloc(sizeof(int)*cantidad);
    int count = 0;
    char *ptr = frase->cadena;

    for (int i = 0; i < cantidad; i++)
    {
        while (*ptr != '\0') 
        {
            if (*ptr == frase->c) {
                ocurrencias[count++] = ptr - frase->cadena;
            }
            ptr++;
        }
        ptr = frase->cadena;
    }
    
    return ocurrencias;
}