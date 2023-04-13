/*
Elaborar una función que se le pase la dirección de una variable entera e incremente en 1 lo apuntado por dicha variable.
*/

#include <stdio.h>
#include <stdlib.h>

void incrementa (int *);

int main()
{
    int valor = 1;

    printf("Valor antes de ingresar a la función: %d\n",valor);

    incrementa(&valor);

    printf("El valor luego de ingresar a la función %d.\n",valor);

    
    return EXIT_SUCCESS;
}

void incrementa(int *x1)
{
    *x1 += 1;
}