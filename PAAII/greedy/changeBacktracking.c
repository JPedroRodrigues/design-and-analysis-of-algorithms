#include <stdio.h>
#include <stdlib.h>

void print(int *a, int n) {
    printf("[%d", a[0]);
    for (int i = 1; i < n; i++) printf(", %d", a[i]);
    printf("]\n");
}


int *changeBacktracking(int change, int *coins, int lc, int *p, int  i, int *s, int *ls) {
    if (change == 0) {
        if (i < *ls) {
            *ls = i;
            for (int j = 0; j < *ls; j++) s[j] = p[j];
            return s;
        }
    }

    for (int j = lc - 1; j >= 0; j--) {
        if (coins[j] <= change) {
            p[i] = coins[j];
            s = changeBacktracking(change - p[i], coins, lc, p, i + 1, s, ls);
        }
    }
    return s;
}


int main() {
    int change = 8;
    int coins[] = {1, 4, 6};
    int lc = sizeof(coins) / sizeof(int);

    int *s = (int *) calloc(change, sizeof(int));
    int *p = (int *) calloc(change, sizeof(int));
    int ls = 8;

    s = changeBacktracking(change, coins, lc, p, 0, s, &ls); 

    print(s, ls);

    free(s);
    free(p);

    return 0;
}