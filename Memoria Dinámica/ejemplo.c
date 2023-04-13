#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *mensaje = "Hola Mundo!";
    char *pc = (char*) malloc(20 * sizeof (char)); // reservo memoria

    for (int i = 0; i < strlen(mensaje); i++)
    {
        *(pc + i) = *(mensaje + i);
    }

    printf("%s\n", pc);
    free(pc); // libero
    pc = NULL; // lo igualo a null para no volver a utilizar el espacio de memoria al que apunta  
     
}