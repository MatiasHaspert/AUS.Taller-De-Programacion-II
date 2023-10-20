#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char *ip;
    char *mask;
}red;

char * obtenerNumRed(red *);

int main()
{
    red *e1 = malloc(sizeof(red));
    e1->ip = malloc(sizeof(char) * 16); // 16 porque 15 caracteres y el caracter nulo;
    e1->mask = malloc(sizeof(char) * 14);
    char *numeroRed;

    strcpy(e1->ip,"192.168.146.222");
    strcpy(e1->mask, "255.255.255.0");

    puts(e1->ip);
    puts(e1->mask);

    numeroRed = obtenerNumRed(e1);

    puts(numeroRed);

    free(numeroRed);
    free(e1->ip);
    free(e1->mask);
    free(e1);

    return EXIT_SUCCESS;
}

char * obtenerNumRed(red *e)
{
    char *numeroRed = malloc(sizeof(char) * 16);

    int cont_puntos = 0;
    int i = 0;
    while(e->ip[i] != '\0' && cont_puntos < 3)
    {
        if(e->ip[i] == '.')
        {
            cont_puntos++;
        }
        numeroRed[i] = e->ip[i];
        i++;
    }
    numeroRed[i] = '0';
    numeroRed[++i] = '\0';

    return numeroRed; 
}