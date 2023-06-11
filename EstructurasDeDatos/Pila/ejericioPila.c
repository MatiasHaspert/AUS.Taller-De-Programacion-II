/*
Todo compilador o intérprete de un lenguaje tiene un módulo dedicado a analizar si una 
expresión está correctamente codificada, es decir que los paréntesis estén abiertos y cerrados en un orden lógico y bien balanceados.

Se debe desarrollar un programa que tenga las siguientes responsabilidades :

- Ingresar una fórmula que contenga paréntesis, corchetes y llaves.
- Validar que los ( ) [] y {} estén correctamente balanceados.
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "pila.h"

int verificar (item *);

nodo *pila; //(CIMA) variable global (cualquier funcion puede acceder) (siempre guarda la direccion del primer nodo)

int main()
{
    pila = NULL; //el primer nodo es vacio
    char formula[101];

    printf("Ingrese la formula: ");
    fgets(formula,101,stdin);
    
    printf("\nLa formula a considerar es: %s\n",formula);
    if(verificar(formula) == 1) printf("\nFórmula balanceada.\n");
    else printf("\nFórmula no balanceada.\n");

    return EXIT_SUCCESS;
}

/*insertar*/
void push (nodo **pila, item v)
{
    nodo *nuevo = NULL;

    nuevo = malloc(sizeof(nodo)); //creamos el nuevo nodo
    nuevo->valor = v; // almacenamos el valor ingresado en un nuevo nodo

    nuevo->siguiente = *pila; //el nuevo nodo lo hacemos apuntar al que hasta ese momento era el primer nodo, es decir, al nodo al que apunta la raiz actualmente

    *pila = nuevo;  // y la raiz siempre apunta a la direccion del primer nodo
}

item pop (nodo ** pila)
{    
    nodo *pnodo = NULL; //creamos un nodo auxiliar
    item v;

    pnodo = *pila; //lo hacemos apuntar al nodo que vamos a borrar
    *pila = (*pila)->siguiente; //avanzamos la raiz al segundo nodo 

    v = pnodo->valor; // guardamos el valor del nodo a borrar y lo retornamos

    free(pnodo); // eliminamos el nodo
    return v;
}

int verificar (item *formula)
{
    int i = 0;
    item x; //caracter

    while(formula[i] != '\0')
    {
        if(formula[i] == '(' || formula[i] == '[' || formula[i] == '{') //si encontramos algun caracter de apertura lo insertamos en la pila
        {
            push(&pila,formula[i]);
        }

        if(formula[i] == ')' || formula[i] == ']' || formula[i] == '}')
        {
            if(vacia() == 1) return EXIT_SUCCESS;

            x = pop(&pila);

            if(formula[i] == ')' && x != '(') return EXIT_SUCCESS;
            if(formula[i] == ']' && x != '[') return EXIT_SUCCESS;
            if(formula[i] == '}' && x != '{') return EXIT_SUCCESS;
        }
        i++;
    }
    if(vacia() != 1) return EXIT_SUCCESS;
    return 1;
}

int vacia()
{
    if(pila == NULL) return 1;
    else return 0;
}
