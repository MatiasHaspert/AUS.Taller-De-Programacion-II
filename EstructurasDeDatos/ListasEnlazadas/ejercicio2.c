/*
En la lista enlazada de nuestro programa, los elementos deben estar ordenados de forma ascendente.
Las opciones presentadas al usuario son las siguiente:
1- Ingresar N numeros aleatorios (2 al 100)
2- Eliminar todos los numeros compuestos
3- Mostrar la lista
4- eliminar la lista
5- Salir del programa
*/

#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include <time.h>

Nodo *cabeza;

#define N 100

void imprimirMensaje();
void insertarOrdenado(Nodo **,item);
void eliminarNrosCompuestos(Nodo **);
int esCompuesto (int );

int main()
{
    srand(time(NULL));
    cabeza = NULL;
    int cant_nros, opc;
    item x;

    do
    {
        imprimirMensaje();
        scanf("%d",&opc);

        switch (opc)
        {
            case 1:
                printf("\nTeclea la cantidad de numeros que deseas cargar aleatoriamente a la lista: ");
                scanf("%d",&cant_nros);

                for(int i = 0; i < cant_nros; i++)
                {
                    x.nro = 2 + rand() %(N-1);

                    insertarOrdenado(&cabeza,x);
                }

                printf("\nElementos agregados a la lista.\n");
                break;
            case 2:
                eliminarNrosCompuestos(&cabeza);
                printf("\nSe eliminaron los numeros compuestos.\n");    
                break;
            case 3:
                imprimirLista(cabeza);
                break;
            case 4:
                liberarLista(&cabeza);
                break;
            case 5:
                printf("\nPrograma finalizado.\n");
                return EXIT_SUCCESS;
                break;
            default:
                printf("\nOpcion no válida, teclea nuevamente.\n");
                break;
        }
    }while(opc != 5);

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

void imprimirLista (Nodo *cabeza)
{
    Nodo *actual;
    printf("\nLa lista es:\n");
    for(actual = cabeza; actual!= NULL; actual = actual->siguiente)
    {
        printf("%d ",actual->valor.nro);
    }

    printf("\n");
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

void imprimirMensaje()
{
    printf("\n(1)Ingresar N numeros aleatorios (2 al 100).\n");
    printf("(2)Eliminar todos los numeros compuestos.\n");
    printf("(3)Mostrar la lista.\n");
    printf("(4)Eliminar la lista.\n");
    printf("(5)Salir del programa.\n");
    printf("\nTeclea la opcion que deseas: ");
}

void insertar (Nodo **cabeza, Nodo *anterior, item valor)
{
    //si el valor del nodo anterior no se encuentra en la lista, el nuevo valor lo insertamos al inicio
    if(anterior == NULL || *cabeza == NULL) // si la cabeza apunta a null quiere decir que la lista esta vacia
    {
        inserInic(cabeza,valor); //lo insertamos al inicio
    }
    else
    {
        Nodo *nuevo = CrearNodo(valor); 
        nuevo->siguiente = anterior->siguiente;
        anterior->siguiente = nuevo;
    }
}

void insertarOrdenado (Nodo **cabeza, item valor)
{
    //si la cabeza apunta null(lista vacia) insertamos al inicio
    if(*cabeza == NULL) inserInic(cabeza,valor);
    else
    {    
        Nodo *actual = *cabeza;
        Nodo *anterior = NULL;
        //Buscamos en donde insertar (un lugar antes que el primer elemento mayor que encontremos)
        while(actual != NULL && actual->valor.nro <= valor.nro)
        {
            anterior = actual;
            actual = actual->siguiente;
        }
        insertar(cabeza,anterior,valor);
    }
}

void inserInic (Nodo **cabeza, item valor)
{
    Nodo *nueva;
    nueva = CrearNodo(valor);
    nueva->siguiente = *cabeza;
    *cabeza = nueva;
}

void eliminarNrosCompuestos(Nodo **cabeza)
{
    Nodo *actual, *siguiente;
    actual = *cabeza;

    while(actual != NULL)
    {
        siguiente = actual->siguiente;

        if(esCompuesto(actual->valor.nro) == 1)
        {
            eliminarNodo(cabeza,actual->valor);
        }

        actual = siguiente;
    }


}

/*Funcion que elimina un nodo con un cierto item*/
void eliminarNodo (Nodo **cabeza,item valor)
{
    Nodo *actual = *cabeza; //en actual está el valor a eliminar y lo inicialzamos en la cabeza de la lista
    Nodo *anterior = NULL;

    //buscamos el dato que queremos eliminar
    while (actual != NULL && actual->valor.nro != valor.nro)
    {   
        anterior = actual;
        actual = actual->siguiente;
    }

    if(actual == NULL) // significa que no se encontro el elemento(o la lista esta vacia)
    {
        if(*cabeza == NULL) printf("\nLista vacia.\n");
        else printf("\nNo se encontro el dato a eliminar.\n");
    }
    else
    {
        if(actual == *cabeza) //si lo que apunta actual es igual a lo que apunta la cabeza, es decir, el primer nodo de la lista, lo eliminamos
        {
            *cabeza = actual->siguiente;
            free(actual);
        }
        else
        {
            anterior->siguiente = actual->siguiente; 
            free(actual); //se libera el nodo, tener en cuenta el tipo de dato que se utiliza!
        }
    }
}

int esCompuesto (int nro)
{
    int cont = 0;

    for(int i = 1; i <= nro; i++)
    {
        if(nro % i == 0)
        {
            cont++;
        }
    }

    if(cont > 2) return 1;
    else return 0;
}