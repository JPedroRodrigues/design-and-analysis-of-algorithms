#include <stdio.h>

void printArray(int v[], int n) {
    printf("Array = [%d", v[0]);
    for (int i = 1; i < 10; i++) printf(", %d", v[i]);
    printf("]\n");
}

void recursiveInsertion(int v[], int n) {
    if (n == 1) return;
    
    recursiveInsertion(v, n - 1);
    
    int key = v[n];
    int i = n - 1;
    while (i >= 0 && v[i] > key) {
        v[i + 1] = v[i];
        i--;
    }
    v[i + 1] = key;

    // Caso a chamada estivesse aqui embaixo,
    // Deveria existir uma variável j iniciada em 0
    // De modo que ela seja incrementada a cada chamada
    // Até que se iguale a n
    // Os valores dos vetores são obtidos em função de j
    // recursiveInsertion(v, j + 1);
}

int main(void) {
    int v[] = {5, 4, 2, 1, 7, 3, 9, 10, 8, 6};
    int n = 9;
    
    recursiveInsertion(v, n);
    printArray(v, n);
    
    return 0;
}