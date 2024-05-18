#include <stdio.h>
#define N 8

void print_board(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_valid(int board[N][N], int row, int col) {
    // check if the current position is valid for placing a queen
    // check if there is any queen in the same row
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return 0;
        }
    }
    // check if there is any queen in the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }
    // check if there is any queen in the lower-left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }
    return 1;
}

int solve(int board[N][N], int col) {
    if (col >= N) {
        // all queens have been placed, print the solution
        print_board(board);
        return 1;
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (is_valid(board, i, col)) {
            board[i][col] = 1;
            count += solve(board, col + 1);
            board[i][col] = 0;
        }
    }
    return count;
}

int main() {
    int board[N][N] = {0};
    printf("Enter the size of the board: ");
    int n;
    scanf("%d", &n);
    if (n != N) {
        printf("This program only solves the 8-Queens Problem, please enter 8.\n");
        return 0;
    }
    printf("Possible solutions:\n");
    int num_solutions = solve(board, 0);
    printf("Total number of solutions: %d\n", num_solutions);
    return 0;
}
