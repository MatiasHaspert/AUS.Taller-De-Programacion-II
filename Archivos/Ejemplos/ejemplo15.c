#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    char linea[100];
    int cant, i, dia, mes, anio;

    if((f = fopen("fechas.txt", "w+")) == NULL)
    {
        printf("Error al abrir el archivo.");
        exit(EXIT_FAILURE);
    }
    

    printf("Teclee la cantidad de fechas que desee guardar en el archivo: ");
    scanf("%d",&cant);

    for (i = 0; i < cant; i++)
    {
        printf("\nFecha #%d:",i+1);
        printf("\nDía: "); scanf("%d",&dia);
        printf("\nMes: "); scanf("%d",&mes);
        printf("\nanio: "); scanf("%d",&anio);

        fprintf(f, "%d/%d/%d\n", dia, mes, anio);
    }

    // Mueve el puntero de archivo al principio del archivo
    fseek(f, 0, SEEK_SET);
    
    printf("\nFechas guardadas en el archivo:\n");
    while((fgets(linea, 100, f)) != NULL)
    {
        sscanf(linea,"%d/%d/%d",&dia,&mes,&anio);
        printf("%d/%d/%d\n", dia, mes, anio);
    }

    fclose(f);
    return EXIT_SUCCESS;
}
