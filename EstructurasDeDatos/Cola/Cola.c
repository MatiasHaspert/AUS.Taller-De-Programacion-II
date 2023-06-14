#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"

Nodo *inicio;
Nodo *final;

int main()
{
    inicio = NULL;
    final  = NULL;
    int i,N;
    int nro;

    printf("\nTeclea la cantidad de numeros que desee ingresar: ");
    scanf("%d",&N);
    
    printf("\nIngrese los numeros a la queue:\n");

    for ( i = 0; i < N; i++)
    {
        printf("%d#: ",i+1);
        scanf("%d",&nro);
        enQueue(&inicio,&final,nro);
    }

    printf("\nQueue tiene %d elementos.\n",tamano(inicio));
    printf("\nElemento en el inicio de la queue: %d.\n",frente(inicio));
    printf("\nElementos extraidos de la queue:\n");

    while(!queueVacia(inicio)) printf("%d ",deQueue(&inicio,&final));
    
    /*underflow*/
    printf("%d ",deQueue(&inicio,&final));
    liberarQueue(&inicio);
    return EXIT_SUCCESS;
}

Nodo* crearQueue(item x)
{
    Nodo *nuevo = malloc(sizeof(Nodo));

    nuevo->dato = x;
    nuevo->siguiente = NULL;
    
    return nuevo;  
}

int queueVacia (Nodo *inicio)
{
    if(inicio == NULL) return 1;
    else return 0;
}

void enQueue(Nodo **inicio, Nodo **final, item x)
{
    Nodo *nuevo = crearQueue(x);

    if(queueVacia(*inicio) == 1) //es decir la cola se encuentra vacia
    {
        *inicio = nuevo;
        *final = nuevo;
    }
    else
    {
        (*final)->siguiente = nuevo;
        *final = nuevo;
    }
}

item deQueue(Nodo **inicio, Nodo **final)
{
    if(queueVacia(*inicio) == 1)
    {
        printf("\nQueue vacia, no se pudo extrar un dato.\n");
        exit(EXIT_FAILURE);
    }

    Nodo *pivot;
    
    pivot = *inicio;
    item x = pivot->dato;

    *inicio = pivot->siguiente;
    
    free(pivot);
    return x;
}

item frente (Nodo *inicio)
{
    if(queueVacia(inicio) == 1)
    {
        printf("\nQueue vacia.\n");
        exit(EXIT_FAILURE);
    }

    return inicio->dato;
}

void liberarQueue (Nodo **inicio)
{
    Nodo *actual;
    while(!queueVacia(*inicio))
    {
        actual = *inicio;
        *inicio = actual->siguiente;
        free(actual);
    }
}

int tamano (Nodo *inicio)
{   
    Nodo *actual;
    int cant = 0;

    for(actual = inicio; actual != NULL; actual = actual->siguiente)
    {
        cant++;
    }

    return cant;
}

