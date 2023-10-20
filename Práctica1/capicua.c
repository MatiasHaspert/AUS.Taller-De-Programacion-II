#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esCapicua(char []);

int main()
{
    char cadena[100];

    printf("Ingrese una cadena y te dire si es capicua: ");
    scanf("%s",cadena);
    

    printf("\nLa cadena *%s*  %s.\n",cadena,(esCapicua(cadena) ? "es capicua" : "no es capicua"));



    return EXIT_SUCCESS;
}

int esCapicua(char cadena[])
{
    int i = 0;
    int j = strlen(cadena) -1;

    while(i < j)
    {
        if(cadena[i] != cadena[j])
        {
            return 0;
        }
        i++;
        j--;
        
    }

    return 1;
    
}