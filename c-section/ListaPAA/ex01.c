#include <stdio.h>
#include <stdbool.h>

bool isPrimer(int n) {
    if (n == 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n1, n2;
    printf("N1: "); scanf("%d", &n1);
    printf("N2: "); scanf("%d", &n2);

    printf("Números primos entre %d e %d:", n1, n2);
    for (int i = n1; i <= n2; i++) {
        if (isPrimer(i)) printf(" %d", i);
    }
    printf("\n");
    return 0;
}