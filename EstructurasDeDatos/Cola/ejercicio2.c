/*
Desarrollar un programa para la simulación de un cajero automático.
Se cuenta con la siguiente información:
- Llegan clientes a la puerta del cajero cada 2 ó 3 minutos.
- Cada cliente tarda entre 2 y 4 minutos para ser atendido.

Obtener la siguiente información:
1 - Cantidad de clientes que se atienden en 10 horas.
2 - Cantidad de clientes que hay en cola después de 10 horas.
3 - Hora de llegada del primer cliente que no es atendido luego
de 10 horas (es decir la persona que está primera en la cola cuando se cumplen 10 horas)

El dato que ingresemos a la cola va a ser un entero pq es el minuto donde a llegado la persona
*/
#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"
#include <time.h>

Nodo *inicio;
Nodo *final;

int main()
{
    inicio = NULL;
    final  = NULL;
    
    int estado = 0; // estado del cajero 0=desocupado
    int salida = -1;
    int llegada = 2 + rand() %2; //llegada de clientes cada 2 o 3 minutos(el resto de dividirlo por dos siempre da 1 o 0)
    int cantAtendidas = 0;
    int minuto;

    srand(time(NULL));

    for(minuto = 0; minuto < 600; minuto++)
    {
        if(llegada == minuto) //llega un cliente al cajero
        {
            if(estado == 0)
            {
                estado = 1; //ocupamos el cajero

                salida = minuto + 2 + rand()%3; //el cliente sale cada 2 o 4 minutos
            }
            else //si el cajero esta ocupado
            {
                enQueue(&inicio,&final,minuto);
            }

            llegada = minuto + 2 + rand() %2; //actualizamos para la llegada de otro cliente
        }
        if(salida == minuto) //cliente sale del cajero
        {
            estado = 0;
            cantAtendidas++;
            if(!queueVacia(inicio))
            {
                deQueue(&inicio,&final);
                estado = 1;
                salida = minuto + 2 + rand()%3;
            }
        }       
    }

    printf("\nClientes atendidios: %d.\n",cantAtendidas);
    printf("\nEn cola: %d.\n",tamano(inicio)); 
    printf("\nMinuto de llegada: %d.\n",frente(inicio));
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

int tamano (Nodo *inicio)
{   
    Nodo *actual;
    int cant = 0;

    for(actual = inicio; actual != NULL; actual = actual->siguiente)
    {
        cant++;
    }

    return cant;
}