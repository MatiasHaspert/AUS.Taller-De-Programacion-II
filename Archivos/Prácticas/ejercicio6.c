/*
leemos en el archivo del ejercicio 5 el alumno que se encuentre en la posicion que deseemos
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
    char cad[1000];

    if((pf=fopen("alumnos.txt","rb")) == NULL)
    {
        printf("Error al abrir el archivo.\n");
    }

    //ingresar la posicion de revision
    int pos;
    printf("Ingrese la posicion del alumno (1->primer alumno): ");
    scanf("%d",&pos);

    printf("La posicion corresponde a:\n");
    Alumno al;
    //          saltamos la cabecera    cantidad de bytes de la struct
    int salto = sizeof(cad) + (pos-1) * sizeof (Alumno);
    fseek(pf,salto,SEEK_SET); //salto a la posicion deseada
    fread(&al,sizeof(Alumno),1,pf);
    printf("\nDatos del alumno %d:\n",pos);
    printf("\nNombre: %s.",al.nombre);
    printf("\nApellido: %s.",al.apellido);
    printf("\nFacultad: %s.",al.facultad);
    printf("\nSemestre: %d.\n",al.semestre);

    //cierre de archivos
    if(!fclose(pf)) printf("El archivo %s se cerro correctamente.\n","alumnos.txt");
    else printf("Error.\n");

    return EXIT_SUCCESS;
}