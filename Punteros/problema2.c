/*
Definir dos variables enteras y no inicializarlas.
Definir una variable puntero a entero, hacer que apunte sucesivamente a las dos variables enteras definidas previamente 
y cargue sus contenidos.
Imprimir las dos variables enteras.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor1,valor2;
    int *pe;

    pe = &valor1;

    *pe = 100;

    pe = &valor2;

    *pe = 200;

    printf("Variable uno: %d.\n",valor1); 

    printf("Variable dos: %d.\n",valor2); 

    return EXIT_SUCCESS;
}