/*
Escribir una funcion que tome como argumento un entero positivo entre 1 y 7
y retorne un puntero a cadena con el nombre del dıa de la semana correspondiente
al argumento. Probar dicha funcion.
*/

#include <stdio.h>
#include <stdlib.h>

char* cadena (int );

int main()
{
    int num;
    char *pu;

    printf("Ingrese un entero positivo entre 1 y 7 y te devolveré su día de la semana correspondiente:\n");

    do
    {
        printf("> ");
        scanf("%d",&num);

    } while (num < 1 || num > 7);
    
    pu = cadena(num);

    printf("El día de la semana es %s.\n",pu);

    return EXIT_SUCCESS;
}

char* cadena (int num)
{
    char *cadena[10];

    switch (num)
    {
    case 1:
        return *cadena = "Lunes";
        break;
    case 2:
        return *cadena = "Martes";
        break;
    case 3:
        return *cadena = "Miércoles";
        break;
    case 4:
        return *cadena = "Jueves";
        break;
    case 5:
        return *cadena = "Viernes";
        break;
    case 6:
        return *cadena = "Sábado";
        break;
    case 7:
        return *cadena = "Domingo";
        break;
    }

}