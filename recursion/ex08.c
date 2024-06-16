#include <stdio.h>


int p(int c[], int n, int x) {
    if (n == 0) return c[0];
    return p(c, n - 1, x) * x + c[n];
}


int main() {
    int c[] = {4, 3, 2, 1};
    int n = 3, x = 10;
    printf("Result from polynomial: %d\n", p(c, n, x));
    return 0;
}