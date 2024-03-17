#include <stdio.h>
#include <stdlib.h>


void print(int *a, int n) {
    printf("[%d", a[0]);
    for (int i = 1; i < n; i++) printf(", %d", a[i]);
    printf("]\n");
}


void printMatrix(int **a, int rows, int cols) {
    for (int i = 0; i < rows; i++) print(a[i], cols);
}


void simpleSudoku(int **sudoku, int n, int *values, int i, int *usedR, int *usedC) {
    if (i == n) {
        printMatrix(sudoku, n, n);
        return;
    }

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            // printf("%d used in %d° row\n", sudoku[j][k], j + 1);
            usedR[sudoku[j][k]] = 1;

            // printf("%d used in %d° column\n", sudoku[k][i], i + 1);
            usedC[sudoku[k][i]] = 1;
        }

        // printf("\n");
        // printf("I want to put %d in position [%d][%d].\n", values[j], j, i);
        // printf("Was %d used?\nUsedR = %d\nUsedC = %d\n", values[j], usedR[values[j]], usedC[values[j]]);
        
        // print(usedR, n + 1);
        // print(usedC, n + 1);
        
        printf("\n");

        if (sudoku[j][i] == 0) {
            for (int k = 0; k < n; k++) {
                if (!usedC[values[k]] && !usedR[values[k]]) {
                    usedC[values[k]] = 1;
                    usedR[values[k]] = 1;

                    sudoku[j][i] = values[k];
                }
            }
        }
        
        
        for (int k = 0; k < n; k++) {
            usedR[sudoku[j][k]] = 0;
            usedC[sudoku[k][i]] = 0;
        }

        simpleSudoku(sudoku, n, values, i + 1, usedR, usedC);
    }
}


int main() {
    int n = 4;

    int **sudoku = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) sudoku[i] = (int *)calloc(n, sizeof(int));
    
    int *values = (int *)calloc(n, sizeof(int));
    int *usedR = (int *)calloc(n + 1, sizeof(int));
    int *usedC = (int *)calloc(n + 1, sizeof(int));

    for (int i = 0; i < n; i++) values[i] = i + 1;

    sudoku[0][1] = 2;
    sudoku[0][2] = 4;
    sudoku[1][0] = 1;
    sudoku[1][3] = 3;
    sudoku[2][0] = 4;
    sudoku[2][3] = 2;
    sudoku[3][1] = 1;
    sudoku[3][2] = 3;

    simpleSudoku(sudoku, n, values, 0, usedR, usedC);

    for (int i = 0; i < n; i++) free(sudoku[i]);
    free(sudoku);

    free(values);
    free(usedR);
    free(usedC);

    return 0;
}