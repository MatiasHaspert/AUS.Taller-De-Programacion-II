#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

Nodo *cabeza; //va a tener siempre la direccion del primer elemento de la lista

int main()
{
    cabeza = NULL;
    int i,n;
    item x;
    
    printf("\nTeclee la cantidad de numeros que desee ingresar: ");
    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        printf("Ingrese el nro %d#: ",i+1);
        scanf("%d",&x.nro);
        inserInic(&cabeza,x);
        //inserFinal(&cabeza,x);
    }

    imprimirLista(cabeza);

    printf("\nIngrese el nro que desee buscar en la lista: ");
    scanf("%d",&x.nro);

    Nodo *sal = busqueda(cabeza,x);
    if(sal != NULL) printf("\nEl elemento %d se encuentra en la direccion %p\n",x.nro,sal);
    else printf("El elemento %d no se encuentra en la lista.\n",x.nro);

    printf("\nLuego de que numero desea insertar otro: ");
    scanf("%d",&x.nro);
    sal = busqueda(cabeza,x); //si el valor no se encuentra lo inserta al inicio
    
    printf("\nIngrese un numero que desee insertar luego del %d: ",x.nro);
    scanf("%d",&x.nro);
    insertar(&cabeza,sal,x);
    
    //imprimimos la lista luego de insertar un nuevo nodo
    imprimirLista(cabeza);

    printf("\nIngrese el nro que desea eliminar de la lista: ");
    scanf("%d",&x.nro);

    eliminarNodo(&cabeza,x);
    // imprimimos la lista luego de eliminar un valor
    imprimirLista(cabeza);

    printf("\nEliminamos todos los elementos de la lista.\n");
    liberarLista(&cabeza);
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
    printf("\nLa lista es:\n");
    for(actual = cabeza; actual!= NULL; actual = actual->siguiente)
    {
        printf("%d ",actual->valor.nro);
    }

    printf("\n");
}

/*si encontramos el dato en la lista retornamos su direccion si no null*/
Nodo * busqueda(Nodo *cabeza, item dato)
{
    Nodo *actual;

    for(actual = cabeza; actual!= NULL; actual = actual->siguiente)
    {
        if(dato.nro == actual->valor.nro) return actual; //ésta condicion dependera del tipo de datos que utilizamos(ésta vez nros enteros)   
    }

    return NULL;        
}

void inserFinal (Nodo **cabeza, item valor)
{
    Nodo *ultimo;
    
    ultimo = *cabeza; // nodo pivot le asignamos la direccion del primer elemento de la lista

    if(ultimo == NULL) //si el nodo pivot apunta a null quiere decir que la lista está vacía;
    {
        *cabeza = CrearNodo(valor); 
    }
    else
    {
        while(ultimo->siguiente != NULL) ultimo = ultimo->siguiente;

        ultimo->siguiente = CrearNodo(valor);
    }
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