#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


int checkTable(int **table, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (table[i][j] == 0) return 0;
    }
    return 1;
}


int validMove(int **table, int l, int c, int n) {
    return (l >= 0 && l < n && c >= 0 && c < n && table[l][c] == 0);
}


int horse(int **table, int i, int n, int l, int c, int direction[8][2]) {
    if (i > n * n) return 1;

    int boolean = 0;
    for (int j = 0; j < n; j++) {
        int newL = l + direction[j][0];
        int newC = c + direction[j][1];

        if (validMove(table, newL, newC, n)) {
            table[newL][newC] = i;

            horse(table, i + 1, n, newL, newC, direction);
            
            if (!(i > n * n)) table[l][c] = 0;
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

    int x = 0, y = 0;
    table[x][y] = 1;
    if (horse(table, 2, 8, x, y, direction)) 
        printf("É possível realizar o percurso a partir das posições %d e %d\n", x, y);

    for (int i = 0; i < n; i++) free(table[i]);
    free(table);

    return 0;
}