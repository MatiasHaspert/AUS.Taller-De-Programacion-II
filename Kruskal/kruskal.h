#include <stdio.h>
#include <stdlib.h>

typedef int vertice;
typedef int tipo_nombre;

#define VERTICES 5
#define NIL 0

typedef struct _ARISTA 
{
    vertice u;
    vertice v;
    int costo;
    struct _ARISTA *sig;
}arista;

/*
    ENCABEZADO es el inicio del conjunto
    cuenta es la cantidad de vertices que "absorbio" un conjunto
    primer_elemento de los conjuntos se pondran en 0 cuando el conjunto sea "absorbido"
*/

typedef struct _ENCABEZADO{
    int cuenta;
    int primer_elemento;
}encabezado;

/*
    NOMBRE es el nombre del conjunto al que pertenece el vertice
    nombre_conjunto es el nombre del conjunto al que pertenece el vertice
    siguiente_elemento es el siguiente elemento del conjunto
*/
typedef struct _NOMBRE{
    tipo_nombre nombre_conjunto; // Si ambos vertices de un lado pertenecen al mismo conjunto, no tomo en cuenta el lado
    int siguiente_elemento;
}nombre;

/*
    Si se recibe un lado (x-y,w) con w siendo el peso del mismo.
    Para nombre x: El nombre_conjunto de x seguira intacto. El siguiente_elemento de x sera y
    Para nombre y: El nombre_conjunto de y sera el de x. El siguiente_elemento de y seguira intacto. 
*/

/*
    CONJUNTO_CE es el conjunto combina-encuentra, las operaciones son en este conjunto
    nombres es el nombre de cada conjunto al que pertenece el vertice, [v]
    encabezamientos es un array con los miembros del conjunto combina-encuentra
*/

typedef struct _CONJUNTO_CE{
    nombre nombres[VERTICES];
    encabezado encabezamientos[VERTICES];
}conjunto_CE;

/*
* Funciones
* combina: combina los conjuntos
* encuentra: encuentra el conjunto al que pertenece el vertice
* inicial: inicializa el conjunto combina-encuentra
* inserta: inserta un lado en la cola de prioridad
* kruskal: algoritmo de kruskal
* lista: imprime la cola de prioridad
* sacar_min: saca el lado de menor peso de la cola de prioridad
*/

void inicial(tipo_nombre, conjunto_CE*);
void combina(tipo_nombre,tipo_nombre,conjunto_CE*);
tipo_nombre encuentra(vertice,conjunto_CE*);
void kruskal(arista**);

void inserta(vertice,vertice,int,arista**);
arista *sacar_min(arista**);
void lista(arista*);