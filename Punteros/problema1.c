/*
Definir dos variables enteras y almacenar valores por asignación. Definir una variable puntero a entero 
y guardar sucesivamente las direcciones de dichas dos variables y acceder a sus valores.
*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int valor1 = 10;
    int valor2 = 20;
    int *pe; // *pe es una variable que apunta a una dirección de memoria donde se almacena un entero

    pe = &valor1; // almacenar en la variable pe la dirección de memoria donde se almacena valor1

    printf("pe apunta a: %d.\n",*pe);
    printf("La direccion a la que apunta pe es: %p.\n",pe);

    pe = &valor2; // Una variable de tipo puntero puede cambiar la dirección que almacena a lo largo de la ejecución del programa

    printf("Lo apuntado por pe es: %d.\n",*pe);
    printf("La direccion a la que apunta pe es: %p.\n",pe);


    return EXIT_SUCCESS;
}