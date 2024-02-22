#include <stdio.h>

void printArray(int v[], int n) {
    printf("Array = [%d", v[0]);
    for (int i = 1; i < n; i++) printf(", %d", v[i]);
    printf("]\n");
}

void swap(int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void recursiveSelection(int v[], int n) {
    if (n > 0) {
        int min = n;
        for (int j = 0; j < n; j++) {
            if (v[j] > v[min]) {
                min = j;
            }
        }
        swap(v, min, n);
    
        recursiveSelection(v, n - 1);
    }
}

int main() {
    int v[] = {5, 4, 2, 1, 7, 3, 9, 10, 8, 6};

    recursiveSelection(v, 9);
    printArray(v, 10);

    return 0;
}