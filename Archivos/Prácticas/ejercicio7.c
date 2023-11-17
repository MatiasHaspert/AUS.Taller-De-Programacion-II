#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20], apellido[20];
    int edad;
    float prom;
}Estudiante;

int main() 
{
    FILE *archivo_entrada, *archivo_salida;
    char titulos[100];
    Estudiante *e = malloc(sizeof(Estudiante));

    if ((archivo_entrada = fopen("datosEst.txt", "r")) == NULL) {
        printf("Error al abrir el archivo de entrada.");
        exit(EXIT_FAILURE);
    }

    if ((archivo_salida = fopen("datosEst_actualizados.txt", "w")) == NULL) {
        printf("Error al abrir el archivo de salida.");
        exit(EXIT_FAILURE);
    }

    fgets(titulos,100,archivo_entrada);
    fprintf(archivo_salida,"%s",titulos);

    while (fscanf(archivo_entrada, "%s %s %d %f", e->nombre, e->apellido, &e->edad, &e->prom) == 4) //fscanf devuelve la cantidad de enteros que leyo
    {
        e->prom += 3; // Sumar 3 al promedio
        fprintf(archivo_salida, "%s\t %s\t %d\t    %.2f\n", e->nombre, e->apellido, e->edad, e->prom);
    }

    fclose(archivo_entrada);
    fclose(archivo_salida);

    /*
    // Reemplazar el archivo original con el archivo actualizado (opcional)
    remove("datosEst.txt");
    rename("datosEst_actualizados.txt", "datosEst.txt");
    */
    free(e);
    return EXIT_SUCCESS;
}