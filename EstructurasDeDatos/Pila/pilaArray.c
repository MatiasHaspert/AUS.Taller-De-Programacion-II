#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *contenido; //asignacion dinamica
    int tamMax;
    int cima; //contador que indica la cima de la pila

}Pila;

void crearPila(Pila *,int );
int pilaVacia (Pila );
int pilaLlena (Pila );
void apila (Pila *, int);
int desapila (Pila *);
int cima (Pila );
void liberar (Pila *);

int main()
{
    int max;
    Pila pila;
    int n,i;

    printf("\nCuantos elementos desea ingresar: ");
    scanf("%d",&max);

    crearPila(&pila,max);

    for(i = 0; i < max; i++)
    {
        printf("\nIngrese el valor %d#: ",i+1);
        scanf("%d",&n);
        apila(&pila,n);
    }

    printf("\nElementos extraidos de la pila:\n");
    while(pilaVacia(pila) != 1)
    {
        printf("%d ", desapila(&pila));
    }

    liberar(&pila);

    return EXIT_SUCCESS;
}

void crearPila(Pila *pila,int max)
{
    int *elementos;

    if((elementos = malloc(sizeof(int)* max)) == NULL)
    {
        printf("Error al reservar memoria.\n");
        exit(1);
    }

    pila->contenido = elementos; //contenido apunta al inicio del array 
    pila->cima = -1; //inicializamos la pila
    pila->tamMax = max;
}

void apila (Pila *pila, int elementos)
{
    if(pilaLlena(*pila) == 1)
    {
        printf("Error, pila llena.\n");
        exit(1);
    }

    pila->cima++; //incrementamos la posicion de cima
    pila->contenido[pila->cima] = elementos; // donde apunta el array contenido guardamos el elemento en la cima
}

int desapila (Pila *pila)
{
    if(pilaVacia(*pila) == 1)
    {
        printf("Error, pila vacia.\n"); 
        exit(1);
    }

    int temp = pila->contenido[pila->cima]; // guardamos el elemento que esta en la cima
    pila->cima--;

    return temp;
}


int pilaVacia (Pila pila)
{
    if(pila.cima == -1) return 1;
    else return 0;
}

int pilaLlena (Pila pila)
{
    if(pila.cima == pila.tamMax-1) return 1;
    else return 0;
}

int cima (Pila pila)
{
    if(pilaVacia(pila) == 1)
    {
        printf("Error, pila vacia.\n"); 
        exit(1);
    }

    return pila.contenido[pila.cima];
}

int tam (Pila pila)
{
    return pila.cima+1;
}

void liberar (Pila *pila)
{
    free(pila->contenido);

    pila->contenido = NULL;
    pila->cima = -1;
    pila->tamMax = 0;
}

