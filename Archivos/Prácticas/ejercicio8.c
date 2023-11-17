/*
Escribir un programa que proceso los datos de un archivo csv(valores separados por comas) que contiene las calificaciones de alumnos de un curso
Para cada alumno se tiene: nombre,apellido, puntaje del proceso y puntaje del examen final (ambas de 0 a 100)

Para el puntaje final del curso,se calcula de la siguiente manera:
            puntaje_final_del_curso = 0.4*puntaje_del_proceso + 0.6*puntaje_del_examen_final

El programa crea otro archivo en donde se añade un campo que contenga el puntaje final del curso para cada alumno.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMEF1  "PlanillaCalificaciones.csv"
#define NAMEF2  "PlanillaProcesada.csv"

typedef struct
{
    char nombre[20];
    char apellido[20];
    int puntaje_proceso;
    int puntaje_examen;
}Alumno;

int obtener_puntaje_final(int , int );

int main()
{
    FILE *f1;
    FILE *f2;
    char *linea = malloc(sizeof(char) * 100);
    Alumno *a = malloc(sizeof(Alumno));

    if((f1 = fopen(NAMEF1,"r")) == NULL)
    {
        printf("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    if((f2 = fopen(NAMEF2,"w")) == NULL)
    {
        printf("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    fgets(linea,100,f1);
    linea[strlen(linea)-1] = '\0'; //elimino el '\n'

    fprintf(f2,"%s, Puntaje - Final\n",linea);
    int puntaje_final;

    while(fgets(linea, 100, f1) != NULL)
    {
        sscanf(linea," %[^,],%[^,],%d,%d",a->nombre,a->apellido,&a->puntaje_proceso,&a->puntaje_examen); // %[^,] va a leer caracteres hasta encontrar una coma (','), pero no incluirá la coma en la cadena leída
        puntaje_final = obtener_puntaje_final(a->puntaje_proceso,a->puntaje_examen);
        fprintf(f2,"%s, %s, %d, %d, %d\n",a->nombre,a->apellido,a->puntaje_proceso,a->puntaje_examen,puntaje_final);
    }

    fclose(f1);
    fclose(f2);
    free(linea);
    free(a);
    return EXIT_SUCCESS;
}

int obtener_puntaje_final(int p_proceso, int p_examen)
{
    int puntaje_final = 0;

    return puntaje_final = 0.4*p_proceso + 0.6*p_examen; 
}