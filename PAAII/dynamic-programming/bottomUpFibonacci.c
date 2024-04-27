#include <stdio.h>


int fib(int n) {
    int a = 0, b = 1, c = 0;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}


int main() {
    int n = 10;
    printf("Bottom-up: fib(%d) = %d\n", n, fib(n));
    return 0;
}