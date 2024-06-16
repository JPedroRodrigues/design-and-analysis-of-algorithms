#include <stdio.h>

void iterativeReverse(int a[], int n) {
    for (int i = 0; i < n / 2; ++i) {
        int temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}


void recursiveReverse(int a[], int n, int i) {
    if (i == n / 2) return;
    int temp = a[i];
    a[i] = a[n - i - 1];
    a[n - i - 1] = temp;
    recursiveReverse(a, n, i + 1);
    
}


void reverseTwoPointers(int a[], int n, int i, int j) {
    if (i == n / 2) return;
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    reverseTwoPointers(a, n, i + 1, j - 1);
}


void printArray(int a[], int n) {
    printf("Array = [%d", a[0]);
    for (int i = 1; i < n; i++) printf(", %d", a[i]);
    printf("]\n");
}


int main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = 5;
    printArray(a, n);

    // recursiveReverse(a, n, 0);
    reverseTwoPointers(a, n, 0, n - 1);
    printArray(a, n);
    return 0;
}