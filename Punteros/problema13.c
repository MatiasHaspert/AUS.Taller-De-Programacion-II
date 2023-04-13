/*
Implementar la función:
int largo(char *cadena)

*/

/*
Se define en la main un vector de tipo char de 40 caracteres.
Implementar las funciones de carga e impresión de dicho vector 
utilizando la sintaxis de punteros cuando definamos los parámetros de las funciones.
*/

#include <stdio.h>
#include <stdlib.h>

void carga(char *);
void imprimir(char *, int );
int largo (char *);

int main()
{
    char A[40];

    carga(A);

    largo(A);

    imprimir(A,(largo(A)));

    return EXIT_SUCCESS;
}

void carga(char *A)
{
    printf("Ingrese una palabra:");
    scanf("%s",A);
    
}

int largo (char *A)
{
    int i = 0;
    int largo = 0;
    while (A[i] != '\0')
    {
        largo++;

        i++;
    }

    return largo;
    

}

void imprimir(char *A,int largo)
{
    printf("Palabra ingresada: %s\n",A);

    printf("La longitud de la palabra es %d.\n",largo);
}