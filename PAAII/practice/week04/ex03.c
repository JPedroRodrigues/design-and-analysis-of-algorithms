#include <stdio.h>

int bitonicArray(int a[], int l, int r) {
    if (l == r) return a[l];

    int m = (l + r) / 2;
    int x = bitonicArray(a, l, m);
    int y = bitonicArray(a, m + 1, r);
    
    if (x > y) return x;
    else return y;
}

int main() {
    int a[] = {6, 9, 12, 7, 2, 1};
    int l = 0, r = 5;

    printf("Greatest number: %d\n", bitonicArray(a, l, r));
    return 0;
}