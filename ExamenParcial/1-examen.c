#include <stdio.h>
#include <stdlib.h>

char * digitos2char(int, int*);

int main()
{
    int a;
    int cant = 0;

    printf("Ingrese un entero: ");
    scanf("%d",&a);
    
    char *cadena = digitos2char(a,&cant);
    printf("\nCadena: ");
    puts(cadena);
    printf("Cantidad de digitos: %d\n",cant);
    free(cadena);
    return 0;
}

char * digitos2char(int n, int *cant)
{
    char temp[10];
    int dig;
    int i = 0;
    while(n != 0)
    {
        dig = n % 10;
        temp[i] = dig+48;
        (*cant) = (*cant) + 1;
        i++;
        n = n / 10;
    }
    char *cadena = malloc(sizeof(char) * (*cant)+1); //la cantidad de digitos y el caracter \0
    i = 0;
    while(i < (*cant))
    {
        cadena[i] = temp[i];
        i++;
    }
    cadena[i] = '\0';
    return cadena;
}