#include <stdio.h>
#include <stdlib.h>

int n = 4;
int items[] = {1, 2, 3, 4};
int weights[] = {3, 2, 4, 1};
int values[] = {8, 3, 9, 6};

int **m;

int max(int x, int y) { return x > y ? x : y; }


int backPack(int n, int W) {
    if (n < 0 || W <= 0) return 0;
    else if (weights[n] > W) return backPack(n - 1, W);
    else return max(backPack(n - 1, W), backPack(n - 1, W - weights[n]) + values[n]);
}


int main() {
    int w = 5;

    m = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) m[i] = (int *) malloc(w * sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < w; j++) m[i][j] = -1;
    }

    printf("Top down backpack problem: backPack(%d, %d) = %d\n", n - 1, w, backPack(n - 1, w));

    for (int i = 0; i < n; i++) free(m[i]);
    free(m);

    return 0;
}