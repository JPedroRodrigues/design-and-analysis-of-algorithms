#include <stdio.h>
#include <limits.h>

int matrixChain(int *p, int i, int j) {
    if (i == j) return 0;

    int minimum = INT_MAX;

    for (int k = i; k < j; k++) {
        int q = matrixChain(p, i, k) + matrixChain(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (q < minimum) minimum = q;
    }
    return minimum;
}


int main() {
    int p[] = {200, 2, 30, 20, 5};
    int n = sizeof(p) / sizeof(int);

    matrixChain(p, 1, n);

    printf("Backtracking:\n");
    printf("Minimum number of multiplications: %d\n", matrixChain(p, 1, n - 1));

    return 0;
}