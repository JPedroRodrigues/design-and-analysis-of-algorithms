#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_CAPACITY 10

int readIntegers(int v[], int size) {
    int i = 0, n;
    while (i < size) {
        printf("Digite um número inteiro: "); scanf("%d", &n);
        if (n != -1) {
            v[i] = n;
            ++i;
        } else break;
    }
    return i;
}


bool isRepeated(int v[], int size, int e) {
    for (int i = 0; i < size; i++) {
        if (e == v[i]) return true;
    }
    return false;
}


void arrayValues(int v[], int size) {
    int *aux = (int *) calloc(size, sizeof(int));
    int j = 0;

    printf("Elementos do vetor:");
    for (int i = 0; i < size; i++) {
        if (!isRepeated(aux, j, v[i])) {
            printf(" %d", v[i]);
            aux[j] = v[i];
            j++;
        }
    }
    printf("\n");
    free(aux);
}


int main() {
    int v[ARRAY_CAPACITY];

    int size = readIntegers(v, ARRAY_CAPACITY);
    arrayValues(v, size);
    
    return 0;
}