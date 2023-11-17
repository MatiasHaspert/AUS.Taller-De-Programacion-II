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
int main()
{
    inicio = NULL;
   
    int n = 1;
    eliminar(&inicio, n);
    while(n != 0)
    {
        printf("Ingrese un N° (0 = Fin): ");
        scanf("%d", &n);
        if(n != 0)
            insertar(&inicio, n);
    }

    eliminar(&inicio,3);
    print_lista(inicio);
    eliminar(&inicio, 5);
    print_lista(inicio);
    eliminar(&inicio,4);
    print_lista(inicio);
    return EXIT_SUCCESS;
}

void print_lista(Nodo *inicio)
{
    Nodo *aux = inicio;
    printf("\nLista doblemente enlazada: \n");
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

