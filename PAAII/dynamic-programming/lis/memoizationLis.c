#include <stdio.h>
#include <stdlib.h>

int *memo;

int max(int x, int y) { 
    return x > y ? x : y; 
}


int lis(int *a, int i, int longest) {
    if (memo[i] != -1) return memo[i];
    else if (i == 0) return memo[i] = 1;

    longest = 1;
    for (int j = 0; j <= i; j++) {
        if (a[j] < a[i]) longest = max(longest, lis(a, j - 1, longest) + 1);
    }
    return memo[i] = longest;
}


int main() {
    int a[] = {8, 7, 11, 4, 5, 1, 9, 10, 6, 3};
    int n = 10;

    memo = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) memo[i] = -1;

    printf("Longest Increasing Sequence: %d\n", lis(a, n - 1, 1));

    free(memo);
    return 0;
}