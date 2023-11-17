#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    char cadena[50];
    struct nodo *h_izq, *h_der;
}arbol;

arbol *raiz;

arbol *crearNodo(char []);
void insertar(arbol **, char []);
char *eliminar_menor(arbol **);
void eliminar(arbol **, char []);
int es_miembro(arbol *, char []);
void print_arbol(arbol *, int);

int main()
{
    char cadena[50];
    int i, n;

    printf("Teclee la cantidad de cadenas que desee ingresar: ");
    scanf("%d",&n);

    for ( i = 0; i < n; i++)
    {
        printf("\n%d#: ",i+1);
        scanf("%s", cadena);

        insertar(&raiz,cadena);
    }
    
    print_arbol(raiz,0);

    printf("Ingrese una cadena y te dire si se encuentra en el arbol: ");
    scanf("%s",cadena);
    if(es_miembro(raiz,cadena) == 1)
    {
        printf("\n%s se encuentra en el arbol.\n",cadena);
    }
    else
    {
        printf("\n%s no se encuentra en el arbol.\n",cadena);
    }

    printf("Ingrese una cadena a eliminar: ");
    scanf("%s",cadena);
    eliminar(&raiz,cadena);

    print_arbol(raiz,0);


    return EXIT_SUCCESS;
}

arbol *crearNodo(char cadena[])
{
    arbol *nuevo = malloc(sizeof(arbol));
    
    if(nuevo == NULL)
    {
        printf("\nError al crear un nuevo nodo.\n");
        return NULL;
    }

    strcpy(nuevo->cadena, cadena);
    nuevo->h_der = NULL;
    nuevo->h_izq = NULL;

    return nuevo;

}

void insertar(arbol **raiz, char cadena[])
{
    if(*raiz == NULL)
    {
        *raiz = crearNodo(cadena);
    }
    else 
    {    
        if(strcmp(cadena,(*raiz)->cadena) < 0)
        {
            insertar(&(*raiz)->h_izq, cadena);
        }
        else
        {
            insertar(&(*raiz)->h_der, cadena);
        }
    }
}

int es_miembro(arbol *raiz, char cadena[])
{
    if(raiz == NULL)
    {
        return 0;
    }

    if(strcmp(cadena, raiz->cadena) == 0)
    {
        return 1;
    }
    else
    {
        if(strcmp(cadena, raiz->cadena) < 0)
            return es_miembro(raiz->h_izq, cadena);
        else
            return es_miembro(raiz->h_der, cadena);
    }
}

char *eliminar_menor(arbol **raiz)
{
    char *cadena_ref = malloc(sizeof(char) * 50);
    if((*raiz)->h_izq == NULL) //se encontro el valor mas pequeño
    {
        strcpy(cadena_ref,(*raiz)->cadena);
        arbol *temp = *raiz;
        *raiz = (*raiz)->h_der;
        free(temp);
    }
    else
    {
        strcpy(cadena_ref, eliminar_menor(&(*raiz)->h_izq));
    }

    return cadena_ref;
}
void eliminar(arbol **raiz, char cadena[])
{
    if(*raiz != NULL)
    {
        if(strcmp(cadena, (*raiz)->cadena) < 0)
        {
            eliminar(&(*raiz)->h_izq, cadena);
        }
        else if(strcmp(cadena, (*raiz)->cadena) > 0)
        {
            eliminar(&(*raiz)->h_der, cadena);
        }//encontre la string a eliminar
        else if((*raiz)->h_izq == NULL && (*raiz)->h_der == NULL)
        {
            arbol *temp = *raiz;
            *raiz = NULL;
            free(temp);
        }
        else if((*raiz)->h_izq == NULL)
        {
            *raiz = (*raiz)->h_der;
        }
        else if((*raiz)->h_der == NULL)
        {
            *raiz = (*raiz)->h_izq;
        }
        else    // ambos hijos presentes
        {
            strcpy((*raiz)->cadena, eliminar_menor(&(*raiz)->h_der));
        }

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
    printf("%s\n", raiz->cadena);

    // Imprimir el nodo izquierdo
    print_arbol(raiz->h_izq, nivel);
}