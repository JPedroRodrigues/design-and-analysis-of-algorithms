#include <stdio.h>

int increasingMaximum(int a[], int n) {
    int count = 0, max = 0;

    for (int i = 0;  i < n - 1; i++) {
        if(a[i] <= a[i + 1]) ++count;
        else {
            ++count;
            max = max < count? count : max;
            count = 0;
        }
    }
    return max;
}


void print(int a[], int n) {
    printf("[%d", a[0]);
    for (int i = 1; i < n; i++) printf(", %d", a[i]);
    printf("] ");
}


int main() {
    int a[] = {5, 10, 3, 2, 4, 7, 9, 8, 5};
    int len = sizeof(a) / sizeof(int);

    printf("Na sequência ");
    print(a, len);
    printf("o comprimento do segmento crescente máximo é %d.\n", increasingMaximum(a, len));

    return 0;
}