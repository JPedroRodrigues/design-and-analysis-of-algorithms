#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int countDigits(char n[], char dgt) {
    int count = 0;
    for (int i = 0; i < strlen(n); i++) {
        if (dgt == n[i]) count++;
    }
    return count;
}

bool isPermutation(char n1[], char n2[]) {
    if (strlen(n1) != strlen(n2)) return false;

    for (int i = 0; i < strlen(n1); i++) {
        for (int j = 0; j < strlen(n2); j++) {
            if (countDigits(n1, n2[j]) == 0 || countDigits(n2, n1[i]) == 0) return false;
            else if(n1[i] == n2[j] && countDigits(n1, n1[i]) != countDigits(n2, n2[j])) return false;
        }
    }
    return true;
}


int main() {
    char n1[10], n2[10];
    printf("Número N1: "); scanf("%s", n1);
    printf("Número N2: "); scanf("%s", n2);

    if (isPermutation(n1, n2)) printf("%s é permutação de %s.\n", n1, n2);
    else printf("%s NÃO é permutação de %s.\n", n1, n2);

    return 0;
}