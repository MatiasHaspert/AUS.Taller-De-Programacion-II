#include<stdio.h>


int main()
{
    int f;
    int *pe;
    pe=&f;
    for(*pe=1;*pe<=10;*pe=*pe+1)
    {
        printf("%i\n",f); //se imprime 1,2,3,4,5,6,7,8,9,10
    }
    
    return 0;
}