#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int **m;

int matrixChain(int *p, int i, int j) {
    if (i == j) return 0;

    if (m[i][j] != 0) return m[i][j];

    m[i][j] = INT_MAX;

    for (int k = i; k < j; k++) {
        int q = matrixChain(p, i, k) + matrixChain(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (q < m[i][j]) m[i][j] = q;
    }
    return m[i][j];
}


int main() {
    int p[] = {200, 2, 30, 20, 5};
    int n = sizeof(p) / sizeof(int);

    m = (int **) calloc(n, sizeof(int *));

    for (int i = 0; i < n; i++) m[i] = (int *) calloc(n, sizeof(int));

    int mult = matrixChain(p, 1, n - 1);

    printf("Top Down:\n");
    printf("Minimum number of multiplications: %d\n", mult);

    for (int i = 0; i < n; i++) free(m[i]);
    free(m);

    return 0;
}