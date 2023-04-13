/*
Los operadores ++ y -- con tipo de dato puntero tienen un funcionamiento distinto que cuando incrementamos o 
decrementamos una variable entera.

Cuando utilizamos el operador ++ con un puntero incrementa la variable según el tamaño del tipo de dato que apunta. 
Si es un puntero a entero incrementa la dirección en 4 bytes (en un sistema operativo de 32bits), si es un puntero a tipo char 
incrementa la dirección en 1 byte etc.

Un ejemplo de como utilizar la sintaxis de punteros:
*/

#include<stdio.h>


int main()
{
    int vec[5]={10,20,30,40,50};
    int *pe;
    pe=vec;
    printf("%i\n",*pe);  // 10
    pe++;
    printf("%i\n",*pe);  // 20
    pe++;
    printf("%i\n",*pe);  // 30
    pe--;
    printf("%i\n",*pe);  // 20
    
    return 0;
} 