#include "Kruskal.h"

int main()
{
    int M_Costos[VERTICES][VERTICES]; //matriz con los pesos
    rama *arbol = NULL; //cola de prioridad
    for (int i = 0; i < VERTICES; i++)
    {
        for (int j = i+1; j < VERTICES; j++)
        {
            printf("Ingrese costo de lado entre vertices %d y %d: ",i, j);
            scanf("%d", &M_Costos[i][j]);

            if(M_Costos[i][j] != 0)
            {
                inserta(i, j, M_Costos[i][j], &arbol); //inserto en la cola de prioridad
            }
        }
    }
    printf("\n");
    lista(arbol);
    printf("\n");
    kruskal(arbol);
    
    return EXIT_SUCCESS;
}

// INSERTO ARISTA EN LA COLA DE PRIORIDAD
void inserta(int a, int b, int costo, rama **arbol)
{
    rama *nueva = malloc(sizeof(rama));
    nueva->a.costo = costo;
    nueva->a.u = a;
    nueva->a.v = b;
    nueva->sig = NULL;
    if(*arbol == NULL)
    {
        nueva->sig = *arbol;
        *arbol = nueva;
    }
    else
    {
        if((*arbol)->a.costo >= costo) //cuando se inserta al inicio
        {
            nueva->sig = *arbol;
            *arbol = nueva;
        }
        else if((*arbol)->a.costo < costo && (*arbol)->sig != NULL && (*arbol)->sig->a.costo >= costo) //esta entre dos
        {
            nueva->sig = (*arbol)->sig;
            (*arbol)->sig = nueva;
        }
        else
        {
            inserta(a, b, costo, &((*arbol)->sig));
        }
    }
}

// OBTENGO LA ARISTA DE MENOR PESO
arista *sacar_min(rama **arbol)
{
    if(*arbol == NULL) // si la cola esta vacia
    {
        return NULL;
    }
    else
    {   // la arista de menor peso siempre va a ser el primer elemento de la cola de prioridad
        rama *temp = *arbol;
        arista *arista_min = &(temp->a);
        *arbol = (*arbol)->sig;
        return arista_min;
    }
}

//LISTAR
void lista(rama *arbol)
{
    if(arbol == NULL)
    {
        printf("\n");
        return;
    }
    printf("(%d-%d,%d)\n", arbol->a.u, arbol->a.v, arbol->a.costo);
    lista(arbol->sig);
}

//INICIAL
void inicial(tipo_nombre a, tipo_elemento x, conjunto_CE *ce)
{
    // nombre de un componente que pertenece al conjunto ce que inicialmente tiene al vertice tipo_elemento
    ce->nombres[x].nombre_conjunto = a;
    ce->nombres[x].siguiente_elemento = 0; //puntero nulo al siguiente elemento
    ce->encabezamientos_conjunto[a].cuenta = 1;
    ce->encabezamientos_conjunto[a].primer_elemento = x;   
}

//COMBINA LOS CONJUNTOS A Y B
void combina(tipo_nombre a, tipo_nombre b, conjunto_CE *ce)
{
    int i;

    if(ce->encabezamientos_conjunto[a].cuenta > ce->encabezamientos_conjunto[b].cuenta)
    {//A es el conjunto mas grande , combina B dentro de A, encuentra el final de B, cambiando los nombres de los conjuntos por A conforme se avanza 1
        i = ce->encabezamientos_conjunto[b].primer_elemento; //primer elemento del conjunto b

        while(ce->nombres[i].siguiente_elemento != 0)
        {
            ce->nombres[i].nombre_conjunto = a;
            i = ce->nombres[i].siguiente_elemento;
        }
        //agrega a la lista A al final de la B y llama A al resultado
        //ahora i es el ındice del ultimo elemento de B 

        ce->nombres[i].nombre_conjunto = a;
        ce->nombres[i].siguiente_elemento = ce->encabezamientos_conjunto[a].primer_elemento;
        ce->encabezamientos_conjunto[a].primer_elemento = ce->encabezamientos_conjunto[b].primer_elemento;
        ce->encabezamientos_conjunto[a].cuenta += ce->encabezamientos_conjunto[b].cuenta;

    }
    else
    {//B es al menos tan grande como A, combina A dentro de B, encuentra el final de A, cambiando los nombres de los conjuntos por B conforme se avanza 1
        i = ce->encabezamientos_conjunto[a].primer_elemento; //primer elemento del conjunto a

        while(ce->nombres[i].siguiente_elemento != 0)
        {
            ce->nombres[i].nombre_conjunto = a;
            i = ce->nombres[i].siguiente_elemento;
        }
        //agrega a la lista B al final de la A y llama B al resultado
        //ahora i es el ındice del ultimo elemento de A 

        ce->nombres[i].nombre_conjunto = b;
        ce->nombres[i].siguiente_elemento = ce->encabezamientos_conjunto[b].primer_elemento;
        ce->encabezamientos_conjunto[b].primer_elemento = ce->encabezamientos_conjunto[a].primer_elemento;
        ce->encabezamientos_conjunto[b].cuenta += ce->encabezamientos_conjunto[a].cuenta;

    }
}

//ENCUENTRA
tipo_nombre encuentra(int x, conjunto_CE *ce)
{//devuelve el nombre de aquel conjunto que tiene a x como miembro
    return ce->nombres[x].nombre_conjunto;
}

void kruskal(rama *arbol)
{
    rama *arbol_minimo = NULL;
    arista *arista_menor;
    int comp_n = VERTICES;
    conjunto_CE combinaYencuentra;
    vertice u, v;
    tipo_nombre comp_u, comp_v; //nombre de los componentes
    int i;

    if(arbol == NULL)
    {
        printf("\nNo hay aristas disponibles");
        return;
    }

    for (i = 0; i < VERTICES; i++)
    {
        inicial(i, i, &combinaYencuentra); //inicializo el conjunto combina y encuentra
    }

    while(comp_n > 1) //considera la siguiente arista
    {
        arista_menor = sacar_min(&arbol);
        u = arista_menor->u; //vertice de cada arista
        v = arista_menor->v;

        comp_u = encuentra(u, &combinaYencuentra);
        comp_v = encuentra(v, &combinaYencuentra);
        
        if(comp_u != comp_v) //si las componentes son disconexas
        {
            combina(comp_u, comp_v, &combinaYencuentra); //combino las componentes
            comp_n--; // tengo una menos porque una componente se combino con otra
            inserta(arista_menor->u, arista_menor->v, arista_menor->costo, &arbol_minimo); //agrego la arista al arbol abarcador de menor costo
            free(arista_menor);
        }
        else //se descarta la arista si conecta dos vertices contenidos en el mismo componente
        {
            if(arista_menor)
                free(arista_menor);
        }
    }

    lista(arbol_minimo);
    free_arbol(arbol_minimo);
}

void free_arbol(rama *arbol)
{
    rama *pivot;
    while(arbol != NULL)
    {
        pivot = arbol;
        arbol = pivot->sig;
        free(pivot);
    }
}
