#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"
#include <string.h>

legislador *chicos_buenos;
legislador *chicos_malos;

int main()
{
    chicos_buenos = NULL;
    chicos_malos = NULL;

    char voto = ' ',opc;
    char nombre[MAXCT];
    int cantidad = 1;

    printf("\nBienvenidos al programa de votos de la Sociedad para la Prevención de Injusticias con el Atún (SPIA).\n");

    while(opc != 'N')
    {
        printf("\nVotación %d#:\n",cantidad);

        voto = ' ';
        while(voto != 'E')
        {
            printf("\nTeclea 'F'(voto favorable), 'D'(voto desfavorable), 'E'(para terminar la votación): ");
            scanf(" %c",&voto);

            if(voto == 'F' || voto == 'D')
            {
                printf("\nIngrese el nombre del legislador que votó: ");
                scanf(" %s",nombre);

                if(voto == 'F' && (!miembro(&chicos_buenos,nombre)))
                {
                    suprime(&chicos_malos,nombre);
                    inserta(&chicos_buenos,nombre);
                }
                else if (voto == 'D' && (!miembro(&chicos_malos,nombre)))
                {
                    suprime(&chicos_buenos,nombre);
                    inserta(&chicos_malos,nombre);
                }
            }
        }
        printf("\nLegisladores que votaron a favor:\n");
        mostrar(chicos_buenos);
        printf("Legisladores que votaron en contra:\n");
        mostrar(chicos_malos);
        cantidad++;
        
        printf("\n¿Desea ingresar votos?\n");
        printf("(S|N)> ");
        scanf(" %c",&opc);

    }

    liberarLista(&chicos_buenos);
    liberarLista(&chicos_malos);

    return EXIT_SUCCESS;
}

void inserta(legislador **cabeza, char nombre[])
{
    //si la cabeza apunta null(lista vacia) insertamos al inicio
    if(*cabeza == NULL) inserInic(cabeza,nombre);
    else
    {    
        legislador *actual = *cabeza;
        legislador *anterior = NULL;
        //Buscamos en donde insertar (un lugar antes que el primer elemento mayor que encontremos)
        while(actual != NULL && strcmp(actual->nombre,nombre) < 0)
        {
            anterior = actual;
            actual = actual->siguiente;
        }

        insertarDato(cabeza,anterior,nombre);
    }

}

void insertarDato (legislador **cabeza, legislador *anterior, char nombre[])
{
    //si el valor del nodo anterior no se encuentra en la lista, el nuevo valor lo insertamos al inicio
    if(anterior == NULL || *cabeza == NULL) // si la cabeza apunta a null quiere decir que la lista esta vacia
    {
        inserInic(cabeza,nombre); //lo insertamos al inicio
    }
    else
    {
        legislador *nuevo = CrearNodo(nombre);
        nuevo->siguiente = anterior->siguiente;
        anterior->siguiente = nuevo;
    }
}

void inserInic (legislador **cabeza, char nombre[])
{
    legislador *nuevo;
    nuevo = CrearNodo(nombre);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

legislador *CrearNodo (char x[])
{
    legislador *a;

    if((a = malloc (sizeof(legislador))) == NULL)
    {
        printf("No se pudo reservar memoria para un nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(a->nombre,x);
    a->siguiente = NULL;

    return a; 
}

void mostrar (legislador *cabeza)
{
    legislador *actual;
    for(actual = cabeza; actual!= NULL; actual = actual->siguiente)
    {
        printf("%s\n",actual->nombre);
    }

    printf("\n");
}

void suprime (legislador **cabeza,char x[])
{
    legislador *actual = *cabeza; //en actual está el valor a eliminar y lo inicialzamos en la cabeza de la lista
    legislador *anterior = NULL;

    //buscamos el dato que queremos eliminar
    while (actual != NULL && strcmp(actual->nombre,x) != 0)
    {   
        anterior = actual;
        actual = actual->siguiente;
    }

    if(actual == NULL) // significa que no se encontro el elemento(o la lista esta vacia)
    {
        if(*cabeza == NULL) printf("\n");
        else printf("\n");
    }
    else
    {
        if(actual == *cabeza) //si lo que apunta actual es igual a lo que apunta la cabeza, es decir, el primer nodo de la lista, lo eliminamos
        {
            *cabeza = actual->siguiente;
            free(actual);
        }
        else
        {
            anterior->siguiente = actual->siguiente; 
            free(actual); 
        }
    }
}

int miembro (legislador **cabeza, char x[])
{
    legislador *actual;

    for(actual = *cabeza; actual!= NULL; actual = actual->siguiente)
    {
        if(strcmp(actual->nombre,x) == 0) return TRUE;   
    }

    return FALSE;
       
}

void liberarLista (legislador **cabeza)
{
    legislador *primero;//eliminamos el primer nodo de la lista

    while(*cabeza != NULL)
    {
        primero = *cabeza;
        *cabeza = primero->siguiente;

        free(primero);
    }
}

