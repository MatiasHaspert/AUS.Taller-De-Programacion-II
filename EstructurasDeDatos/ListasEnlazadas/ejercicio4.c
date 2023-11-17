/*
implementar una lista ordenada respecto al campo usuario;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    char usuario[41];
    struct nodo *siguiente;

}Nodo;

Nodo *inicio;

void insertar(Nodo **, char []);
void eliminar(Nodo **, char []);
void print_lista(Nodo *);
void liberar_lista(Nodo **);

int main()
{
    char usuario[41];

    int opc = 1;
    do
    {
        printf("\n1- Ingresar usuario a la lista.\n");
        printf("2- Eliminar un nombre de la lista.\n");
        printf("3- Mostrar lista.\n");
        printf("4- Liberar lista.\n");
        printf("5- Salir del programa.\n");
        printf("> ");
        scanf("%d",&opc);
        switch (opc)
        {
        case 1:
            getc(stdin);
            printf("> ");
            fgets(usuario,41,stdin);
            insertar(&inicio,usuario);
            break;
        case 2:
            printf("> ");
            fgets(usuario,41,stdin);
            eliminar(&inicio,usuario);
            getc(stdin);
            break;
        case 3:
            print_lista(inicio);
            break;
        case 4:
            liberar_lista(&inicio);
            break;
        default:
            break;
        }
        
    }while(opc != 5);
    


    return EXIT_SUCCESS;
}

void insertar(Nodo **inicio, char usuario[])
{
    Nodo *nuevo = malloc(sizeof(Nodo));
    strcpy(nuevo->usuario,usuario);

    if(*inicio == NULL)
    {
        nuevo->siguiente = *inicio;
        *inicio = nuevo;
    }
    else
    {
        if(strcmp((*inicio)->usuario, usuario) > 0) 
        {
            nuevo->siguiente = *inicio;
            *inicio = nuevo;
        }
        else if(strcmp((*inicio)->usuario, usuario) < 0 && (*inicio)->siguiente !=  NULL && strcmp((*inicio)->siguiente->usuario, usuario) > 0)
        {
            nuevo->siguiente = (*inicio)->siguiente;
            (*inicio)->siguiente = nuevo;
        }
        else if(strcmp((*inicio)->usuario, usuario) == 0)
        {
            printf("Ya existe el usuario.\n");
        }
        else
        {
            insertar(&(*inicio)->siguiente, usuario);
        }
    }
}

void eliminar(Nodo **inicio, char usuario[])
{
    Nodo *aux;

    if(*inicio == NULL)
    {
        printf("No existen usuarios a eliminar.\n");
    }
    else
    {
        if(strcmp((*inicio)->usuario, usuario) == 0)
        {
            aux = *inicio;
            *inicio = aux->siguiente;
            free(aux);
        }
        else if(strcmp((*inicio)->usuario, usuario) < 0 && (*inicio)->siguiente !=  NULL && strcmp((*inicio)->siguiente->usuario, usuario) == 0)
        {
            aux = (*inicio)->siguiente;
            (*inicio)->siguiente = (*inicio)->siguiente->siguiente;
            free(aux);
        }
        else
        {
            eliminar(&(*inicio)->siguiente, usuario);
        }
    }
}
void print_lista(Nodo *inicio)
{
    Nodo *aux = inicio;
    printf("\nLista de usuarios: \n");
    
    if(inicio == NULL)
        printf("\nNo existen elementos a mostrar.\n");
    while(aux != NULL)
    {
        fputs(aux->usuario,stdout);
        aux = aux->siguiente;
    }
}

void liberar_lista(Nodo **inicio)
{
    Nodo *aux;
    while(*inicio != NULL)
    {
        aux = *inicio;
        *inicio = aux->siguiente;
        free(aux);
    }

    printf("\nLista liberada.\n");
}