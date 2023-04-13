#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum { MAYUSCULAS , MINUSCULAS } may_min ;

int strLargo ( const char *origen ); // Cantidad de caracteres
int strVacio ( const char *origen ); // retorna 1 si tiene al menos un caracter , 0 en otro caso
void strCopia ( char * destino , const char * origen ); // Copiador
char *reverse ( char * string ); // retorna una cadena que es string invertida
void strIzq ( char * destino , const char * origen ); // Saca blancos Izq .
void strDer ( char * destino , const char * origen ); // Sacablancos Der .
void strAmbos ( char * destino , const char * origen ); // Saca blancos Izq . y Der .
void strMayMin ( char * destino , const char * origen , may_min m ); // Convierte May. Min.

int main () {
    char * text1 = " Sera Cierto ?? " ;
    int largo = strLargo ( text1 )+1;
    char * result = ( char *) malloc(largo);
    char *reves;

    if ( result == NULL )
    {
        return -1; // sino pudo reservar memoria para result
    }

    printf("La cadena: ");
    puts(text1);
    printf("Se encuentra %s\n", (strVacio(text1) ? "No vacia" : "Vacia"));
    printf("Largo: %d\n", strLargo(text1));
    strCopia(result, text1);
    printf("Copia: [%s]\n", result);
    strIzq(result, text1);
    printf("Sin blancos a la Izq: [%s]\n", result);
    strDer(result, text1);
    printf("Der: [%s]\n", result);
    strAmbos(result, text1);
    printf("Ambos: [%s], sin blancon al principio ni al final.\n", result);
    strMayMin(result, text1, MAYUSCULAS);
    printf("Mayusculas: [%s]\n", result);
    strMayMin(result, text1, MINUSCULAS);
    printf("Minusculas: [%s]\n", result);
    reves = reverse(text1);
    printf("La cadena: %s invertida queda: %s\n", text1, reves);

    return 0;
}

int strLargo ( const char *origen )  // Cantidad de caracteres
{
    int i = 0;

    while (origen[i] != '\0')
    {
        i++;
    }

    return i;
    
}

int strVacio ( const char *origen ) // retorna 1 si tiene al menos un caracter , 0 en otro caso
{
    if( origen[0] == '\0')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void strCopia ( char * destino , const char * origen ) // Copiador
{
    int i = 0;

    while (origen[i] != '\0') // 
    {
        destino[i] = origen[i];

        i++;
    }

    destino[i] = '\0'; //agrego el caracter nulo al final de la cadena
        
}

char *reverse ( char * string ) // retorna una cadena que es string invertida
{
    int longitud = strlen(string);
    char temporal;
    for(int izquierda = 0, derecha = longitud - 1; izquierda < (longitud / 2); izquierda++, derecha--) 
    {
        temporal = string[izquierda];
        string[izquierda] = string[derecha];
        string[derecha] = temporal;
    }
    
    return string;

}

void strIzq(char *destino, const char *origen)
{
    int i = 0;
    int j = 0;
    while (origen[i] == ' ') // recorro la cadena hasta que no encuentre un espacio en blanco
    {
        i++; // incremento el contador
    }
    while (origen[i] != '\0') // recorro la cadena hasta el caracter nulo
    {
        destino[j] = origen[i]; // copio el caracter
        i++;                    // incremento el contador
        j++;                    // incremento el contador
    }
    destino[j] = '\0'; // agrego el caracter nulo al final de la cadena
}

// strDer saca los espacios en blancos a la derecha
void strDer(char *destino, const char *origen)
{
    int i = 0;
    int j = 0;
    while (origen[i] != '\0') // recorro la cadena hasta el caracter nulo
    {
        i++; // incremento el contador
    }
    i--;                     // decremento el contador para que no cuente el caracter nulo
    while (origen[i] == ' ') // recorro la cadena hasta que no encuentre un espacio en blanco
    {
        i--; // decremento el contador
    }
    while (j <= i) // recorro la cadena hasta el caracter nulo
    {
        destino[j] = origen[j]; // copio el caracter
        j++;                    // incremento el contador
    }
    destino[j] = '\0'; // agrego el caracter nulo al final de la cadena
}

// strAmbos saca los espacios en blancos a la izquierda y derecha
void strAmbos(char *destino, const char *origen)
{
    int i = 0;
    int j = 0;
    while (origen[i] == ' ') // recorro la cadena hasta que no encuentre un espacio en blanco
    {
        i++; // incremento el contador
    }
    while (origen[i] != '\0') // recorro la cadena hasta el caracter nulo
    {
        destino[j] = origen[i]; // copio el caracter
        i++;                    // incremento el contador
        j++;                    // incremento el contador
    }
    i--;                      // decremento el contador para que no cuente el caracter nulo
    while (destino[i] != ' ') // recorro la cadena hasta que no encuentre un espacio en blanco
    {
        i--; // decremento el contador
    }
    destino[i] = '\0'; // agrego el caracter nulo al final de la cadena
}

// strMayMin convierte a mayusculas o minusculas
void strMayMin(char *destino, const char *origen, may_min m)
{
    int i = 0;
    while (origen[i] != '\0') // recorro la cadena hasta el caracter nulo
    {
        if (m == MAYUSCULAS) // si m es MAYUSCULAS
        {
            if (origen[i] >= 'a' && origen[i] <= 'z') // si el caracter es una letra minuscula
            {
                destino[i] = origen[i] - 32; // convierto a mayuscula
            }
            else
            {
                destino[i] = origen[i]; // copio el caracter
            }
        }
        else // si m es MINUSCULAS
        {
            if (origen[i] >= 'A' && origen[i] <= 'Z') // si el caracter es una letra mayuscula
            {
                destino[i] = origen[i] + 32; // convierto a minuscula
            }
            else
            {
                destino[i] = origen[i]; // copio el caracter
            }
        }
        i++; // incremento el contador
    }
    destino[i] = '\0'; // agrego el caracter nulo al final de la cadena
}