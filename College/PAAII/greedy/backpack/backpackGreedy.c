#include <stdio.h>
#include <stdlib.h>

void print(float *a, int n) {
    printf("[%.2f", a[0]);
    for (int i = 1; i < n; i++) printf(", %.2f", a[i]);
    printf("]\n");
}


void swap(float *a, float *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void recursiveBubble(float *v, float *w, int n) {
    if (n == 0) return;

    for (int i = 0; i < n - 1; ++i) {
        if (v[i] / w[i] > v[i + 1] / w[i + 1]) {
            swap(&v[i], &v[i + 1]);
            swap(&w[i], &w[i + 1]);
        }
        recursiveBubble(v, w, n - 1);
    }
}


void backpack(float *w, float *v, int n, float capacity) {
    float *x = (float *) calloc(n, sizeof(float));
    int lenX = 0;

    int i = 0;

    while (i < n && capacity > 0) {
        if (w[i] <= capacity) {
            x[lenX++] = 1;
            capacity -= w[i];
            i++;
        } else {
            x[lenX++] = capacity / w[i];
            capacity = 0;
        }
    }
    printf("\nBag's capacity: ");
    print(x, lenX);

    free(x);
}


int main() {
    float values[] = {100.0, 60.0, 120.0};
    float weight[] = {20.0, 10.0, 30.0};
    float capacity = 50.0;

    int n = 3;

    recursiveBubble(weight, values, n);

    printf("Values: ");
    print(values, n);
    printf("\nWeight: ");
    print(weight, n);

    backpack(weight, values, n, capacity);

    return 0;
}