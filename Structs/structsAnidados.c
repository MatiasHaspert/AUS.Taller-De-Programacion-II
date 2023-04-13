#include <stdio.h>
#include <stdlib.h>

struct domicilio
{
    char calle[30];
    char numero[10]; //tipo de dato char porque solamente es para almacenarlos
    int piso;
    char dto[5];

};

struct cliente
{
    char dni[12];
    char nombre[20];
    struct domicilio dom;

};


int main()
{
    struct cliente c;

    printf("Ingrese su dni: ");
    scanf("%s",c.dni);

    printf("Ingrese su nombre: ");
    scanf("%s",c.nombre);

    printf("Ingrese su calle: ");
    scanf("%s",c.dom.calle);

    printf("Dni: %s\n",c.dni);
    printf("Nombre: %s\n",c.nombre);
    printf("Calle: %s\n",c.dom.calle);


    return EXIT_SUCCESS;
}