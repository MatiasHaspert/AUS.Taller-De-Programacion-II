#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct 
{
    double abscisa;
    double ordenada;
}TipoPunto;

typedef struct 
{
    TipoPunto situacion;
    char nombre[50];
}tipoCiudad;

void Reordenar(tipoCiudad [], int, char []);

int main()
{
    tipoCiudad ciudades[3] ={2.1, 3.4, "San Jorge",
                                    1.2,5.3, "Sastre",
                                    1.2, 3, "El Trebol"};

    char nombreCiudadReferencia[20];

    printf("Ingresa un nombre de una ciudad: ");
    scanf("%s",nombreCiudadReferencia);

    Reordenar(ciudades,3,nombreCiudadReferencia);

    printf("Ciudades ordenadas:");
    for (int i = 0; i < 3; i++)
    {
        printf("Ciudad: %s, Abscisa: %.2f, Ordenada: %.2f\n",ciudades[i].nombre,ciudades[i].situacion.abscisa,ciudades[i].situacion.ordenada);
    }
    

    return EXIT_SUCCESS;
}

void Reordenar(tipoCiudad ciudades[], int num_ciudades, char nombre_ciudad_referencia[])
{
    int i, j, k;
    double restaAbscisaA, restaOrdenadaA, totalA;
    double restaAbscisaB, restaOrdenadaB, totalB;
    tipoCiudad aux;
    for (i = 0; i < num_ciudades; i++)
    {
        if (strcmp(ciudades[i].nombre, nombre_ciudad_referencia) == 0)
        {
            aux = ciudades[0];
            ciudades[0] = ciudades[i];
            ciudades[i] = aux;
        }
    }
    for (i = 0; i < num_ciudades; i++)
    {
        for (j = i + 1; j < num_ciudades; j++)
        {
            for (k = j + 1; k < num_ciudades; k++)
            {
                restaAbscisaA = ciudades[i].situacion.abscisa - ciudades[j].situacion.abscisa;
                restaOrdenadaA = ciudades[i].situacion.ordenada - ciudades[j].situacion.ordenada;
                totalA = sqrt(pow(restaAbscisaA, 2) + pow(restaOrdenadaA, 2));

                restaAbscisaB = ciudades[i].situacion.abscisa - ciudades[k].situacion.abscisa;
                restaOrdenadaB = ciudades[i].situacion.ordenada - ciudades[k].situacion.ordenada;
                totalB = sqrt(pow(restaAbscisaB, 2) + pow(restaOrdenadaB, 2));

                if (totalA > totalB)
                {
                    aux = ciudades[j];
                    ciudades[j] = ciudades[k];
                    ciudades[k] = aux;
                }
            }
        }
    }
}