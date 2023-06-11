/*
Apertura y escritura de archivos
Lo que suele ser recomendable es que el archivo se habra siempre con la opcion de lectura y
escritura y de forma binaria (ya que esta compresion ayuda a que si el volumen
de lo grabado es grande, el archivo este comprimido. ("w+b")

fwrite().
El prototipo de la primera es el siguiente:
t size fwrite(const void *ptr, size t tama ̃no, size t nmiemb, FILE *pArchivo);
En donde:
ptr es el puntero al registro de elementos a escribir.
tamaño es el tamano en bytes de cada elemento a escribir.
nmiemb es el n ́umero de elementos, cada uno con un tamano en bytes.
pArchivo es el puntero al objeto archivo que ser a la salida.
El retorno de la funcion un elemento de tipo t size que sera el total de los
elementos escritos y que debera coincidir con nmiemb para que no sea error
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cadena[2][20];   

    for (int i = 0; i < 2; i++)
    {
        printf("Ingrese la (%d) palabra al archivo:\n", i+1);
        printf("> ");
        fgets(cadena[i],20,stdin);
    }

    FILE *archi = fopen("escribir.txt","w+b");
    int byte;
    if(archi != NULL)
    {
        byte = fwrite(cadena,sizeof(char),sizeof(cadena),archi);
        printf("Cantidad de bytes que se guardaron en el archivo: %d\n",byte);
    }
    else
    {
        printf("Error!\n");
    }

    fclose(archi);

    return EXIT_SUCCESS;
}