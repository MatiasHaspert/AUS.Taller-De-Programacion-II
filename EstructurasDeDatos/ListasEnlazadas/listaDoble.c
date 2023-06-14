#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
    struct nodo *anterior;
    
}Nodo;

Nodo *cabeza;

void liberarLista (Nodo **);
int vacia();
int tamano();
void imprimirLista (Nodo *);
Nodo *CrearNodo (int );
void inserInic (Nodo **, int );
void insertar (Nodo **, Nodo *, int );
void insertarOrdenado (Nodo **, int );
void eliminarNodo (Nodo **,int );
Nodo * busqueda(Nodo *, int );

int main()
{
    cabeza = NULL;
    int i,n,nro;

    printf("\nTeclee la cantidad de numeros que desee ingresar: ");
    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        printf("Ingrese el nro %d#: ",i+1);
        scanf("%d",&nro);
        insertarOrdenado(&cabeza,nro);
    }

    imprimirLista(cabeza);

    printf("\nIngrese el nro que desee buscar en la lista: ");
    scanf("%d",&nro);

    Nodo *sal = busqueda(cabeza,nro);
    if(sal != NULL) printf("\nEl elemento %d se encuentra en la direccion %p\n",nro,sal);
    else printf("El elemento %d no se encuentra en la lista.\n",nro);

    printf("\nIngrese el nro que desea eliminar de la lista: ");
    scanf("%d",&nro);

    eliminarNodo(&cabeza,nro);
    // imprimimos la lista luego de eliminar un valor
    imprimirLista(cabeza);

    liberarLista(&cabeza);
    printf("\nLuego de liberar la lista: ");
    imprimirLista(cabeza);

    return EXIT_SUCCESS;
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

int vacia ()
{
    if(cabeza == NULL) return 1;
    else return 0;
}

int tamano ()
{
    Nodo *actual;
    actual = cabeza;
    int cant;
    while(actual != NULL)
    {
        cant++;
        actual = actual->siguiente;
    }

    return cant;
}

void imprimirLista (Nodo *cabeza)
{
    Nodo *actual;
    printf("\nLa lista es:\n");
    for(actual = cabeza; actual!= NULL; actual = actual->siguiente)
    {
        printf("%d ",actual->dato);
    }

    printf("\n");
}

Nodo *CrearNodo (int x)
{
    Nodo *a;

    if((a = malloc (sizeof(Nodo))) == NULL)
    {
        printf("No se pudo reservar memoria para un nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }

    a->dato = x;
    a->siguiente = NULL;
    a->anterior  = NULL;

    return a; //retorno la direccion el nuevo nodo
}


void insertar (Nodo **cabeza, Nodo *anterior, int valor)
{
    //si el valor del nodo anterior no se encuentra en la lista, el nuevo valor lo insertamos al inicio
    if(anterior == NULL || *cabeza == NULL) // si la cabeza apunta a null quiere decir que la lista esta vacia
    {
        inserInic(cabeza,valor); //lo insertamos al inicio
    }
    else //insertar un nuevo nodo entre el anterior y el siguiente
    {
        Nodo *nuevo = CrearNodo(valor); 
        nuevo->siguiente = anterior->siguiente;
        
        if(anterior->siguiente != NULL) anterior->siguiente->anterior = nuevo;
        
        nuevo->anterior = anterior;
        anterior->siguiente = nuevo;
    }
}


void insertarOrdenado (Nodo **cabeza, int valor)
{
    //si la cabeza apunta null(lista vacia) insertamos al inicio
    if(*cabeza == NULL) inserInic(cabeza,valor);
    else
    {    
        Nodo *actual = *cabeza;
        Nodo *anterior = NULL;
        //Buscamos en donde insertar (un lugar antes que el primer elemento mayor que encontremos)
        while(actual != NULL && actual->dato <= valor)
        {
            anterior = actual;
            actual = actual->siguiente;
        }
        insertar(cabeza,anterior,valor);
    }
}


void inserInic (Nodo **cabeza, int x)
{
    Nodo *nuevo;
    nuevo = CrearNodo(x);
    nuevo->siguiente = *cabeza;
    if(*cabeza != NULL) // si ya hay nodos en la lista
    {
        (*cabeza)->anterior = nuevo;
    }
    *cabeza = nuevo;
}

/*Funcion que elimina un nodo con un cierto item*/
void eliminarNodo (Nodo **cabeza,int valor)
{
    Nodo *actual = *cabeza; //en actual está el valor a eliminar y lo inicialzamos en la cabeza de la lista
    Nodo *anterior = NULL;

    //buscamos el dato que queremos eliminar
    while (actual != NULL && actual->dato != valor)
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
            if(actual->siguiente != NULL) actual->siguiente->anterior = anterior; 
            free(actual); //se libera el nodo, tener en cuenta el tipo de dato que se utiliza!
        }
    }
}

/*si encontramos el dato en la lista retornamos su direccion si no null*/
Nodo * busqueda(Nodo *cabeza, int dato)
{
    Nodo *actual;

    for(actual = cabeza; actual!= NULL; actual = actual->siguiente)
    {
        if(dato == actual->dato) return actual; //ésta condicion dependera del tipo de datos que utilizamos(ésta vez nros enteros)   
    }

    return NULL;        
}
