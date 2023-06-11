#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char sign;
    unsigned char num_bytes;
    unsigned char * bytes;
} APint;

APint * suma_APint( APint *, APint *);

int main()
{
    APint n1 = {-1, 4, 2};
    APint n2 = {1, 4, 2};

    APint p_n1 = n1;
    APint p_n2 = n2;

    APint *resultado = suma_APint(&p_n1,&p_n2);
    
    return 0;
}

APint * suma_APint( APint * i1, APint * i2)
{
    
}

APint * producto_APint(APint * i1, APint * i2)
{

}