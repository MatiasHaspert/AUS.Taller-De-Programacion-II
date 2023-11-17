/*
a)permitir el ingreso de alumnos a la nomina

b) teniendo en cuenta que las carretas son:
    AUS - TUC - TUQ

    listar a los alumnos por la determinada carrera

c) dar el numero de alumnos por carrera

d) buscar un alumno determinado y mostrar sus datos

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[20];
}Alumno;

Alumno *nomina;

void ingreso_datos(Alumno *, int );
void listado_alumnos(Alumno *,int );
void print_alumno(Alumno *, int );
void alumnos_por_carrera(Alumno *, int);
void alumno_determinado(Alumno *, int, int);

int main()
{
    int a; //cantidad de alumnos
    int i;
    printf("Teclee la cantidad de alumnos que desee en la nomina: ");
    scanf("%d",&a);

    nomina = malloc(sizeof(Alumno) * a);

    if(nomina == NULL)
    {
        printf("No se pudo reservar memoria.\n");
        return EXIT_FAILURE;
    }

    for(i = 0; i < a; i++)
    {
        ingreso_datos(nomina,i);
    }
    strcpy(nomina[0].carrera,"AUS");
    strcpy(nomina[1].carrera,"TUC");
    strcpy(nomina[2].carrera,"TUQ");
    strcpy(nomina[3].carrera,"AUS");

    int id;
    printf("\nIngrese la matrícula del alumno y mostraré sus datos: ");
    scanf("%d",&id);
    alumno_determinado(nomina,id,a);
    alumnos_por_carrera(nomina,a);
    listado_alumnos(nomina,a);
    
    free(nomina);


    return EXIT_SUCCESS;
}

void ingreso_datos (Alumno *nomina, int i)
{
    printf("\nIngrese los datos del alumno #%d:\n",i+1);
    printf("\nMatricula: ");
    scanf("%d",&nomina[i].matricula);
    getc(stdin); //limpio el enter ingresado
    printf("\nNombre: ");
    fgets(nomina[i].nombre,20,stdin);
    printf("\nCarrera: ");
    fgets(nomina[i].carrera,20,stdin);
    printf("\nPromedio: ");
    scanf("%f",&nomina[i].promedio);
    getc(stdin);
    printf("\nDirección: ");
    fgets(nomina[i].direccion,20,stdin);
}

void print_alumno(Alumno *nomina, int i)
{
    printf("\nMatrícula: %d.",nomina[i].matricula);
    printf("\nNombre: ");puts(nomina[i].nombre);
    printf("Carrera: %s.",nomina[i].carrera);
    printf("\nPromedio: %2.f",nomina[i].promedio);
    printf("\nDirección: "); puts(nomina[i].direccion); 
}


void listado_alumnos(Alumno *nomina, int cant)
{
    printf("\nListado de alumnos por carreras:\n");
    printf("AUS:\n");
    for (int i = 0; i < cant; i++)
    {
        if (strcmp(nomina[i].carrera, "AUS") == 0)
        {
            print_alumno(nomina,i);
        }
    }

    printf("\nTUC:\n");
    for (int i = 0; i < cant; i++)
    {
        if (strcmp(nomina[i].carrera, "TUC") == 0)
        {
           print_alumno(nomina,i);
        }
    }

    printf("TUQ:\n");
    for (int i = 0; i < cant; i++)
    {
        if (strcmp(nomina[i].carrera, "TUQ") == 0)
        {
           print_alumno(nomina,i);
        }
    }
}

void alumnos_por_carrera(Alumno *nomina, int cant)
{
    int contAUS = 0, contTUC = 0, contTUQ = 0;

    for (int i = 0; i < cant; i++)
    {
        if(strcmp(nomina[i].carrera, "AUS") == 0)
        {
            contAUS++;
        }
        else if(strcmp(nomina[i].carrera, "TUC") == 0)
        {
            contTUC++;
        }
        else if(strcmp(nomina[i].carrera, "TUQ") == 0)
        {
            contTUQ++;
        }
    }

    printf("\nCantidad de alumnos en la carrera AUS: %d.",contAUS);
    printf("\nCantidad de alumnos en la carrera TUC: %d.",contTUC);
    printf("\nCantidad de alumnos en la carrera TUQ: %d.\n",contTUQ);
    
}

void alumno_determinado(Alumno *nomina, int matricula, int cant)
{
    int bandera = 0;

    for (int i = 0; i < cant; i++)
    {
        if(nomina[i].matricula == matricula)
        {
            print_alumno(nomina,i);
            bandera = 1;
            break;
        }
    }

    if(bandera == 0)
    {
        printf("\nEl alumno no se encuentra en la nomina.\n");
    }

}


