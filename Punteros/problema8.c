/*
Implementar una función que intercambie el contenido de dos variables enteras, utilizar punteros para solucionarlo.
*/

#include <stdio.h>
#include <stdlib.h>

void intercambia (int *,int *);

int main()
{
    int x1 = 10,x2 = 20;

    printf("%d y %d\n",x1,x2);

    intercambia(&x1,&x2);

    printf("%d y %d.\n",x1,x2);

    return EXIT_SUCCESS;
}

void intercambia (int *valor1,int *valor2)
{
    int aux;
    aux = *valor1;
    *valor1 = *valor2;
    *valor2 = aux;    
}