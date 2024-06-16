#include <stdio.h>


int countDigit(int n, int k, int c) {
    if (n == 0) return c;
    if (k == n % 10) ++c;
    return countDigit(n / 10, k, c);
}


int main() {
    int n = 32281730;
    int k = 2;
    int c = countDigit(n, k, 0);
    printf("Number of appearences of %d in %d: %d\n", k, n, c);
    return 0;
}