#include <stdio.h>
#include <stdlib.h>

int main () 
{
    FILE *f;
    int entero, entero2 = 100;
    void *buffer = (int*)malloc(sizeof(int));

    f = fopen("salida.bin", "w+b"); //apertura en modo w/r binario
    
    printf("Ingrese un entero (distinto de 100): ");
    scanf("%d", &entero);
    
    buffer = &entero; //se guarda en buffer lo que ingresa el usuario
    
    fwrite(buffer, sizeof(int), 1, f);
    
    buffer = &entero2; //se “ensucia” la variable deliberadamente
 
    rewind(f); //se rebobina para leer desde el ppio del archivo
    
    fread(buffer, sizeof(int), 1, f);
    
    printf("El entero guardado fue %d\n", *(int*)buffer);
    
    fclose(f);
}