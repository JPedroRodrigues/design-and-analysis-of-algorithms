#include <stdio.h>
#include <stdlib.h>

int **squareMatrix(int n) {
    int **m = (int **) calloc(n, sizeof(int *));

    for (int i = 0; i < n; i++) {
        m[i] = (int *) calloc(n, sizeof(int));
    }

    return m;
}


int **patternMatrix(int **m, int n) {
    int value = 0;
    int firstHalf = n / 2;

    int decrease = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // N par
            if (n % 2 == 0) {
                if (i < n / 2 && value <= i && j < n / 2) {
                value++;
                } else if (j >= n / 2) {
                    m[i][j] = m[i][j - decrease];
                    decrease += 2;
                    continue;
                } else if (i >= n / 2 && value < n - i) {
                    value++;
                }
            // N ímpar
            } else {
                if (i <= n / 2 && value <= i && j <= n / 2) {
                value++;
                } else if (j > n / 2) {
                    m[i][j] = m[i][j - decrease - 1];
                    decrease += 2;
                    continue;
                } else if (i > n / 2 && value < n - i) {
                    value++;
                }
            }
            
            m[i][j] = value;
            decrease = 1;
        }
        value = 0;
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
}


int main() {
    int n;
    printf("Dimensões da matriz NxN: "); scanf("%d", &n);

    int **m = squareMatrix(n);
    m = patternMatrix(m, n);
    printMatrix(m, n, n);

    for (int i = 0; i < n; i++) free(m[i]);
    free(m);
    return 0;
}