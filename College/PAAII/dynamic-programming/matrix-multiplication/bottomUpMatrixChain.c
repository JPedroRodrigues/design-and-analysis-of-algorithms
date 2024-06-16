#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int **m, **s;

void matrixChain(int *p, int n) {
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}


int main() {
    int p[] = {200, 2, 30, 20, 5};
    int n = sizeof(p) / sizeof(int);

    m = (int **) calloc(n, sizeof(int *));
    s = (int **) calloc(n, sizeof(int *));

    for (int i = 0; i < n; i++) {
        m[i] = (int *) calloc(n, sizeof(int));
        s[i] = (int *) calloc(n, sizeof(int));  
    }

    matrixChain(p, n);

    printf("Bottom Up:\n");
    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);

    for (int i = 0; i < n; i++) {
        free(m[i]); 
        free(s[i]);
    }
    
    free(m); free(s);

    return 0;
}