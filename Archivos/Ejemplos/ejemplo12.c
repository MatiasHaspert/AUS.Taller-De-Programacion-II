#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f1, *f2;
    char linea1[100];
    char linea2[100];

    if ((f1 = fopen("nombres.txt", "r")) == NULL)
    {
        printf("Error al abrir el archivo nombres.txt\n");
        exit(EXIT_FAILURE);
    }

    if ((f2 = fopen("apellidos.txt", "r")) == NULL) 
    {
        printf("Error al abrir el archivo apellidos.txt\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(linea1, 100, f1) != NULL && fgets(linea2, 100, f2) != NULL) 
    {
        if (strcmp(linea1, linea2) != 0) 
        {
            printf("Diferencia en la línea de nombres.txt: %s", linea1);
            printf("Diferencia en la línea de apellidos.txt: %s", linea2);
            break;
        }
    }

    fclose(f1);
    fclose(f2);

    return EXIT_SUCCESS;
}






