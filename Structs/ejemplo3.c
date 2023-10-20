#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona
{
    char nombre[20];
    int edad;
}Persona;

int main()
{
    Persona juan, maria;

    strcpy(juan.nombre, "Juan");
    printf("\nEdad: ");
    scanf("%d",&juan.edad);


    strcpy(maria.nombre, "Maria");
    printf("\nEdad: ");
    scanf("%d",&maria.edad);

    printf("\nUsuarios:\n");
    printf("%s %d",juan.nombre, juan.edad);
    printf("\n%s %d",maria.nombre, maria.edad);
    
    return EXIT_SUCCESS;
}