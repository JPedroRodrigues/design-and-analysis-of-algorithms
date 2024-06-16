#include <stdio.h>

void print(int *a, int n) {
    printf("[%2d", a[0]);
    for (int i = 1; i < n; i++) printf(", %2d", a[i]);
    printf("]\n");
}


void printMatrix(int **a, int l, int c) {
    for (int i = 0; i < l; i++) print(a[i], c);
}