#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct alumno
{
    int matricula;
    char nombre[20];
    char carrera[30];
    float promedio;
    char direccion[20];
}Alumno;

int main()
{
    Alumno *matias;

    matias = malloc(sizeof(Alumno));  // es necesario crear la estructura mediante malloc

    printf("\nMatricula: ");
    scanf("%d",&matias->matricula);
    getc(stdin); //desechar el enter ingresado
    strcpy(matias->nombre,"Matias");
    printf("\nCarrera: ");
    fgets(matias->carrera,30,stdin);
    matias->promedio = 8.2;
    printf("\nDireccion: ");
    fgets(matias->direccion,20,stdin);


    printf("\n%d - %s - %s - %f - %s \n", matias->matricula, matias->nombre, matias->carrera, matias->promedio, matias->direccion);

    return EXIT_SUCCESS;
}