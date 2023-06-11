typedef struct
{
    int nro;

}item;

typedef struct elemento
{
    item valor;
    struct elemento *siguiente;

}Nodo;

/*PROTOTIPOS DE LAS FUNCIONES SOBRE LISTAS*/
Nodo* CrearNodo(item);
void inserInic (Nodo **, item);
void imprimirLista (Nodo *);
Nodo * busqueda(Nodo *, item);
void inserFinal (Nodo **, item);
void insertar (Nodo **, Nodo *, item);
void eliminarNodo (Nodo **,item);
void liberarLista (Nodo **);
