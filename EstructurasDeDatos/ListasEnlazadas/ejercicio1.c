/*
Se va a formar una lista de N numeros aleatorios enteros (0 al 100). El programa realizara ésta tarea y los numeros se insertaran
al inicio de la lista.Una vez creada la lista se recorre la lista y se muestran los numeros pares
*/

#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include <time.h>

Nodo *cabeza;

int main()
{
    int N, i;
    cabeza = NULL;
    item x;

    printf("\nTeclea la cantidad de nros aleatorios que desee: ");
    scanf("%d",&N);

    srand(time(NULL));

    for(i = 0; i < N; i++)
    {
        x.nro = 1 + rand() %100;

        inserInic(&cabeza,x);
    }

    imprimirLista(cabeza);

    return EXIT_SUCCESS;
}

Nodo *CrearNodo (item x)
{
    Nodo *a;

    if((a = malloc (sizeof(Nodo))) == NULL)
    {
        printf("No se pudo reservar memoria para un nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }

    a->valor = x;
    a->siguiente = NULL;

    return a; //retorno la direccion el nuevo nodo
}

void inserInic (Nodo **cabeza, item valor)
{
    Nodo *nueva;
    nueva = CrearNodo(valor);
    nueva->siguiente = *cabeza;
    *cabeza = nueva;
}

void imprimirLista (Nodo *cabeza)
{
    Nodo *actual;

    printf("\nNumero aleatorios cargados en la lista:\n");
    for(actual = cabeza; actual!= NULL; actual = actual->siguiente)
    {
        printf("%d ",actual->valor.nro);
    }
    printf("\n\nLos numeros pares en al lista son:\n");
    for(actual = cabeza; actual!= NULL; actual = actual->siguiente)
    {
        if((actual->valor.nro) % 2 == 0)
        {
            printf("%d ",actual->valor.nro);
        }
    }

    printf("\n");
}

