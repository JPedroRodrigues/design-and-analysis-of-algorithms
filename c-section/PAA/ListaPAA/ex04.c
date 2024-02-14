#include <stdio.h>

void printTriangle(int lines) {
    int value = 1;
    for (int i = 1; i <= lines; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%02d ", value);
            value++;
        }
        printf("\n");
    }
}


int main() {
    int lines;
    printf("Número de linhas: "); scanf("%d", &lines);
    printf("Triângulo de Floyd:\n");
    printTriangle(lines);
    return 0;
}