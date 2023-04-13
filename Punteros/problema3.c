#include <stdio.h>


int main()
{
    char c1='A';
    char c2='B';
    char *pc;
    pc=&c1;
    printf("%c\n",c1); //se imprime: A
    *pc='a';
    printf("%c\n",c1); //se imprime: a
    c1='Z';
    printf("%c\n",*pc); //se imprime: Z
    pc=&c2;
    printf("%c\n",*pc); //se imprime: B
    
    return 0;
}