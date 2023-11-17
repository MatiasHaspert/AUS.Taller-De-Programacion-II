#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char fecha[10]; // dd/mm/aa
    double monto;
}sueldos;

typedef struct
{
    char nombre[25];
    int legajo;
    sueldos sueldosMensuales[12];
    double sueldoProm;
}Empleado;

void asignarSueldo(Empleado *);
void calculaProm(Empleado *);
void datos_empleado(Empleado *);

int main()
{
    Empleado *e1 = malloc(sizeof(Empleado));

    printf("Empleado #1:\n");
    printf("Ingrese su nombre: ");
    fgets(e1->nombre,25,stdin);
    printf("\nLegajo: ");
    scanf("%d",&e1->legajo);
    getc(stdin); //limpio el enter ingresado;
    
    asignarSueldo(e1);
    
    calculaProm(e1);

    datos_empleado(e1);


    free(e1);

    return 0;
}

void asignarSueldo(Empleado *e)
{
    int i = 0;
    while(i < 12)
    {
        printf("\nIngrese el sueldo del mes #%d: ",i+1);
        printf("\nFecha: ");
        fgets(e->sueldosMensuales[i].fecha, 9, stdin);
        printf("\nMonto: ");
        scanf("%lf",&e->sueldosMensuales[i].monto);
        getc(stdin);
        i++;
    }
}

void calculaProm(Empleado *e)
{
    double suma_montos = 0;
    int i = 0;
    while(i < 12)
    {
        suma_montos += e->sueldosMensuales[i].monto;
        i++;
    }

    e->sueldoProm = suma_montos/12;
}

void datos_empleado(Empleado *e)
{
    printf("\nDatos del empleado:");
    printf("\nNombre: ");
    puts(e->nombre);
    printf("Legajo: %d.",e->legajo);
    printf("\nSueldo promedio: %f\n",e->sueldoProm);
}