#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


int split(int a[], int l, int r, int k) {
    if (l >= r) return a[k];

    int x = a[r];
    int i = l - 1;
    int m = (l + r) / 2;

    for (int j = l; j < r; ++j) {
        if (a[j] <= x) {
            ++i;
            swap(&a[i], &a[j]);
        } 
    }
    swap(&a[i + 1], &a[r]);

    return split(a, l, m, k);
    return split(a, m + 1, r, k);
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

    int k;

    do {
        printf("Select an element: ");
        scanf("%d", &k);
    } while (k >= n || k < 0);
    

    int element = split(a, 0, n - 1, k);
    printArray(a, n);
    printf("Elemento: %d", element);

    free(a);
    return 0;
}