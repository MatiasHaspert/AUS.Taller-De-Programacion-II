/*
Confeccionar una función que reciba como parámetros las direcciones de dos variables enteras
y le cargue a lo apuntado por dichas variables dos enteros.
*/

#include <stdio.h>
#include <stdlib.h>

void carga(int *,int *);

int main()
{
    int x1,x2;

    carga(&x1,&x2);

    printf("Los valores ingresados son %d y %d.\n",x1,x2);

    return EXIT_SUCCESS;

}

void carga(int *num1,int *num2)
{

    *num1 = 100;

    *num2 = 200;

}