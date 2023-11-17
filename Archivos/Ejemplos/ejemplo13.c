#include <stdio.h>
#include <errno.h>

int main ()
{
    FILE *f;
    char c;

    if ((f=fopen("nombres.txt", "r")) == NULL)
    {
        printf("errno = %d\n", errno);
        perror("main");
    } 
    else 
    {
        while ((c = fgetc(f)) != EOF) 
        fputc(c, stdout);
    
        printf("Fin del archivo %s.\n", "nombres.txt");
        fclose(f);
    }
 
    return 0;
}