/*
Crear un programa que lea un numero determinado (¡100) de reales intro-
ducidos por teclado, los almacene en un vector para luego mostrarlos en orden
inverso. Para recorrer el array debera usar aritmetica de punteros en lugar de
indices del array.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cant_numeros;
    int i;
    int *pu;

    printf("Teclea la cantidad de números que desee ingresar (max.100):\n");
    do
    {
        printf("> ");
        scanf("%d",&cant_numeros);

        if (cant_numeros < 0 || cant_numeros > 100)
        {
            printf("Por favor ingrese un número entre [0..100]: ");
        }
        
    } while (cant_numeros < 0 || cant_numeros > 100);
    
    int array[cant_numeros];
    pu = array;

    i = 0;

    while (i < cant_numeros)
    {
        printf("Ingrese un valor a la posicion %d: ",i);
        scanf("%d", pu);

        pu++;
        i++;
    }

    printf("\nArray inverso:\n");

    i = cant_numeros - 1;
    
    while (i >= 0)
    {
        array[i - 1];

        printf("%d ",*(pu - 1));

        pu--;
        i--;
    }
    
    return EXIT_SUCCESS;
}