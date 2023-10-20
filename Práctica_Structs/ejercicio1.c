#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3
typedef struct
{
    int anio, mes, dia, hora, minuto, segundo;
}Tiempo;

typedef struct
{
    char *nombre;
    Tiempo ultima_mod;
}Archivo;

void ingresa_tiempo (Tiempo *);
int compara_tiempos (Tiempo *, Tiempo *);
void imprime_tiempo (Tiempo );
void ordena_alfa( Archivo *, int );
void ordena_temporal(Archivo *, int );

int main()
{
    Tiempo t1, t2;
    Archivo lista[N];
    
    printf("\nTiempo #1:\n");
    ingresa_tiempo(&t1);
    printf("\nTiempo #2:\n");
    ingresa_tiempo(&t2);

    printf("\nTiempo #1:\n");
    imprime_tiempo(t1);
    printf("\nTiempo #2:\n");
    imprime_tiempo(t2);

    int compara = compara_tiempos(&t1,&t2);
    if(compara == 1) 
    {
        printf("\nEl tiempo #1 es anterior al #2.\n");
    }
    else if(compara == -1) 
    {
        printf("El tiempo #1 es posterior al #2.\n");
    }
    else
    {
        printf("\nLos tiempos son iguales.\n");
    }
    
    Tiempo *aux = malloc(sizeof(Tiempo));
    for (int i = 0; i < N; i++)
    {
        char *nombre = malloc(sizeof(char) * 20);
        printf("\nIngresa el nombre del archivo #%d: ",i+1);
        fflush(stdin);
        fgets(nombre,20,stdin);
        fflush(stdin);
        lista[i].nombre = nombre;
        printf("\nUltima modificacion:\n");
        fflush(stdin);
        ingresa_tiempo(aux);
        fflush(stdin);
        lista[i].ultima_mod = *aux;
    }
    ordena_alfa(lista,N);
    printf("\nArchivos ordenados alfabeticamente:\n");
    for (int i = 0; i < N; i++)
    {
        printf("Nombre: %s\n",lista[i].nombre);
        printf("Tiempo:\n");
        imprime_tiempo(lista[i].ultima_mod);
    }

    ordena_temporal(lista,N);
    printf("\nArchivos ordenados cronologicamente:\n");
    for (int i = 0; i < N; i++)
    {
        printf("Nombre: %s\n",lista[i].nombre);
        printf("Tiempo:\n");
        imprime_tiempo(lista[i].ultima_mod);
    }
    
    for (size_t i = 0; i < N; i++)
    {
        free(lista[i].nombre);
    }
    
    free(aux);
    
    return EXIT_SUCCESS;
}

void ingresa_tiempo (Tiempo *t)
{
    printf("\nAño: ");
    scanf("%d",&t->anio);
    printf("\nMes: ");
    scanf("%d",&t->mes);
    printf("\nDía: ");
    scanf("%d",&t->dia);
    printf("\nHora: ");
    scanf("%d",&t->hora);
    printf("\nMinuto: ");
    scanf("%d",&t->minuto);
    printf("\nSegundo: ");
    scanf("%d",&t->segundo);
}

int compara_tiempos (Tiempo *t1, Tiempo *t2)
{   
    if(t1->anio < t2->anio)
        return 1;
    if(t1->anio > t2->anio)
        return -1;
    if(t1->mes < t2->mes)
        return 1;
    if(t1->mes > t2->mes)
        return -1;
    if(t1->dia < t2->dia)
        return 1;
    if(t1->dia > t2->dia)
        return -1;
    if(t1->hora < t2->hora)
        return 1;
    if(t1->hora > t2->hora)
        return -1;
    if(t1->minuto < t2->minuto)
        return 1;
    if(t1->minuto > t2->minuto)
        return -1;    
    if(t1->segundo < t2->segundo)
        return 1;
    if(t1->segundo > t2->segundo)
        return -1;
    else
        return 0;
}

void imprime_tiempo (Tiempo t)
{
    printf("\n %d/%d/%d  %d:%d:%d \n",t.dia,t.mes,t.anio,t.hora,t.minuto,t.segundo);
}

void ordena_alfa( Archivo *lista, int n)
{
    int i,j;
    Archivo aux;
    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre) > 0)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}

void ordena_temporal(Archivo *lista, int n)
{
    int i,j;
    Archivo aux;
    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if(compara_tiempos(&lista[i].ultima_mod,&lista[j].ultima_mod) == -1)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}
