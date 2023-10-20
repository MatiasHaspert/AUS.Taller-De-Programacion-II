#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    MAYUSCULAS,
    MINUSCULAS
} may_min;

// Prototipos
int strLargo(const char *origen);                             // cantidad de caracteres
int strVacio(const char *origen);                             // retorna 1 si tiene al menos un caracter, 0 en otro caso
void strCopia(char *destino, const char *origen);             // copiador
char *reverse(char *string);                                  // retorna una cadena que es string invertida
void strIzq(char *destino, const char *origen);               // saca blancos Izq
void strDer(char *destino, const char *origen);               // saca blancos Der
void strAmbos(char *destino, const char *origen);             // saca blancos Izq y Der
void strMayMin(char *destino, const char *origen, may_min m); // convierte a mayusculas o minusculas

// Funcion principal
int main()
{
    char *text1 = " Sera Cierto ?? ";
    int largo = strLargo(text1) + 1;
    char *result = (char *)malloc(largo);
    char *reves;
    if (result == NULL)
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

// strLargo retorna la cantidad de caracteres de una cadena
int strLargo (const char *origen)
{
    int cont = 0;

    while(*origen != '\0')
    {
        cont++;
        origen++;
    }
    
    return cont;
}


int strVacio(const char *origen)
{
    if(*origen == '\0')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void strCopia(char *destino, const char *origen)
{
    while(*origen != '\0')
    {
        *destino = *origen;
        origen++;
        destino++;
    }

    *destino = '\0';
}

char *reverse(char *string)
{
    char *reves = malloc(sizeof(strLargo(string))+ 1); 
    int i = 0;
    int j = strLargo(string) - 1;
    
    while(i < strLargo(string))
    {
        reves[i] = string[j];
        j--;
        i++;
    }

    reves[i] = '\0';

    return reves;
}


// strIzq saca los espacios en blancos a la izquierda
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

void strDer(char *destino, const char *origen)
{
    int i = 0, j = 0;

    while(origen[i] != '\0')
    {
      i++;  
    }
    i--; // decremento el contador por el caracter nulo
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

void strAmbos(char *destino, const char *origen)
{
    int i = 0;
    int j = 0;

    while(origen[i] == ' ') // si encuentro un espacio en blanco incremento el indice i
    {
        i++;
    }
    while(origen[i] != '\0') 
    {
        destino[j] = origen[i]; //copio la cadena
        i++;
        j++;
    }
    i--; // decremento el contador por el caracter nulo y elimino los espacios a la derecha
    while(origen[i] == ' ') 
    {
        i--;
    }

    destino[i] = '\0';
}

void strMayMin(char *destino, const char *origen, may_min m)
{
    int i = 0;

    while(origen[i] != '\0')
    {
        if(m == MAYUSCULAS)
        {
            if(origen[i] >= 'a' && origen[i] <= 'z') // si el caracter es una minuscula
            {
                destino[i] = origen[i]-32; // lo convierto a mayuscula
            }
            else
            {
                destino[i] = origen[i]; // copio el caracter
            }
        }
        else // m == MINUSCULA
        {
            if(origen[i] >= 'A' && origen[i] <= 'Z') // si el caracter es una mayuscula
            {
                destino[i] = origen[i]+32; // lo convierto a minuscula
            }
            else
            {
                destino[i] = origen[i]; // copio el caracter
            }
        }
        i++;    
    }

    destino[i] = '\0';
}






