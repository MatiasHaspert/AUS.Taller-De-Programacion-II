#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
}Nodo;

Nodo *inicio;

void insertar(Nodo **, int);
void eliminar(Nodo **, int);
void print_lista(Nodo *);
void liberar_lista(Nodo **);

void print_lista(Nodo *inicio)
{
    Nodo *aux = inicio;
    printf("\nLista: \n");
    
    if(inicio == NULL)
        printf("\nNo existen elementos a mostrar.\n");
    while(aux != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->siguiente;
    }
}

void insertar(Nodo **inicio, int d)
{
    Nodo *nuevo = malloc(sizeof(Nodo));
    nuevo->dato = d;
    
    if(*inicio == NULL)
    {
        nuevo->siguiente = *inicio;
        *inicio = nuevo;
    }
    else
    {
        if((*inicio)->dato > d) //cuando se inserta al inicio
        {
            nuevo->siguiente = *inicio;
            *inicio = nuevo;
        }
        else if((*inicio)->dato < d && (*inicio)->siguiente != NULL && (*inicio)->siguiente->dato > d) //cuando esta entre dos
        {
            nuevo->siguiente = (*inicio)->siguiente;
            (*inicio)->siguiente = nuevo;
        }
        else if((*inicio)->dato == d)
        {
            printf("Ya existe el elemento %d en la lista.\n", d);
        }
        else
        {
            insertar(&(*inicio)->siguiente, d);
        }
    }
}

void eliminar(Nodo **inicio, int d)
{
    Nodo *aux;
    if(*inicio == NULL)
    {
        printf("\nNo existe el elemento a eliminar.");
    }
    else
    {
        if((*inicio)->dato == d) // el dato se encuentra en el inicio
        {
            aux = *inicio;
            *inicio = (*inicio)->siguiente;
            free(aux);
        }
        else if((*inicio)->dato < d && (*inicio)->siguiente != NULL && (*inicio)->siguiente->dato == d)
        {
            aux = (*inicio)->siguiente;
            (*inicio)->siguiente = (*inicio)->siguiente->siguiente;
            free(aux);
        }
        else
        {
            eliminar(&(*inicio)->siguiente, d);
        }
    }
}

void liberar_lista(Nodo **inicio)
{
    Nodo *aux;
    while(*inicio != NULL)
    {
        aux = *inicio;
        *inicio = aux->siguiente;
        free(aux);
    }

    printf("\nLista liberada.\n");
}
