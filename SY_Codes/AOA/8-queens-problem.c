#include <stdio.h>
#include <stdlib.h>

#define N 20

int board[N][N];
int queen[N];
int n;

void initialize()
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        queen[i] = -1;
        for(j = 0; j < n; j++)
            board[i][j] = 0;
    }
}

int isSafe(int row, int col)
{
    int i, j;

    for(i = 0; i < row; i++)
    {
        if(board[i][col])
            return 0;
    }

    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j])
            return 0;
    }

    for(i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if(board[i][j])
            return 0;
    }

    return 1;
}

void printBoard() {
    int i, j;

    printf("\nSolution: \n\n");
    for(i = 0; i < n; i++) 
    {
        for(j = 0; j < n; j++) 
        {
            if(board[i][j] == 1)
                printf("Q ");
            else
                printf("_ ");
        }
        printf("\n");
    }
    printf("\n");
}

void placeQueen(int row) 
{
    int col;

    for(col = 0; col < n; col++) 
    {
        if(isSafe(row, col)) 
        {
            board[row][col] = 1;
            queen[row] = col;

            if(row == n - 1)
            {
                printBoard();
            }
            else
            {
                placeQueen(row + 1);
            }

            board[row][col] = 0;
            queen[row] = -1;
        }
    }
}

int main() 
{
    
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    initialize();
    placeQueen(0);

    return 0;
}