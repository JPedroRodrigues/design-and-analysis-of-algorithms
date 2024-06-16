#include <stdio.h>
#include <stdlib.h>

int *memo;

int fib(int n) {
    if (memo[n] != -1) return memo[n];
    else if (n == 0 || n == 1) return memo[n] = n;
    else return memo[n] = fib(n - 1) + fib(n - 2);
}


int main() {
    int n = 10;
    
    memo = (int *) malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n + 1; i++) memo[i] = -1;

    printf("Memoization: fib(%d) = %d\n", n, fib(n));
    
    free(memo);
    return 0;
}