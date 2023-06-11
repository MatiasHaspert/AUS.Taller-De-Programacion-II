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

int contarAlumn(char *);
float obtenerPunFinal(char *);

int main()
{
    char nombreArchiE[] = "PlanillaCalificaciones.csv";
    char nombreArchiS[] = "PlanillaProcesada.csv";
    FILE *pEntr;
    FILE *pSal;
    int n; //cantidad de alumnos
    n = contarAlumn(nombreArchiE); 
    printf("La cantidad de alumnos es %d.\n",n);

    //abrimos los archivos
    if((pEntr = fopen(nombreArchiE,"r")) == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return EXIT_FAILURE;
    }

    if((pSal = fopen(nombreArchiS,"w")) == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return EXIT_FAILURE;
    }

    //primero llegamos a la segunda linea
    char linea[1000];
    fgets(linea,1000,pEntr); //leemos los titulos

    //fgets tambien almacena el salto de linea asi que lo remplazamos por el terminal de cadena
    linea[strlen(linea)-1] = '\0';

    //agregamos el nuevo campo "Puntaje - Final" al nuevo archivo
    fprintf(pSal,"%s Puntaje - Final\n",linea);

    //recorremos a los alumnos
    float puntaje;
    for (int i = 0; i < n; i++)
    {
        fgets(linea,1000,pEntr); // leemos la linea correspondiente a cada alumno
        linea[strlen(linea)-1] = '\0'; //reemplazamos el '\n' por '\0'
        puntaje = obtenerPunFinal(linea);
        fprintf(pSal,"%s %2.f\n",linea,puntaje); 
    }
    
    //cierre de archivos
    if(!fclose(pEntr)) printf("El archivo %s se cerro correctamente.\n",nombreArchiE);
    else printf("Error.\n");

    if(!fclose(pSal)) printf("El archivo %s se cerro correctamente.\n",nombreArchiS);
    else printf("Error.\n");

    return EXIT_SUCCESS;
}

int contarAlumn(char *nombre)
{
    FILE *pa;

    if((pa = fopen(nombre,"r")) == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return EXIT_FAILURE;
    }

    int n = 0;
    char letra;

    letra = fgetc(pa);
    while(!feof(pa))
    {
        if(letra == '\n')
        {
            n++; //en n guardo los saltos de línea, es decir, cada salto de línea es una línea
        }
        letra = fgetc(pa);
    }

    return n-1; //le resto uno porque hay que acordarse que en la primera línea estan los titulos
}

float obtenerPunFinal(char *linea)
{
    float punt_proceso, punt_ExFinal;

    //contamos las comas para llegar hasta el puntaje del proceso
    int i=0, cont_comas = 0;

    while(cont_comas < 2)
    {
        if(linea[i] == ',')
        {
            cont_comas++;
        }
        i++;
    }

    //estamos posicionados dsp de la segunda coma(los valores del puntaje del proceso)
    int j = 0;
    char nro[100]; //variable para cargar el numero que esta en la linea
    while(linea[i] != ',')
    {
        nro[j++] = linea[i++]; //copiamos el puntaje como cadena
    }
    nro[j] = '\0'; //agregamos el caracter de final de cadena
    punt_proceso = atoi(nro); //conversion de la cadena a int
    i++; //salteamos la 3ra coma

    //obtenemos el puntaje del examen final
    j = 0;
    while(linea[i] != '\0')
    {
        nro[j++] = linea[i++]; //copiamos el puntaje como cadena
    }
    nro[j] = '\0'; //agregamos el caracter de final de cadena
    punt_ExFinal = atoi(nro); //conversion de la cadena a int

    //se calcula el puntaje final
    float puntaje = 0.4 * punt_proceso + 0.6 * punt_ExFinal;
    return puntaje;
}