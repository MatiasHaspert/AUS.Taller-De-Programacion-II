/*
implementar una lista ordenada respecto al campo usuario;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    char usuario[41];
    struct nodo *siguiente;

}Nodo;

Nodo *cabeza;

Nodo* CrearNodo(char *);
void inserInic (Nodo **, char *);
void insertar (Nodo **, Nodo *, char *);
void imprimirLista (Nodo *);
void insertarOrdenado(Nodo **,char *);
void liberarLista (Nodo **);

int main()
{
    char usuario[41];
    int cant,i;
    cabeza = NULL;

    printf("\nTeclea la cantidad de usuarios que desee ingresar: ");
    scanf("%d",&cant);

    for(i = 0; i < cant; i++)
    {
        printf("\nNombre del usuario %d#: ",i+1);
        scanf("%s",usuario);

        insertarOrdenado(&cabeza,usuario);
    }

    imprimirLista(cabeza);

    liberarLista(&cabeza);
    return EXIT_SUCCESS;
}

Nodo *CrearNodo (char *x)
{
    Nodo *a;

    if((a = malloc (sizeof(Nodo))) == NULL)
    {
        printf("No se pudo reservar memoria para un nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(a->usuario,x);
    a->siguiente = NULL;

    return a; //retorno la direccion el nuevo nodo
}

void inserInic (Nodo **cabeza, char *x)
{
    Nodo *nueva;
    nueva = CrearNodo(x);
    nueva->siguiente = *cabeza;
    *cabeza = nueva;
}

void imprimirLista (Nodo *cabeza)
{
    Nodo *actual;
    printf("\nLa lista es:\n");
    for(actual = cabeza; actual!= NULL; actual = actual->siguiente)
    {
        printf("%s\n ",actual->usuario);
    }

    printf("\n");
}

void insertar (Nodo **cabeza, Nodo *anterior, char *x)
{
    //si el valor del nodo anterior no se encuentra en la lista, el nuevo valor lo insertamos al inicio
    if(anterior == NULL || *cabeza == NULL) // si la cabeza apunta a null quiere decir que la lista esta vacia
    {
        inserInic(cabeza,x); //lo insertamos al inicio
    }
    else
    {
        Nodo *nuevo = CrearNodo(x);
        nuevo->siguiente = anterior->siguiente;
        anterior->siguiente = nuevo;
    }
}

void liberarLista (Nodo **cabeza)
{
    Nodo *primero;//eliminamos el primer nodo de la lista

    while(*cabeza != NULL)
    {
        primero = *cabeza;
        *cabeza = primero->siguiente;

        free(primero);
    }
}

void insertarOrdenado (Nodo **cabeza, char *x)
{
    //si la cabeza apunta null(lista vacia) insertamos al inicio
    if(*cabeza == NULL) inserInic(cabeza,x);
    else
    {    
        Nodo *actual = *cabeza;
        Nodo *anterior = NULL;
        //Buscamos en donde insertar (un lugar antes que el primer elemento mayor que encontremos)
        while(actual != NULL && strcmp(actual->usuario,x) < 0)
        {
            anterior = actual;
            actual = actual->siguiente;
        }
        insertar(cabeza,anterior,x);
    }
}

