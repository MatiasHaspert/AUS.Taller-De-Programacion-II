#include <stdio.h>

struct libro
{
    char titulo[30], autor[30], editorial[15];
    int anyo,edicion;
};

int main()
{
    struct libro a = {"El Quijote","Cervantes","Limusa",1987,2}, b;
    b = a;//copia todos los datos de a en b
    printf("%s - %s - %s - %d - %d\n", b.titulo, b.autor, b.editorial,
    b.edicion, b.anyo); 
    return 0;
}