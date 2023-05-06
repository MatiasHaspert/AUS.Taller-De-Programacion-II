#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char calle[25];
    int numero;

}direc;

int main()
{
    direc d;

    strcpy(d.calle,"Leandro alem");

    printf("La direccion de la calle es: %s",d.calle);
    
    return 0;
}