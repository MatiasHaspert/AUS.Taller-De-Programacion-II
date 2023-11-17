#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

arbol *raiz;

int main()
{
    raiz = NULL;

    int i,nro,N;

    printf("\nTeclea la cantidad de numero que deseas ingresar: ");
    scanf("%d",&N);

    for ( i = 0; i < N; i++)
    {
        printf("%d#> ",i+1);
        scanf("%d",&nro);

        inserta(&raiz,nro);
    }

    print_arbol(raiz,0);
    printf("\nRecorrido inorder:\n");
    inorder(raiz);
    printf("\nRecorrido postrder:\n");
    postorder(raiz);
    printf("\nRecorrido preorder:\n");
    preorder(raiz);

    printf("\nIngresa un numero y te diré si se encuentra en el arbol: ");
    scanf("%d",&nro);


    if(es_miembro(raiz,nro) == 1) printf("El elemento %d se encuentra en el arbol!\n",nro);
    else printf("El elemento %d no se encuentra en el arbol!\n",nro);

    printf("\nIngresa un numero que desees eliminar del arbol: ");
    scanf("%d",&nro);

    suprime(&raiz,nro);

    print_arbol(raiz,0);

    printf("\nIngresa un numero que desees eliminar del arbol: ");
    scanf("%d",&nro);

    suprime(&raiz,nro);

    print_arbol(raiz,0);

    return EXIT_SUCCESS;
}

arbol * nuevonodo(int valor)
{
    arbol *nuevo = malloc(sizeof(arbol));
    if(nuevo == NULL)
        return NULL;
    
    nuevo->dato = valor;
    nuevo->h_der = NULL;
    nuevo->h_izq = NULL;

    return nuevo;
}


void inserta(arbol **raiz,int x)
{
    if(*raiz == NULL)
    {
        *raiz = nuevonodo(x);
    }
    else 
    {    
        if(x < (*raiz)->dato)
        {
            inserta(&(*raiz)->h_izq, x);
        }
        else// x > (*raiz)->dato
        {
            inserta(&(*raiz)->h_der, x);
        }
    }
}

int es_miembro (arbol *raiz,int x)
{
    if(raiz == NULL) 
        return 0;

    if(raiz->dato == x)
    {
        return 1;
    }
    else
    {
        if(raiz->dato > x) return es_miembro(raiz->h_izq,x);
        else return es_miembro(raiz->h_der,x);
    }
}

int suprime_menor(arbol **raiz)
{
    int valor_ref;
    if((*raiz)->h_izq == NULL) //se alcanzo el nodo mas pequeño del arbol
    {
        valor_ref = (*raiz)->dato;
        arbol *temp = *raiz;
        *raiz = (*raiz)->h_der;
        free(temp);
        return valor_ref;
    }
    else //aun no se alcanzo el nodo mas pequeño
    {
        valor_ref = suprime_menor(&(*raiz)->h_izq);
    }

    return valor_ref;
    
}

void suprime (arbol **raiz,int x)
{
    if(*raiz != NULL)
    {
        if(x < (*raiz)->dato)
        {
            suprime(&(*raiz)->h_izq,x);
        }
        else if (x > (*raiz)->dato)
        {
            suprime(&(*raiz)->h_der,x);
        }
        else if((*raiz)->h_izq == NULL && (*raiz)->h_der == NULL)
        {
            arbol *temp = *raiz;
            *raiz = NULL;
            free(temp);
        }
        else if((*raiz)->h_izq == NULL) // el hijo derecho contiene el valor a eliminar
        {
            *raiz = (*raiz)->h_der;
        }
        else if ((*raiz)->h_der == NULL)
        {
            *raiz = (*raiz)->h_izq;  
        }
        else //ambos hijos estas presentes
        {
            (*raiz)->dato = suprime_menor(&(*raiz)->h_der);
        }
    }       
}

// Función para mostrar el árbol en orden (izquierda - raíz - derecha)
void inorder(arbol *raiz) 
{
    if (raiz != NULL) {
        inorder(raiz->h_izq);
        printf("%d ", raiz->dato);
        inorder(raiz->h_der);
    }
}

// Función para mostrar el árbol en orden (raiz - izq - derecha)
void preorder(arbol *raiz)
{
    if(raiz != NULL)
    {
        printf("%d ",raiz->dato);
        preorder(raiz->h_izq);
        preorder(raiz->h_der);
    }
}
// Función para mostrar el árbol en orden (izquierda - derecha - raiz)
void postorder(arbol *raiz)
{
    if(raiz != NULL)
    {
        postorder(raiz->h_izq);
        postorder(raiz->h_der);
        printf("%d ",raiz->dato);
    }
}

// Función para imprimir un árbol binario
void print_arbol(arbol* raiz, int nivel) 
{
    if (raiz == NULL) 
    {
        return;
    }

    // Incrementar el nivel para obtener un formato visual
    nivel += 5;

    // Imprimir el nodo derecho
    print_arbol(raiz->h_der, nivel);

    // Imprimir el nodo actual
    printf("\n");
    for (int i = 5; i < nivel; i++) {
        printf(" ");
    }
    printf("%d\n", raiz->dato);

    // Imprimir el nodo izquierdo
    print_arbol(raiz->h_izq, nivel);
}

