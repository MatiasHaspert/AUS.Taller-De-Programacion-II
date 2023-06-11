typedef char item;

typedef struct nodo{
    item valor; //valor con el que vamos a trabajar
    struct nodo *siguiente; 
}nodo;


/*FUNCIONES PILA*/
void push (nodo**, item);
item pop (nodo**);
void cargar();
void listar();
int tamano(nodo *);
item cima ();
int vacia();