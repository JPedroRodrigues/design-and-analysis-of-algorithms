#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **generateMatrix(int l, int c) {
    srand(time(NULL));

    int **m = (int**) calloc(l, sizeof(int*));

    for (int i = 0; i < l; i++) {
        m[i] = (int*) calloc(c, sizeof(int));
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = rand() % 10 + 1;
        }
    }
    return m;
}


void printMatrix(int **m, int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("| %2d ", m[i][j]);
        }
        printf("|\n");
    }
};


int main() {
    int n;
    printf("Dimensão da matriz NxN: "); scanf("%d", &n);

    while(n <= 0 || n > 100) {
        printf("Valor inválido. Digite novamente a dimensão da matriz NxN: "); scanf("%d", &n);
    }
    
    int **m = generateMatrix(n, n);
    printMatrix(m, n, n);

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (m[i][j] < m[i-1][j] && m[i][j] < m[i][j - 1] && m[i][j] < m[i][j + 1] && m[i][j] < m[i + 1][j]) {
                printf("Posição do mínimo local %d: (%d, %d).\n", m[i][j], i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        free(m[i]);
    }

    free(m);
    return 0;
}