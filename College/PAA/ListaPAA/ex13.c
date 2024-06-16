#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

bool inFareySequence(int numerator[], int denominator[], int n, int num, int dem) {
    for (int i = 0; i < n; i++) {
        if ((float) num / dem == (float) numerator[i] / denominator[i]) {
            return true;
        }
    }
    return false;
}


int fareySequence(int numerator[], int denominator[], int n) {
    int index = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (((float) i / j) < 1 && !inFareySequence(numerator, denominator, index, i, j)) {
                numerator[index] = i;
                denominator[index] = j;
                index++;
            }
        }
    }
    return index;
}


int swap(int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}


void bubbleSortFarey(int numerator[], int denominator[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if ((float) numerator[j] / denominator[j] > (float) numerator[j + 1] / denominator[j + 1]) {
                swap(numerator, j, j + 1);
                swap(denominator, j, j + 1);
            }
        }
    }
}


void printArray(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(", %d", v[i]);
    }
}


int main() {
    int n;
    printf("Número de elementos da sequência de Farey: "); scanf("%d", &n);

    int numerator[SIZE];
    int denominator[SIZE];
    int size = fareySequence(numerator, denominator, n);
    bubbleSortFarey(numerator, denominator, size);

    printf("Sequência de Farey relativa a %d: 0/1", n);
    
    for (int i = 0; i < size; i++) {
        printf(", %d/%d", numerator[i], denominator[i]);
    }
    printf(", 1/1\n");

    return 0;
}