#include<stdio.h>
#include<stdlib.h>

void imprimirMatriz(float A[][20], int n, int i, int j)
{
    for(i = 1; i <= n; i++)
    {
       for(j = 1; j <= (n+1); j++)
       {
           printf("%0.2f  ", A[i][j]);
       }
       printf("\n\n");
    }
}

void trocarLinhas(float A[][20], int n, int j)
{
    int k;
    float x[20];
    if(A[1][1] == 0)
    {
        for(k=2; k<=n; k++)
        {
            if(A[k][1] != 0)
            {
                for(j=1; j<=n+1; j++)
                {
                    x[j] = A[1][j];
                    A[1][j] = A[k][j];
                    A[k][j] = x[j];
                }
            }
        }
    }
}

void zerarlados(float A[][20], int n)
{
	int i, k, j;
	float c;
	for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i!=j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
}

void diagonal(float A[][20], int n, int i, int j)
{
    int k;
    float d; 
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i==j)
            {
                d = A[i][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]/d;
                }
            }
        }
    }
}
int main()
{
    int i,j,k,n;
    float A[20][20],c,d,x[10];
    
    printf("\n\tMetodo de Gauss-Jordan\t\n\n");
    printf("Informe a ordem da matriz: ");
    scanf("%d", &n);
    printf("\n\nDigite os elementos da matriz ampliada: \n\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf(" %f", &A[i][j]);

        }
        printf("\n\n");
    }
    
    trocarLinhas(A, n, j);
     
    printf("\n\n\nMatriz ampliada:\n\n");
    imprimirMatriz(A, n, i, j);
    getchar();
    
    zerarlados(A, n);
    
    printf("\n\n\nMatriz com lados zerados:\n\n");
    imprimirMatriz(A, n, i, j);
    getchar();
    
    diagonal(A, n, i, j);

    printf("\n\n\nMatriz identidade: \n\n");
    imprimirMatriz(A, n, i, j);
    
    return 0;    
}
