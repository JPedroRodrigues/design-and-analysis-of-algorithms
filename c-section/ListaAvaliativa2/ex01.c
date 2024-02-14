#include <stdio.h>

void binary(int n) {
    if (n == 0) return;

    binary(n / 2);
    printf("%d", n % 2);
}


int main() {

    int n;
    do {
        printf("Enter a number: ");
        scanf("%d", &n);

        if (n < 0) printf("Invalid number. It must be a positive number.");

    } while (n < 0);

    if (n == 0) printf("%d\n", n);
    else { binary(n); printf("\n"); }

    return 0;
}
