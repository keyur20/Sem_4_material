#include <stdio.h>
#include <stdbool.h>

#define N 10

void printBoard(int board[N][N], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", board[i][j] == 1 ? 'Q' : '-');
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col, int size) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper diagonal on the right side
    for (int i = row, j = col; i >= 0 && j < size; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueensUtil(int board[N][N], int row, int size) {
    if (row == size) {
        printBoard(board, size);
        return true;
    }

    bool result = false;
    for (int col = 0; col < size; col++) {
        if (isSafe(board, row, col, size)) {
            board[row][col] = 1;
            result = solveNQueensUtil(board, row + 1, size) || result;
            board[row][col] = 0;
        }
    }

    return result;
}

void solveNQueens(int size) {
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0, size))
        printf("No solution exists.\n");
}

int main() {
    int size;
    printf("Enter the size of the chessboard: ");
    scanf("%d", &size);

    solveNQueens(size);

    return 0;
}
