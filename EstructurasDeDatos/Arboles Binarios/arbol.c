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
    inorder(raiz);



    return EXIT_SUCCESS;
}

void inserta(arbol **raiz,int x)
{
    if(*raiz == NULL) // si el arbol está vacio
    {
        *raiz = malloc (sizeof(arbol));

        (*raiz)->dato = x;
        (*raiz)->h_der = NULL;
        (*raiz)->h_izq = NULL;
    }
    else //si ya hay elementos en el arbol
    {
        if(x < (*raiz)->dato) inserta(&(*raiz)->h_izq,x);
        else inserta(&(*raiz)->h_der,x);
    }
}

int es_miembro (arbol *raiz,int x)
{
    if(raiz == NULL) return -1;

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
        return suprime_menor(&(*raiz)->h_izq);
    }
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
        else if((*raiz)->h_der == NULL && (*raiz)->h_der == NULL)
        {
            arbol *temp = *raiz;
            *raiz = NULL;
            free(temp);
        }
        else if((*raiz)->h_izq == NULL) // el hijo derecho contiene el valor a eliminar
        {
            arbol *temp = *raiz;
            *raiz = (*raiz)->h_der;
            free(temp);
        }
        else if ((*raiz)->h_der == NULL)
        {
            arbol *temp = *raiz;
            *raiz = (*raiz)->h_izq;
            free(temp);
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