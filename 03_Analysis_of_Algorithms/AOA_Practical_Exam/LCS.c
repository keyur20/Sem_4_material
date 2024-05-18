#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b)
{
    return (a>b) ? a : b;
}

void lcs(char x[],char y[],int m, int n)
{
    int L[m+1][n+1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if( i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if( x[i-1] == y [j-1])
            {
                L[i][j] = L[i-1][j-1] + 1;
                printf("%c",x[i-1]);
            }
            else
            {
                L[i][j] = max(L[i-1][j],L[i][j-1]);
            }
        }
        
    }

    
    
    
}

int main()
{
    char x[100],y[100];
    printf("Enter the first string :");
    scanf("%s ",x);
    printf("\n");
    printf("Enter the second string ");
    scanf("%s",y);
    printf("\n");
   
    
    int m = strlen(x);
    int n = strlen(y);

    printf("The longest common subsequence is : ");
    lcs(x,y,m,n);



    
   


    return 0;
}