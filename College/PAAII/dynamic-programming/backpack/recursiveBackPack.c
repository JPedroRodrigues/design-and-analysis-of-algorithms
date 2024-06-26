#include <stdio.h>

int n = 4;
int items[] = {1, 2, 3, 4};
int weights[] = {3, 2, 4, 1};
int values[] = {8, 3, 9, 6};


int max(int x, int y) { return x > y ? x : y; }


int backPack(int n, int W) {
    if (n - 1 < 0 || W <= 0) return 0;
    else if (weights[n - 1] > W) return backPack(n - 1, W);
    else return max(backPack(n - 1, W), backPack(n - 1, W - weights[n - 1]) + values[n - 1]);
}


int main() {
    int w = 5;

    printf("Recursive backpack problem: backPack(%d, %d) = %d\n", n, w, backPack(n, w));

    return 0;
}