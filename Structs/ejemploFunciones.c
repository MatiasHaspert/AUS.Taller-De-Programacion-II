#include <stdio.h>
#include <stdlib.h>

struct punto
{
    float x;
    float y;
};

struct punto calcularPmedio (struct punto , struct punto );

int main()
{
    struct punto inico;
    struct punto final;

    printf("Programa para calcular el punto medio de un segmento!\n");

    printf("Ingrese la coordenada x e y del punto de inicio:\n");
    printf("x> ");
    scanf("%f",&inico.x);
    printf("y> ");
    scanf("%f",&inico.y);

    printf("Ingrese la coordenada x e y del punto final:\n");
    printf("x> ");
    scanf("%f",&final.x);
    printf("y> ");
    scanf("%f",&final.y);

    struct punto medio = calcularPmedio(inico,final);

    printf("El punto medio es (%f,%f).\n",medio.x, medio.y);

    return EXIT_SUCCESS;
}

struct punto calcularPmedio (struct punto pi, struct punto pf)
{
    struct punto medio;

    medio.x = (pi.x + pf.x) / 2;
    medio.y = (pi.y + pf.y) / 2;

    return medio;

}