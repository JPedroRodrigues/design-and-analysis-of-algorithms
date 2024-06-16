#include <stdio.h>
#include <stdlib.h>

int n = 4;
int items[] = {1, 2, 3, 4};
int weights[] = {3, 2, 4, 1};
int values[] = {8, 3, 9, 6};

int **m;

int max(int x, int y) { return x > y ? x : y; }


int backPack(int n, int W) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (weights[i - 1] > j) m[i][j] = m[i - 1][j];
            else m[i][j] = max(m[i - 1][j], m[i - 1][j - weights[i - 1]] + values[i - 1]);
        }
    }
    return m[n][W];
}


int main() {
    int w = 5;

    m = (int **) malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) m[i] = (int *) malloc((w + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) m[i][j] = 0;
    }

    printf("Bottom up backpack problem: backPack(%d, %d) = %d\n", n, w, backPack(n, w));

    for (int i = 0; i < n; i++) free(m[i]);
    free(m);

    return 0;
}