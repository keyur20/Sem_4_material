#include<stdio.h>

#include<stdlib.h>

#define board[N][N];
#define queen[N];
int n;

void intialize()
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        queen[i] = -1;
        for (j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
        
    }
    

}



void isSafe(int row,int col)
{
    int i,j;
    for (i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return 0;
        }
        
    }
    for ( i = row, j = col; i >= 0 && j >= 0; i--,j--)
    {
        
         if (board[i][j])
        {
            return 0;
        }
    }
    for ( i = row, j = col; i >= 0 && j < n; i--,j++)
    {
         if (board[i][j])
        {
            return 0;
        }
    }

    return 1;
    
    
}
void print_board()
{
    printf("\nsolution: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(board[i][j] == 1)
            {
                printf("Q ");
            }
            else
            {
                printf("_ ");
            }
            
        }
        printf("\n");
        
    }
    printf("\n");
    
}

void placequeen(int row)
{
    int col;
    for (col = 0; col < n; col++)
    {
        if(isSafe(row,col))
        {
            board[row][col] = 1;
            queen[row] = col;
            if (row == n-1)
            {
                print_board();
            }
            else
            {
                placequeen(row+1);
            }
            board[row][col] = 0;
            queen[i] = -1;
            
        }

    }
    
    
    
}


int main()
{
    int n;
    printf("Enter the size of the Chess Board: ");
    scanf("%d", &n);

    intialize();
    placequeen(0);

    return 0;
}