#include <stdio.h>

int findBitonicMax(int a[], int l, int r) {
    int m = (l + r) / 2;
    if (a[m] > a[m - 1] && a[m] > a[m + 1] || m == 0) return a[m];
    else if (a[m] < a[m + 1]) return findBitonicMax(a, m + 1, r);
    else if (a[m] < a[m - 1]) return findBitonicMax(a, l, m - 1);
}


int main() {
    int a[] = {6, 7, 10, 9, 8};
    int l = 0, r = 5;

    printf("Greatest number: %d\n", findBitonicMax(a, l, r));
    return 0;
}