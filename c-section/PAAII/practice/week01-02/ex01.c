#include <stdio.h>


int ab(int a, int b) {
    if (b == 1) return a;
    return ab(a, b - 1) + a;
}


int main(void) {
    int result = ab(5, 6);
    
    printf("Resultado: %d\n", result);
    return 0;
}