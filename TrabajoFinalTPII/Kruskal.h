#include <stdio.h>
#include <stdlib.h>

typedef int tipo_nombre;
typedef int tipo_elemento;
typedef int vertice;

#define VERTICES 5

typedef struct _ARISTA
{ 
    vertice u;
    vertice v;
    int costo;
}arista;

typedef struct _RAMA 
{
    struct _ARISTA a;
    struct _RAMA *sig;
}rama;

typedef struct _ENCABEZADO 
{
    int cuenta; 
    int primer_elemento;
}encabezado;

typedef struct _NOMBRE
{
    tipo_nombre nombre_conjunto;
    int siguiente_elemento;
}nombre;

typedef struct _CONJUNTO_CE 
{
    nombre nombres[VERTICES];
    encabezado encabezamientos_conjunto[VERTICES];
}conjunto_CE;

/*
Funciones
combina: combina los conjuntos
encuentra: encuentra el conjunto al que pertenece el vertice
inicial: inicializa el conjunto combina-encuentra
inserta: inserta una arista en la cola de prioridad
kruskal: algoritmo de kruskal
lista: imprime la cola de prioridad
sacar_min: saca la arista de menor peso de la cola de prioridad
free_arbol: elimina la cola de prioridad
*/

void inicial(tipo_nombre, tipo_elemento, conjunto_CE *);
void combina(tipo_nombre, tipo_nombre, conjunto_CE *);
tipo_nombre encuentra(int, conjunto_CE *);
void kruskal(rama *);

void inserta(int, int, int, rama **);
arista *sacar_min(rama **);
void lista (rama *);
void free_arbol(rama *);