#include <stdio.h>


int findGreater(int a[], int l, int r) {
    if (l == r) return a[l];
    int m = (l + r) / 2;
    int x = findGreater(a, l, m);
    int y = findGreater(a, m + 1, r);
    if (x > y) return x;
    else return y;
}


int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 9, 10};
    int n = 10;

    int greater = findGreater(a, 0, n);
    printf("Greatest number: %d\n", greater);
    return 0;
}