/*
al promedio de dos estudiantes le sumamos 3
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nombre[20], apellido[20];
    int edad;
    float promedio;
}estudiante;

int main()
{
    FILE *archi;

    if((archi = fopen("datosEst.txt","r")) == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return EXIT_FAILURE;
    }

    char titulos[200];
    fgets(titulos,200,archi);

    printf("Al sumarle 3 al promedio de cada estudiante quedan:\n");
    printf("%s",titulos);

    estudiante es;
    for (int i = 0; i < 2; i++)
    {
        fscanf(archi,"%s%s%d%f",es.nombre,es.apellido,&es.edad,&es.promedio);
        printf("%s\t%s\t%d\t%.2f.\n",es.nombre,es.apellido,es.edad,es.promedio+3);
    }
  
    if(!fclose(archi))
    {
        printf("\nEl archivo %s se cerro correctamente.\n","datosEst.txt");
    }
    else
    {
        printf("Error.\n");
    }

    return EXIT_SUCCESS;
}