/*
se crea un archivo con una lista de alumnos y se los guarda de forma binaria.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nombre[20];
    char apellido[20];
    char facultad[20];
    int semestre;
}Alumno;

int main()
{
    FILE *pf;
    char nombreA[20];
    int cant_alum;
    char cadena[1000]; //titulos del archivo
    
    printf("Ingrese la cabecera: ");
    fgets(cadena,1000,stdin);//primera linea - cabecera

    printf("Ingrese el nombre del archivo al que desee guardar los datos: ");
    scanf("%s",nombreA);

    if((pf=fopen(nombreA,"wb")) == NULL)
    {
        printf("Error al abrir el archivo.\n");
    }

    printf("Ingrese la cantidad de alumnos que hay en la facultad: ");
    scanf("%d",&cant_alum);

    //escribimos en el archivo la primera linea(titulos)
    fwrite(cadena,sizeof(char),sizeof(cadena),pf);


    Alumno al[cant_alum];
    int i = 0;
    while (i < cant_alum)
    {
        printf("\nIngrese el nombre del alumno [%d]: ",i+1);
        scanf("%s",al[i].nombre);
        printf("\nIngrese el apellido del alumno [%d]: ",i+1);
        scanf("%s",al[i].apellido);
        printf("\nIngrese el nombre de la facultad del alumno [%d]: ",i+1);
        scanf("%s",al[i].facultad);
        printf("\nIngrese el semestre en el que se encuentra el alumno [%d]: ",i+1);
        scanf("%d",&al[i].semestre);
        //copiamos los datos en el archivo
        fwrite(&al[i],sizeof(Alumno),1,pf);
        i++;
    }
    

    //cierre de archivos
    if(!fclose(pf)) printf("El archivo %s se cerro correctamente.\n",nombreA);
    else printf("Error.\n");

    return EXIT_SUCCESS;
}