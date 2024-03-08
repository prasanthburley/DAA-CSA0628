#include <stdio.h>
#include <stdbool.h>
#define MAX 20 
int board[MAX][MAX];
int solutions = 0;
void printBoard(int N) {
    printf("Solution %d:\n", solutions);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] > 0)
                printf("Q%d ", board[i][j]);
            else
                printf(".  ");
        }
        printf("\n");
    }
    printf("\n");
}
bool isSafe(int row, int col, int N) {
    int i, j;
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j])
            return false;
    }
    return true;
}
bool solveNQueens(int col, int N) {
    if (col == N) {
        printBoard(N);
        solutions++;
        return true;
    }
    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col, N)) {
            board[i][col] = col + 1;
            res = solveNQueens(col + 1, N) || res;
            board[i][col] = 0;
        }
    }
    return res;
}
int main() {
    int N;
    printf("Enter the value of N  ");
    scanf("%d", &N);
    if (N <= 0 || N > 8) {
        printf("Invalid input. Please enter a value between 1 and %d.\n", MAX);
        return 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
    if (!solveNQueens(0, N)) {
        printf("No solutions found.\n");
    }
    return 0;
}
