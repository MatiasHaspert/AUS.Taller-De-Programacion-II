#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int valor;
    struct nodo *siguiente;
    struct nodo *anterior;
}Nodo;

Nodo *inicio;

void insertar(Nodo **, int);
int listaVacia(Nodo *);
void print_lista(Nodo *);
void eliminar(Nodo **, int);

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

int listaVacia(Nodo *inicio)
{
    if(inicio == NULL) return 1;
    else return 0;
}

void print_lista(Nodo *inicio)
{
    Nodo *aux = inicio;
    printf("\nLista doblemente enlazada: \n");
    while(aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->siguiente;
    }
}

void insertar(Nodo **inicio, int d)
{
    Nodo *nuevo = malloc(sizeof(Nodo));
    nuevo->valor = d;

    if(listaVacia(*inicio))
    {
        nuevo->siguiente = *inicio;
        nuevo->anterior = *inicio;
        *inicio = nuevo;
    }
    else
    {
        if((*inicio)->valor > d)
        {
            nuevo->siguiente = *inicio;
            nuevo->anterior  = (*inicio)->anterior;
            *inicio = nuevo;
        }
        else if((*inicio)->valor < d && (*inicio)->siguiente != NULL && (*inicio)->siguiente->valor > d) //cuando esta entre dos
        {
            nuevo->siguiente = (*inicio)->siguiente;
            (*inicio)->siguiente = nuevo;
            nuevo->anterior = *inicio;
            (*inicio)->siguiente->anterior = nuevo;
        }
        else if((*inicio)->valor == d)
        {
            printf("\nEl elemento %d ya existe en la lista.\n",d);
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

    if(listaVacia(*inicio))
    {
        printf("\nNo existen elementos a eliminar.\n");
        return;
    }
    else
    {
        if((*inicio)->valor == d)
        {
            aux = *inicio;
            (*inicio)->siguiente->anterior = (*inicio)->anterior;
            *inicio = (*inicio)->siguiente;
            free(aux);
        }
        else if((*inicio)->valor < d && (*inicio)->siguiente != NULL && (*inicio)->siguiente->valor == d)
        {
            aux = (*inicio)->siguiente;

            if((*inicio)->siguiente->siguiente == NULL) // si se elimina el ultimo elemento
            {
                (*inicio)->siguiente = (*inicio)->siguiente->siguiente;
                free(aux);
            }
            else
            {
                (*inicio)->siguiente = (*inicio)->siguiente->siguiente;
                (*inicio)->siguiente->anterior = *inicio;
                free(aux);
            }
        }
        else
        {
            eliminar(&(*inicio)->siguiente, d);
        }
    }
}

