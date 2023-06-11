/*
Lecturas de palabras en un archivo y guardarlas en un arreglo de caracteres(matriz)
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 51 //50 caracteres + 1 (el terminal de cadena)

int main()
{
    FILE *pf;

    if((pf = fopen("palabras.txt","r")) == NULL)
    {
        printf("Error al abrir el archivo.\n");
    }

    //leo las lineas y las contabilizo(cada linea significa una palabra)
    int l=0; //cuento las palabras
    char palabra[51];
    while(!feof(pf))  //mientras no llegue al final del archivo
    {
        fscanf(pf,"%s",palabra);
        l++;
    }

    printf("\nCantidad de letras en el archivo %d.\n",l);

    //nos encontramos en el final del archivo
    //para volver al inicio exite una funcion void rewind(FILE *p)
    rewind(pf);

    //leemos las palabras del archivo y las almaceno en la matriz
    char palabras[l][TAM];
    int i = 0;
    while(!feof(pf))  //mientras no llegue al final del archivo
    {
        fscanf(pf,"%s",palabras[i]);
        i++; //incremento la posicion de la fila en palabras
    }

    printf("Palabras leídas del archivo:\n");
    for ( i = 0; i < l; i++)
    {
        printf("%s \n",palabras[i]);
    }

    //cierre de archivos
    if(!fclose(pf)) printf("El archivo se cerro correctamente.\n");
    else printf("Error.\n");
    
    return EXIT_SUCCESS;
}