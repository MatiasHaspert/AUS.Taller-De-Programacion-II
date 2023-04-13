#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i =5 , j []={1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10};
    int k;
    char x = 'a' , pal [] = " texto en c " ;
    int *pi;
    char *pc;


    /*
    1. Mostrar la direcci ́on de “i” y su valor.
    2. Mostrar los mismos valores a trav ́es del puntero “pi”.
    */
    pi = &i;
    printf("Por Variable : 'i' Valor : %d  dirección: %p.\n",i,&i);
    printf("Por puntero: 'pi' Valor: %d  dirección: %p.\n",*pi, pi);

    /*
    3. Recorrer el vector “j” mostrando para cada elemento, su direccion y valor.
    4. Recorra el vector accediendo a traves del puntero “pi” y usando  ́algebra de
    punteros.
    */

    for ( k = 0; k < 10; k++)
    {
        printf("Por variable: j[%d]  Valor: %d  Direccion: %p.\n",k,j[k],&j[k]);
    }

    pi = j;

    k = 0;
    while( k < 10)
    {
        printf("Por puntero: 'pi  Valor:%d  Direccion: %p.\n",*pi, pi);
        pi++;
        k++;
    }

    /*
    5. Repita lo mismo con las variables char, el arreglo y el puntero.
    6. Finalmente muestre la direcci ́on donde se almacenan ambos punteros.
    */

    pc = &x;
    printf("Por Variable : 'x' Valor : %c  dirección: %p.\n",x,&x);
    printf("Por puntero: 'pc' Valor: %c  dirección: %p.\n",*pc, pi);

    k = 0;
    while (pal[k] != '\0')
    {
        printf("Por variable: pal[%d]  Valor: %c  direccion: %p.\n",k,pal[k],&pal[k]);

        k++;
    }

    pc = pal;
    k = 0;

    while (*pc != '\0')
    {
        printf("Por puntero: *pc  Valor: %c  direccion: %p.\n",*pc,pc);
        pc++;
    }

    printf("La direccion del puntero pi es: %p\n", pi); // &pi es la direccion de pi
    printf("La direccion del puntero pc es: %p\n", pc); // &pc es la direccion de pc


    


    return EXIT_SUCCESS;
}