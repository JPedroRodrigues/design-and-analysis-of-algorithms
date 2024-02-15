#include <stdio.h>


int oddSum(int n) {
    if (n == 1) return 1;
    return 2 * n - 1 + oddSum(n - 1);
}


int main() {
    int n; 
    
    printf("Quantidade de números: ");
    scanf("%d", &n);

    printf("Soma dos %d números: %d\n", n, oddSum(n));
    
    return 0;
}