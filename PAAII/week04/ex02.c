#include <stdio.h>

int combination(int n, int m) {
    if (m == 0 || n == m) return 1;
    return combination(n - 1, m) + combination(n - 1, m - 1);
}

int main() {
    int n = 5, m = 2;
    printf("Combination (%d %d) = %d\n", n, m, combination(n, m));
    return 0;
}