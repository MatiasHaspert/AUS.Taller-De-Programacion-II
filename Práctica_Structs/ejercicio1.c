/*
Dada la siguiente estructura que permite representar tiempos:

typedef struct tiempo{
int anio, mes, dia, hora, minuto, segundo;
} Tiempo;

Implemente las siguientes funciones:

int compara_tiempos( Tiempo *t1, Tiempo * t2);
que retorna:
    1 si *t1 es anterior a *t2
    0 si *t1 es igual a *t2
    -1 si *t1 es posterior a *t2

2. void imprime_tiempo( Tiempo t );
que imprime el contenido de la estructura t con el siguiente formato: "dia/mes/anio
hora:minuto:segundo" (por ejemplo: "3/8/1974 18:23:59").
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tiempo
{
    int anio,mes,dia,hora,minuto,segundo;
}tiempo;

int compara_tiempos (tiempo *t1,tiempo *t2);
void imprime_tiempo (tiempo t);

int main()
{
    


    return EXIT_SUCCESS;
}

int compara_tiempos (tiempo *t1, tiempo *t2)
{




}