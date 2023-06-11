#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char IP[16];    
    char mascara[16];

}internet;

char* obtenernumeroRed (internet *info);

int main()
{
    internet i1;

    strcpy(i1.IP,"192.168.146.222");
    strcpy(i1.mascara,"255.255.255.0");    

    char* numeroRed = obtenernumeroRed(&i1); 

    printf("\nIP: %s\n",i1.IP);
    printf("Mascara: %s\n",i1.mascara);

    printf("\nNumero de red: %s\n",numeroRed);

    free(numeroRed);
    return EXIT_SUCCESS;
}

char* obtenernumeroRed(internet *info)
{
    char*numeroRed = malloc (16 * sizeof(char));

    strcpy(numeroRed,info->IP);

    int i;

    for ( i = 12; i < 16; i++)
    {
        strcpy(&numeroRed[i],"0");
    }

    numeroRed[15] = '\0';
    
    return numeroRed;

}
