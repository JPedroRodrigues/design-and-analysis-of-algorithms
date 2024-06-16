#include <stdio.h>
#include <stdlib.h>

#define INFINITY 1000000


void print(int *a, int n) {
    printf("[%d", a[0]);
    for (int i = 1; i < n; i++) printf(", %d", a[i]);
    printf("]\n");
}


int min(int x, int y) { return x < y ? x : y; }


int coins(int change, int *values, int n) {
    int *coin = (int *) calloc((change + 1), sizeof(int));
    for (int i = 1; i <= change; i++) coin[i] = INFINITY;

    for (int i = 1; i <= change; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= values[j]) 
                coin[i] = min(coin[i], coin[i - values[j]] + 1);
        }
    }
    return coin[change];
}   


int main() {
    int n = 3;
    int values[] = {1, 4, 6};
    int change = 8;

    printf(">> Bottom Up coin change problem\n");
    printf("Coins: ");
    print(values, n);
    printf("For a change of %d, just %d coins are needed.\n", change, coins(change, values, n));

    return 0;
}