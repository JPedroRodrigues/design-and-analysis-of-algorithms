#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int *createArray(int n) {
    int* v = (int *) calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Valor para %dª posição: ", i + 1);
        scanf("%d", &v[i]);
    }
    return v;
}


double median(int *v, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }
    return (double) sum / n;
}


double var(int *v, int n) {
    double term = 1.0 / (n - 1);
    double sum = 0;
    double med = median(v, n);

    for (int i = 0; i < n; i++) {
        sum += (v[i] - med) * (v[i] - med);
    }
    return (term * sum);
}


double standardDeviation(int *v, int n) {
    return sqrt(var(v, n));
}


int main() {
    int qt;

    printf("Quantidade de números: ");
    scanf("%d", &qt);

    int *v = createArray(qt);

    printf("Média dos valores: %f\n", median(v, qt));
    printf("Variância: %f\n", var(v, qt));
    printf("Desvio padrão: %f\n", standardDeviation(v, qt));

    free(v);
    return 0;
}