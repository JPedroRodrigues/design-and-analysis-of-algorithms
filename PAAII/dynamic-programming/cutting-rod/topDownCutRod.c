#include <stdio.h>
#include <stdlib.h>

int *rMax;

int max(int x, int y) { return x > y ? x : y; }


int cutRod(int *p, int n) {
    if (rMax[n] > 0) return rMax[n];
    if (n <= 0) return 0;
    
    for (int i = 1; i <= n; i++) {
        rMax[n] = max(rMax[n], p[i] + cutRod(p, n - i));
    }
    return rMax[n];
}


int main() {
    int n = 4;
    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    rMax = (int *) calloc(n + 1, sizeof(int));

    printf(">> Top Down\n");
    printf("Max receipt made using a rod with a length of %d: %d\n", n, cutRod(p, n));

    free(rMax);
    return 0;
}