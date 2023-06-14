#include <stdio.h>
#include <stdlib.h>

typedef int item;

typedef struct 
{
    item *array;    // asignacion dinamica del array Circular
    int inicio; // inicio de la cola
    int nroElementos; // cantidad de elementos en la cola
    int tamMax;
}Queue;

//EL FINAL DE LA COLA ES: final = (inicio + nroElementos)% tamMax

void crearQueue (Queue *, int );
int queueLlena(Queue);
int queueVacia(Queue);
void enQueue (Queue *,item );
item deQueue (Queue *);
int tamano (Queue );
item frente(Queue );
void liberarQueue (Queue *);

int main()
{
    Queue cola;
    int i,N;
    int nro;

    printf("\nTeclea la cantidad de numeros que desee ingresar: ");
    scanf("%d",&N);

    crearQueue(&cola,N);
    
    printf("\nIngrese los numeros al array:\n");

    for ( i = 0; i < N; i++)
    {
        printf("%d#: ",i+1);
        scanf("%d",&nro);
        enQueue(&cola,nro);
    }

    enQueue(&cola,6);
    
    printf("\nQueue:\n");

    while(!queueVacia(cola)) printf("%d ",deQueue(&cola));
    
    
    liberarQueue(&cola);

    return EXIT_SUCCESS;
}

void crearQueue (Queue *cola, int tam)
{
    item *array;

    if((array = malloc(sizeof(item) * tam)) == NULL)
    {
        printf("\nNo se pudo reservar memoria.\n");
        exit(EXIT_FAILURE);
    }

    cola->array = array;
    cola->inicio = 0; //inicializacion del inicio de la cola
    cola->nroElementos = 0; //cola vacia
    cola->tamMax = tam;
}

int queueLlena(Queue cola)
{
    if(cola.nroElementos == cola.tamMax) return 1; //verdadero
    else return 0;
}

int queueVacia(Queue cola)
{
    if(cola.nroElementos == 0) return 1; //verdadero
    else return 0;
}

void enQueue (Queue *cola,item x)
{
    if(queueLlena(*cola) == 1)
    {
        printf("\nQueue llena.\n");
        exit(EXIT_FAILURE);
    }
    
    int final = (cola->inicio+cola->nroElementos) % cola->tamMax;
    cola->array[final] = x;
    cola->nroElementos++;
}

item deQueue (Queue *cola)
{
    if(queueVacia(*cola) == 1)
    {
        printf("\nQueue vacia.\n");
        exit(EXIT_FAILURE);
    }
    
    item temp = cola->array[cola->inicio];
    cola->inicio = (cola->inicio+1)% cola->tamMax;
    cola->nroElementos--;

    return temp;
}

int tamano (Queue cola)
{
    return cola.nroElementos;
}

item frente(Queue cola)
{
    if(queueVacia(cola) == 1)
    {
        printf("\nQueue vacia.\n");
        exit(EXIT_FAILURE);        
    }
    else return cola.array[cola.inicio];
}

void liberarQueue (Queue *cola)
{
    free(cola->array);

    cola->array = NULL;
    cola->inicio = 0;
    cola->tamMax = 0;
}