#include "kruskal.h"

int main()
{
    int M_costos[VERTICES][VERTICES]; //matriz con los pesos
    arista *cola = NULL;              //cola de prioridad
    int i,j;

    for(i = 0; i < VERTICES; i++)
    {
        for(j = i+1; j < VERTICES; j++) // diagonal superior
        {
            printf("\nIngrese el peso de la arista entre el vertice %d y %d: ",i,j);
            scanf("%d",&M_costos[i][j]);

            if(M_costos[i][j] != 0)
            {
                inserta(i,j,M_costos[i][j],&cola); //inserto en la cola de prioridad
            }
        }
    }

    kruskal(&cola);

    return EXIT_SUCCESS;
}


/*INSERTA*/
void inserta (vertice iu, vertice jv, int peso,arista **cola)
{
    arista *nueva = malloc(sizeof(arista));
    nueva->u = iu;
    nueva->v = jv;
    nueva->costo = peso;
    nueva->sig = NULL;

    if(*cola == NULL)
    {
        *cola = nueva;
        return;
    }

    nueva->sig = *cola;
    *cola = nueva;
}

/*SACAR EL PESO MINIMO DE LA COLA DE PRIORIDAD*/
arista * sacar_min(arista **cola)
{
    int min;
    arista *pivot;
    arista *menor_arista;
    if(*cola == NULL){ // si la cola esta vacia
        printf("No hay aristas disponibles\n");
        return NULL;
    }
    //inicializo
    menor_arista = *cola;
    min = menor_arista->costo;
    pivot = menor_arista;

    //encuentro la menor arista
    while(pivot != NULL)
    {
        if(pivot->costo < min)
        {
            menor_arista = pivot;
            min = menor_arista->costo;
        }
        pivot = pivot->sig;
    }

    if(*cola == menor_arista) // si la primer arista de la cola es la menor, apunto la cabeza de la cola al siguiente elemento
    { 
        *cola = menor_arista->sig;
        return menor_arista;
    }

    //encuentro la arista previa a la menor
    pivot = *cola;
    while(pivot->sig != menor_arista)
        pivot = pivot->sig;

    pivot->sig = pivot->sig->sig; //apunto a la arista previa con la siguiente de la siguiente
    return menor_arista;

}

/*LISTA*/
void lista(arista *cola)
{
    if(cola == NULL)
    {
        printf("\n");
        return;
    }
    printf("(%d-%d,%d)\n", cola->u, cola->v, cola->costo);
    lista(cola->sig);
}

/*INICIAL*/
void inicial (tipo_nombre x,conjunto_CE *ce)
{
    // nombre de un componente que pertenece al conjunto ce que inicialmente tiene al vertice tipo_elemento
    ce->nombres[x].nombre_conjunto = x;
    ce->nombres[x].siguiente_elemento = NIL; //no posee siguiente elemento
    ce->encabezamientos[x].cuenta = 1;
    ce->encabezamientos[x].primer_elemento = x; // el primer elemento de un componente conexo es el mismo
}

void combina (tipo_nombre a, tipo_nombre b, conjunto_CE *ce) // a y b son los conjuntos
{
    int i;

    if(ce->encabezamientos[a].cuenta >  ce->encabezamientos[b].cuenta) //si A es el conjunto mas grande, combinar B en A
    { 
        i = ce->encabezamientos[b].primer_elemento; // primer elemento del conjunto B

        while(ce->nombres[i].siguiente_elemento != NIL)
        {
            ce->nombres[i].nombre_conjunto = a; // nombre del conjunto que contiene a i pasa a ser a
            i = ce->nombres[i].siguiente_elemento;
        }
        // i ahora es igual al ultimo elemento del conjunto B (ahora unido con A)
        ce->nombres[i].nombre_conjunto = a;
        ce->nombres[i].siguiente_elemento = ce->encabezamientos[a].primer_elemento;
        ce->encabezamientos[a].primer_elemento = ce->encabezamientos[b].primer_elemento;
        ce->encabezamientos[a].cuenta += ce->encabezamientos[b].cuenta;

        ce->encabezamientos[b].cuenta = 0;

    }
    else
    {
        i = ce->encabezamientos[a].primer_elemento;

        while(ce->nombres[i].siguiente_elemento != NIL)
        {
            ce->nombres[i].nombre_conjunto = a; // nombre del conjunto que contiene a i pasa a ser a
            i = ce->nombres[i].siguiente_elemento;
        }

        // i ahora es igual al ultimo elemento del conjunto A (ahora unido con B)
        ce->nombres[i].nombre_conjunto = b;
        ce->nombres[i].siguiente_elemento = ce->encabezamientos[b].primer_elemento;
        ce->encabezamientos[b].primer_elemento = ce->encabezamientos[a].primer_elemento;
        ce->encabezamientos[b].cuenta += ce->encabezamientos[a].cuenta;

        ce->encabezamientos[a].cuenta = 0;
    }
}

tipo_nombre encuentra(vertice v, conjunto_CE *ce)
{
    return ce->nombres[v].nombre_conjunto;
}

void kruskal (arista **cola)
{
    int numeros_componentes = VERTICES;
    int i;
    arista *arbol = NULL;
    arista *aristaMenor;
    conjunto_CE combinaYencuentra;
    vertice v1, v2;
    tipo_nombre componenteX, componenteY;

    if(*cola == NULL)
    {
        printf("No hay aristas disponibles\n");
        return;
    }

    for(i = 0; i < VERTICES; i++)
    {
        inicial(i,&combinaYencuentra); //inicializo el conjuntos combina-encuentra
    }

    while(numeros_componentes > 1)
    {
        aristaMenor = sacar_min(cola);
        v1 = aristaMenor->u; // vertice de cada arista
        v2 = aristaMenor->v;
        componenteX = encuentra(v1, &combinaYencuentra);
        componenteY = encuentra(v2, &combinaYencuentra);

        if (componenteX != componenteY)
        {                                        // si las componentes son disconexas, entonces
            combina(v1, v2, &combinaYencuentra); // combino las componentes
            aristaMenor->sig = arbol;           // agrego la arista al arbol abarcador de menor costo
            arbol = aristaMenor;
            numeros_componentes--; // una componente seguro fue combinada con otra si la arista juntaba dos componentes disconexas, por eso tengo una menos
        }
        else
        {
            if (aristaMenor) free(aristaMenor); // descarto la arista si estuvo en un primer momento
        }
    }

    lista(arbol);  
}


