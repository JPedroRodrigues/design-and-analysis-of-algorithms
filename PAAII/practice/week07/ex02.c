#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


int checkTable(int **table, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (table[i][j] == 0) return 0;
    }
    return 1;
}


int validMove(int l, int c, int moveL, int moveC, int n) {
    if (l + moveL >= n || c + moveC >= n) return 0;
    if (l + moveL < 0 || c + moveC < 0) return 0;
    return 1;
}


void horse(int **table, int n, int l, int c, int direction[8][2]) {
    if (checkTable(table, n)) printMatrix(table, n, n);

    for (int i = 0; i < n; i++) {
        printf("l = %d\nc = %d\n", l, c);
        if (!table[l][c] && validMove(l, c, direction[i][0], direction[i][1], n)) {
            table[l][c]++;
            printMatrix(table, n, n);
            printf("\n");

            horse(table, n, l + direction[i][0], c + direction[i][1], direction);
            
            table[l][c]--;
            l -= direction[i - 1][0];
            c -= direction[i - 1][1];
        }        
    }
}


int main() {
    int n = 8, line = 0, column = 0, move = 0;
    int **table = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) table[i] = (int *)calloc(n, sizeof(int));

    int direction[8][2] = {
        {2, -1},
        {2, 1},
        {1, -2},
        {1, 2},
        {-1, -2},
        {-1, 2},
        {-2, -1},
        {-2, 1}
    };

    horse(table, 8, 0, 0, direction);
    
    for (int i = 0; i < n; i++) free(table[i]);
    free(table);

    return 0;
}