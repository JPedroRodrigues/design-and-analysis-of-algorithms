#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int n = 8, line = 0, column = 0, move = 0;
int **table;

int checkTable(int **table, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (table[i][j] == 0) return 0;
    }
    return 1;
}


int validMove(int **table, int l, int c, int n) {
    return (l >= 0 && l < n && c >= 0 && c < n && table[l][c] == 0);
}


int horse(int i, int n, int l, int c, int direction[8][2]) {
    int done = (i > n * n);

    if (i > n * n) { 
        printMatrix(table, n, n);
        return done;
    }

    for (int j = 0; j < n; j++) {
        int newL = l + direction[j][0];
        int newC = c + direction[j][1];

        if (validMove(table, newL, newC, n)) {
            table[newL][newC] = i;

            done = horse(i + 1, n, newL, newC, direction);
            
            if (!done) table[newL][newC] = 0;
            else break;
        }       
    }
    return done;
}


int main() {
    table = (int **)calloc(n, sizeof(int *));
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

    int x = 0, y = 0;
    table[x][y] = 1;
    if (horse(2, 8, x, y, direction)) 
        printf("É possível realizar o percurso a partir das posições %d e %d\n", x, y);

    for (int i = 0; i < n; i++) free(table[i]);
    free(table);

    return 0;
}