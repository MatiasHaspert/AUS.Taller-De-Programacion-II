#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_STRING 10
#define NCasillas 7
#define VACIO "          "

static char *BORRADO = "**********";
typedef char **DICCIONARIO;

DICCIONARIO CREAR();
void DestruirTablaHash(DICCIONARIO);
void SUPRIME(char *, DICCIONARIO);
int h(char *);
int localiza(char *, DICCIONARIO);
int localiza1(char *, DICCIONARIO);
int MIEMBRO(char *, DICCIONARIO);
void INSERTA(char *, DICCIONARIO);
void print_tabla(DICCIONARIO);

int main()
{
    DICCIONARIO dicc = CREAR();

    INSERTA("perro", dicc);
    INSERTA("naranja", dicc);
    INSERTA("vaso", dicc);

    printf("Tabla después de la inserción:\n");
    print_tabla(dicc);

    printf("\nBuscando elementos en la tabla:\n");
    if(MIEMBRO("perro", dicc))
        printf("perro se encuentra en la tabla\n");
    else 
        printf("perro no se encuentra en la tabla\n");
    
    if(MIEMBRO("naranja", dicc) == 1)
        printf("naranja se encuentra en la tabla\n");
    else 
        printf("naranja no se encuentra en la tabla\n");
    

    if(MIEMBRO("manzana", dicc) == 1)
        printf("manzana se encuentra en la tabla\n");
    else
        printf("manzana no se encuentra en la tabla\n");
    

    printf("\nEliminando elementos de la tabla:\n");
    SUPRIME("perro", dicc);

    printf("Tabla después de la eliminación:\n");
    print_tabla(dicc);

    printf("\nInsertando elementos...\n");
    INSERTA("matias", dicc);
    INSERTA("lentes", dicc);
    INSERTA("hojas", dicc);
    INSERTA("pc", dicc);
    INSERTA("lapiz", dicc);
    INSERTA("sol",dicc);

    printf("\nTabla después de la inserción:\n");
    print_tabla(dicc);
    
    printf("\nEliminando elementos de la tabla:\n");
    SUPRIME("matias", dicc);
    SUPRIME("lapiz", dicc);
    printf("Tabla después de la eliminación:\n");
    print_tabla(dicc);
    return EXIT_SUCCESS;
}

DICCIONARIO CREAR()
{
    DICCIONARIO dicc = malloc(sizeof(char *) * NCasillas);

    int i;
    for(i = 0; i < NCasillas; i++)
    {
        dicc[i] = malloc(sizeof(char) * TAM_MAX_STRING);
        strcpy(dicc[i], VACIO);
    }

    return dicc;
}

int h(char *cadena)
{
    int i = 0, suma = 0;
    while(cadena[i] != '\0')
    {
        suma += (int)cadena[i];
        i++;
    }
    
    return suma % NCasillas;
}

/*
localiza examina el DICCIONARIO desde el compartimiento para h(x) hasta que se encuentre x; o un contenedor vacio , o se
haya revisado toda la tabla y determinade que no se contiene a x. localiza devuelve el indice del contenedor en la que
se detiene por cualquier de esas razones.
*/

int localiza(char *cadena, DICCIONARIO dicc)
{
    int inicial, i = 0; //i cuenta el numero de contenedores examinados hasta el momento cuando se busca la cadena.
    inicial = h(cadena);

    while((i < NCasillas) && strcmp(dicc[(inicial + i)%NCasillas],cadena) != 0 && strcmp(dicc[(inicial + i)%NCasillas],VACIO) != 0)
    {
        i++;
    }

    return ((inicial + i) % NCasillas);
}

//como localiza, pero tambien se detiene en una entrada con suprimido y devuelve ese valor 
int localiza1(char *cadena, DICCIONARIO dicc)
{
    int inicial, i = 0;
    inicial = h(cadena);

    while((i < NCasillas) && strcmp(dicc[(inicial + i)%NCasillas],cadena) != 0 && strcmp(dicc[(inicial + i)%NCasillas],VACIO) != 0 && strcmp(dicc[(inicial + i)%NCasillas],BORRADO) != 0)
    {
        i++;
    }


    return ((inicial + i) % NCasillas);
}

int MIEMBRO(char *cadena, DICCIONARIO dicc)
{
    if(strcmp(dicc[localiza(cadena, dicc)], cadena) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void INSERTA(char *cadena, DICCIONARIO dicc)
{
    if(strcmp(dicc[localiza(cadena,dicc)], cadena) == 0)
    {
        printf("La cadena %s ya se encuentra en la tabla.\n",cadena);
        return;
    }

    int contenedor = localiza1(cadena,dicc);
    if(strcmp(dicc[contenedor], VACIO) == 0 || strcmp(dicc[contenedor], BORRADO) == 0)
    {
        strcpy(dicc[contenedor], cadena);
    }
    else
    {
        printf("\nError INSERTA, la tabla esta llena, no se pudo insertar la cadena %s.\n",cadena);
    }
}

void SUPRIME(char *cadena, DICCIONARIO dicc)
{
    int contenedor = localiza(cadena, dicc);

    if(strcmp(dicc[contenedor], cadena) == 0)
    {
        strcpy(dicc[contenedor], BORRADO);
    }
    else
    {
        printf("\nNo se encontro la cadena %s en la tabla.\n",cadena);
        return;
    }
}

void DestruirTablaHash(DICCIONARIO dicc)
{
    for(int i = 0; i < NCasillas; i++)
    {
        free(dicc[i]);
    }
    free(dicc);
}

void print_tabla(DICCIONARIO dicc)
{
    for (int i = 0; i < NCasillas; i++)
    {
        printf("\n[%d] %s", i, dicc[i]);
    }   
}