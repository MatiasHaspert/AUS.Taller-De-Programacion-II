#include <stdio.h>

void imprimirM (int **,int , int );

int main()
{
    int **b;
    int f = 3, c = 3;

    imprimirM(b,f,c);



    return 0;
}

void imprimirM (int **p, int f, int c)
{
    
    printf("Matriz: \n");

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ",p[i][j]);

        }
        
        printf("\n");
    }
    



}