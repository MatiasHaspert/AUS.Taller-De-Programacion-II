/*
Dada una cadena de caracteres, para cada caracter se debe encontrar el primer caracter no repetitivo
hasta ese momento.Si no existe, se debe mostrar un -1 en esa posicion.
*/
#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"

Nodo *inicio;
Nodo *final;

int main()
{
    int i;
    char letra,cad[100];
    int n = 'z'-'a'+1; //26
    int frecuencias[n]; //llevara la cantidad de apariciones de cada letra
    // en la cola almacenar los caracteres no repetidos hasta ese momento
    inicio = NULL; 
    final = NULL;

    printf("\nIngrese una palabra: ");
    scanf("%s",cad);

    for(i = 0; i < n; i++) frecuencias[i] = 0; //inicializamos el array frecuencias

    for(i = 0; cad[i] != '\0'; i++) printf("%c ",cad[i]); //mostramos la cadena original

    printf("\n");

    for(i = 0; cad[i] != '\0'; i++)
    {
        letra = cad[i];

        if(frecuencias[letra-'a'] == 0) //si la letra nunca aparecio la insertamos
        {
            enQueue(&inicio,&final,letra);
        }
        frecuencias[letra-'a']++; //en la posicion respectiva a la letra incrementamos su valor

        //buscamos el primer caracter no repetido
        while(!queueVacia(inicio))
        {
            if(frecuencias[frente(inicio) - 'a'] > 1) // si el caracter esta repetido lo sacamos
            {
                deQueue(&inicio,&final); 
            }
            else
            {   // se encontro
                printf("%c ",frente(inicio));
                break;
            }
        }

        if(queueVacia(inicio) == 1) //si no se encontro ningun caracter
        {
            printf("%d ",-1);
        }
    }

    printf("\n");

    liberarQueue(&inicio);

    return EXIT_SUCCESS;
}

Nodo* crearQueue(item x)
{
    Nodo *nuevo = malloc(sizeof(Nodo));

    nuevo->dato = x;
    nuevo->siguiente = NULL;
    
    return nuevo;  
}

int queueVacia (Nodo *inicio)
{
    if(inicio == NULL) return 1;
    else return 0;
}

void enQueue(Nodo **inicio, Nodo **final, item x)
{
    Nodo *nuevo = crearQueue(x);

    if(queueVacia(*inicio) == 1) //es decir la cola se encuentra vacia
    {
        *inicio = nuevo;
        *final = nuevo;
    }
    else
    {
        (*final)->siguiente = nuevo;
        *final = nuevo;
    }
}

item deQueue(Nodo **inicio, Nodo **final)
{
    if(queueVacia(*inicio) == 1)
    {
        printf("\nQueue vacia, no se pudo extrar un dato.\n");
        exit(EXIT_FAILURE);
    }

    Nodo *pivot;
    
    pivot = *inicio;
    item x = pivot->dato;

    *inicio = pivot->siguiente;
    
    free(pivot);
    return x;
}

item frente (Nodo *inicio)
{
    if(queueVacia(inicio) == 1)
    {
        printf("\nQueue vacia.\n");
        exit(EXIT_FAILURE);
    }

    return inicio->dato;
}

void liberarQueue (Nodo **inicio)
{
    Nodo *actual;
    while(!queueVacia(*inicio))
    {
        actual = *inicio;
        *inicio = actual->siguiente;
        free(actual);
    }
}