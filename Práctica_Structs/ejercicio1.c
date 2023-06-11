#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tiempo
{
    int anio, mes, dia, hora, minuto, segundo;
}tiempo;

typedef struct {
    char *nombre;
    tiempo ultima_mod;

} archivo;

int compara_tiempos (tiempo *,tiempo *);
void imprime_tiempo (tiempo );
void lee_tiempos(tiempo * );
void ordena_alfa( archivo *, int );
void ordena_temporal(archivo *, int);
 
int main()
{
    tiempo t1,t2;
    tiempo *pt1, *pt2;
    pt1 = &t1;
    pt2 = &t2;

    archivo lista[3];

    archivo *p_lista = lista;

    for (int i = 0; i < 2; i++)
    {
        char *nombre = malloc (sizeof(char) * 10);
        printf("Ingrese el nombre del archivo %d: ",i+1);
        fgets(nombre,10,stdin);

        lista[i].nombre = nombre;
        
    }
    
    printf("Tiempo 1: \n");
    lee_tiempos(pt1);
    imprime_tiempo(t1);

    printf("Tiempo 2: \n");
    lee_tiempos(pt2);
    imprime_tiempo(t2);

    int compara = compara_tiempos(pt1,pt2);

    if(compara == 1)
    {
        printf("El tiempo 1 es anterior a tiempo 2.\n");
    }
    else if (compara == -1)
    {
        printf("El tiempo 1 es posterior a tiempo 2.\n");
    }
    else
    {
        printf("Los tiempos son iguales.\n");
    }

    ordena_alfa(p_lista,2);
    printf("Lista de archivos ordenados alfabeticamente:\n");
    for (int i = 0; i < 2; i++)
    {
        printf("%s \n",lista[i].nombre);
        imprime_tiempo(lista[i].ultima_mod);
    }

    ordena_temporal(p_lista,2);
    printf("Archivos ordenados por tiempos:\n");

    for (int i = 0; i < 2; i++)
    {
        printf("%s \n",lista[i].nombre);
        imprime_tiempo(lista[i].ultima_mod);
    }
            
    return EXIT_SUCCESS;
}

int compara_tiempos (tiempo *t1, tiempo *t2)
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

    return 0;
}

void lee_tiempos(tiempo *t)
{
    printf("Año: ");
    scanf("%d",&t->anio);
    printf("Mes: ");
    scanf("%d",&t->mes);
    printf("Día: ");
    scanf("%d",&t->dia);
    printf("Hora: ");
    scanf("%d",&t->hora);
    printf("Minuto: ");
    scanf("%d",&t->minuto);
    printf("Segundo: ");
    scanf("%d",&t->segundo);
}


void imprime_tiempo(tiempo t)
{
    printf("\n%d/%d/%d  %d:%d:%d\n",t.dia,t.mes,t.anio,t.hora,
            t.minuto,t.segundo);
}

void ordena_alfa( archivo * lista, int n)
{
    int i,j;

    for ( i = 0; i < n; i++)
    {
        for ( j = i + 1; j < n; j++)
        {
            if (strcmp(lista[i].nombre,lista[j].nombre) > 0)
            {
                archivo aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }    
        }    
    }
    
}

void ordena_temporal(archivo *lista, int n )
{   
    int i,j;

    for ( i = 0; i < n; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if (compara_tiempos(&lista[i].ultima_mod,&lista[j].ultima_mod) == -1)
            {
                archivo aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }  
        }
    }
    
}