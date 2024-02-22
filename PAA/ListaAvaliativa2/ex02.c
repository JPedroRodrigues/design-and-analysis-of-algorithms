#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


int gcdIterative(int x, int y) {
    while ((y > x) || (x % y != 0)) {
        if (x < y) swap(&x, &y);
        else x = x % y;
    }

    return y;
}


int gcdRecursive(int x, int y) {

    if (y <= x && x % y == 0) return y;
    else if (x < y) return gcdRecursive(y, x);
    else return gcdRecursive(y, x % y);
}

int main() {

    int x, y;

    printf("Enter the value of X: ");
    scanf("%d", &x);

    printf("Enter the value of Y: ");
    scanf("%d", &y);

    // gcd = greatest common divisor
    printf("%d\n", gcdRecursive(x, y));
    printf("%d\n", gcdIterative(x, y));

    return 0;
}
