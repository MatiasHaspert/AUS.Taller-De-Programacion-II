#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 100
#define C 20

void parseo (char *linea);
void parseoInvertido (char *linea);
float obtenerMonto(int, int, char ,FILE *);
int main()
{
    FILE *pfP; //puntero al archivo personas
    FILE *pfL; //puntero al archivo plan
    FILE *pfPA;//puntero al archivo personas actualizado
    char linea[L];
    char nombre[C];
    char apellido[C];
    int edad;
    char sexo[C];
    int mesesIns;
    char plan;

    float montoApagar;

    char nombrePFP[] = "personas.txt";
    char nombrePFL[] = "plan.txt";
    char nombrePFPA[]= "Personas-actualizado.txt";

    if((pfP = fopen(nombrePFP,"r")) == NULL) printf("Error al abrir el archivo %s.\n",nombrePFP);
    
    if((pfL = fopen(nombrePFL,"r")) == NULL) printf("Error al abrir el archivo %s.\n",nombrePFL);
        
    if((pfPA = fopen(nombrePFPA,"w")) == NULL) printf("Error al abrir el archivo %s.\n",nombrePFPA);

    fgets(linea,L,pfP);//leo los titulos
    //fgets tambien almacena el salto de linea asi que lo remplazamos por el terminal de cadena
    linea[strlen(linea)-1] = '\0';
    fprintf(pfPA,"%s-Monto a pagar\n",linea);//agrego el nuevo titulo

    while(fscanf(pfP,"%s",linea) != EOF)
    {
        parseo(linea);
        sscanf(linea,"%s %s %d %s %d %c",nombre,apellido,&edad,sexo,&mesesIns,&plan);
        montoApagar = obtenerMonto(edad,mesesIns,plan,pfL);
        parseoInvertido(linea);
        fprintf(pfPA,"%s-%.2f\n",linea,montoApagar);
    }
    
    //cierre de archivos
    if(!fclose(pfP)) printf("El archivo %s se cerro correctamente.\n",nombrePFP);
    else printf("Error.\n");
    if(!fclose(pfL)) printf("El archivo %s se cerro correctamente.\n",nombrePFL);
    else printf("Error.\n");
    if(!fclose(pfPA)) printf("El archivo %s se cerro correctamente.\n",nombrePFPA);
    else printf("Error.\n");

    return EXIT_SUCCESS;
}

//reemplazo los guiones por espacios
void parseo (char *linea)
{
    int i = 0;

    while(linea[i] != '\0')
    {
        if(linea[i] == '-')
        {
            linea[i] = ' ';
        }
        i++;
    }
}


//reemplazo los espacios por guiones
void parseoInvertido (char *linea)
{
    int i = 0;

    while(linea[i] != '\0')
    {
        if(linea[i] == ' ')
        {
            linea[i] = '-';
        }
        i++;
    }
}


float obtenerMonto (int edad,int mesesIns,char plan, FILE *pfL)
{
    float monto = 0;
    float descuento = 0;
    char linea[L];
    char plan_file; //obtiene el plan que necesitamos desde el archivo plan.txt
    rewind(pfL); //siempre que volvemos a la funcion, que arranque desde el inicio;

    do
    {
        fscanf(pfL,"%s",linea);
        parseo(linea);
        sscanf(linea,"%c %f %f",&plan_file,&monto,&descuento);
    }while(!feof(pfL) && strcmp(&plan_file,&plan)!=0);
    
    if(mesesIns > 24)
    {
        monto = monto - monto * (descuento * 1.0/100);
    }

    if(edad < 12 || edad > 65)
    {
        monto = monto - monto * (5.0/100);
    }

    return monto;
}