typedef int item;

typedef struct nodo
{
    item dato;
    struct nodo *siguiente;
}Nodo;

Nodo* crearQueue(item);
/*Poner un dato al final de la cola*/
void enQueue(Nodo **, Nodo **, item);
/*Sacar un dato del inicio de la cola*/
item deQueue(Nodo **, Nodo **);
void liberarQueue (Nodo **);
int tamano (Nodo *);
int queueVacia (Nodo *);
item frente (Nodo *);