#include <stdio.h>


float fat(int n) {
    if (n == 0) return 1;
    return n * fat(n - 1);
}

float power(int n, int exp) {
    if (exp == 0) return 1;
    return n * power(n, exp - 1);
}


float sum(int x, int n) {
    if (n == 0) return 1;
    return (power(x, n) / fat(n)) + sum(x, n - 1);
}


int main() {
    int n;
    printf("Número n: "); scanf("%d", &n);

    int exp;
    printf("Expoente: "); scanf("%d", &exp);

    printf("Somatoria (%d, %d): %.3f\n", n, exp, sum(n, exp));
    
    return 0;
}