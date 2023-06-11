#include "pila.h"
#include<stdio.h>
#include<stdlib.h>

nodo *pila; //(CIMA) variable global (cualquier funcion puede acceder) (siempre guarda la direccion del primer nodo)

int main()
{
    pila = NULL; //el primer nodo es vacio

    cargar();
    printf("\nCantidad de elementos en la pila: %d.\n",tamano(pila));
    printf("\nElemento en la cima de la pila: %d.\n",cima());
    printf("\nValores ingresados y liberados de la pila:\n");
    listar();
}

void cargar(){
    int n = 1;

    while(n != 0){
        printf("Ingrese un N° (0 = Fin): ");
        scanf("%d", &n);
        if (n != 0)
            push(&pila, n);
    }
}

void listar(){
        
    while (pila != NULL)
        printf("%d ", pop(&pila)); // va a recorrer toda la pila hasta que llegue al último nodo que apunta a null
    
}

/*insertar*/
void push (nodo **pila, item v){
    printf("Ingresa a push\n");

    struct nodo *nuevo = NULL;

    nuevo = (struct nodo*)malloc(sizeof(struct nodo)); //creamos el nuevo nodo
    nuevo->valor = v; // almacenamos el valor ingresado en un nuevo nodo

    nuevo->siguiente = *pila; //el nuevo nodo lo hacemos apuntar al que hasta ese momento era el primer nodo, es decir, al nodo al que apunta la raiz actualmente

    *pila = nuevo;  // y la raiz siempre apunta a la direccion del primer nodo
}

item pop (nodo **pila){
    
    nodo *pnodo = NULL; //creamos un nodo auxiliar
    item v = 0;

    pnodo = *pila; //lo hacemos apuntar al nodo que vamos a borrar
    *pila = (*pila)->siguiente; //avanzamos la raiz al segundo nodo 

    v = pnodo->valor; // guardamos el valor del nodo a borrar y lo retornamos

    free(pnodo); // eliminamos el nodo
    return v;
}

int tamano (nodo *pila)
{
    nodo *pivot = NULL;
    pivot = pila; // creamos un nodo auxiliar y le asignamos la direccion del primer nodo (para no perder los datos) 
    int cont = 0;
    while(pivot != NULL)
    {
        cont++;
        pivot = pivot->siguiente;
    }

    return cont;
}

item cima ()
{
    if(pila != NULL) return pila->valor;
    else return -1;

}

int vacia()
{
    if(pila == NULL) return 1;
    else return 0;
}

