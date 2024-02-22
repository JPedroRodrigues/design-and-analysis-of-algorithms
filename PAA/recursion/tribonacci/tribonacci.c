#include <stdio.h>

int tribonacci (int n) {
    if (n == 0 || n == 1) return 0;
    else if (n == 2) return 1;
    else return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}

int main() {
    int element = tribonacci(10);
    printf("%d\n", element);
    return 0;
}