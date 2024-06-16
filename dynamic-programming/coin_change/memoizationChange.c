#include <stdio.h>
#include <stdlib.h>

#define INFINITY 1000000

int *memo;

void print(int *a, int n) {
    printf("[%d", a[0]);
    for (int i = 1; i < n; i++) printf(", %d", a[i]);
    printf("]\n");
}


int min(int x, int y) { return x < y ? x : y; }


int coins(int change, int *values, int n) {
    // if the change is zero, then there's no coin to use
    if (change == 0) return 0;
    // if the change is less than zero, then there's no solution at all
    if (change < 0) return INFINITY;
    // if the change was previously calculated, the return its value
    if (memo[change] != -1) return memo[change];

    // if the change is greater than zero, then we'll take the minimum number of coins to use
    int minimum = INFINITY;
    
    for (int i = 0; i < n; i++) {
        minimum = min(minimum, coins(change - values[i], values, n) + 1);
    }

    return memo[change] = minimum;
}   


int main() {
    int n = 3;
    int values[] = {1, 4, 6};
    int change = 8;

    memo = (int *) malloc((change + 1) * sizeof(int));
    for (int i = 0; i <= change; i++) memo[i] = -1;

    printf(">> Top down coin change problem\n");
    printf("Coins: ");
    print(values, n);
    printf("For a change of %d, just %d coins are needed.\n", change, coins(change, values, n));

    return 0;
}