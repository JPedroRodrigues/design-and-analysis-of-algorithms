#include <stdio.h>
#include <limits.h>

int max(int x, int y) { return x > y ? x : y; }


int cutRod(int *p, int n) {
    if (n <= 0) return 0;

    int rMax = INT_MIN;

    for (int i = 1; i <= n; i++) {
        rMax = max(rMax, p[i] + cutRod(p, n - i));
    }
    return rMax;
}


int main() {
    int n = 4;
    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    printf(">> Backtracking\n");
    printf("Max receipt made using a rod with a length of %d: %d\n", n, cutRod(p, n));

    return 0;
}