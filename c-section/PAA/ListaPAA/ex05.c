#include <stdio.h>
#include <stdbool.h>
#include <math.h>

float sqrtLim(float n0) {
    float ni = n0 / 2;
    float newNi;
    
    while (true) {
        newNi = (pow(ni, 2) + n0) / (2.0 *  ni);

        if ((ni - newNi) < 0.00001) return newNi;

        ni = newNi;
    }
}

int main() {
    float n;
    printf("Digite um número: "); scanf("%f", &n);
    printf("Raiz de %.2f: %.2f\n", n, sqrtLim(n));
    return 0;
}