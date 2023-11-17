#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *ip;
    char *mask;

}redes;

char * obtenerNumRed(redes *);

int main()
{
    redes *red = malloc(sizeof(redes));
    red->ip = malloc(sizeof(char) * 16);
    red->mask = malloc(sizeof(char) * 14);

    strcpy(red->ip,"192.168.146.222");
    strcpy(red->mask,"255.255.255.0");

    char *numero_de_red = obtenerNumRed(red);

    printf("\nIP: %s  -  Mask: %s  \n",red->ip,red->mask);
    printf("Numero de red: %s \n",numero_de_red);
    free(red->ip);
    free(red->mask);
    free(numero_de_red);
    free(red);

    return EXIT_SUCCESS;
}

char * obtenerNumRed(redes *red)
{
    char *num_red = malloc(sizeof(char) * 14);
    int i = 0;
    
    while(red->mask[i] != '\0')
    {
        if(red->mask[i] == '0')
        {
            num_red[i] = red->mask[i];
        }
        else
        {
            num_red[i] = red->ip[i];
        }
        i++;
    }
    
    num_red[i] = '\0';

    return num_red;
}