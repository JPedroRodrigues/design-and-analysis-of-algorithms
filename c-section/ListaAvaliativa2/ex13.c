#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


int split(int a[], int l, int r) {
    if (a[(l + r)/2] > a[l]) swap(&a[(l + r)/2], &a[l]);
    if (a[r] > a[l]) swap(&a[r], &a[l]);
    if (a[r] > a[(l + r)/2]) swap(&a[r], &a[(l + r)/2]);

    swap(&a[r], &a[(l + r) / 2]);

    int x = a[r];
    int i = l - 1;
    //int c = ((l + r) / 2) + 1;

    for (int j = l; j < r; ++j) {
        if (a[j] <= x) {
            ++i;
            swap(&a[i], &a[j]);
        } 
    }
    swap(&a[i + 1], &a[r]);
    return i + 1;
}


void quickSort(int a[], int l, int r) {
    if (l >= r) return;

    int m = split(a, l, r);
    quickSort(a, l, m - 1);
    quickSort(a, m + 1, r);
}


void printArray(int a[], int n) {
    printf("Array = [%d", a[0]);
    for (int i = 1; i < n; ++i) printf(", %d", a[i]);
    printf("]\n");
}


int main() {
    int n;
    srand(time(NULL));

    printf("Array's size: ");
    scanf("%d", &n);

    int *a = (int *) calloc(n, sizeof(int));

    for (int i = 0; i < n; ++i) a[i] = rand() % 100;
    printArray(a, n);

    quickSort(a, 0, n - 1);
    printArray(a, n);

    free(a);
    return 0;
}
