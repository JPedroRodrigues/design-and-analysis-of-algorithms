#include <stdio.h>
#include <stdlib.h>


int max(int x, int y) { return x > y ? x : y; }


int cutRod(int *p, int n) {
    int *rMax = (int *) calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            rMax[i] = max(rMax[i], p[j] + rMax[i - j]);
        }
    }
    return rMax[n];
}


int main() {
    int n = 4;
    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    printf(">> Bottom Up\n");
    printf("Max receipt made using a rod with a length of %d: %d\n", n, cutRod(p, n));
    return 0;
}