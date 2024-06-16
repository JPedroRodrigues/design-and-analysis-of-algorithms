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


// /* Lógica:
// *    - Empurro o maior para o final
// *    - Decremento o tamanho do vetor
// */
void bubbleRecursivo(int v[], int n) {
    if (n == 0) {
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) swap(v, i, i + 1);
    }

    bubbleRecursivo(v, n - 1);
}


int main(void) {
    int v[] = {4, 6, 1, 2, 5};
    int n = 5;
    bubbleRecursivo(v, n);
    printArray(v, n);
    return 0;
}