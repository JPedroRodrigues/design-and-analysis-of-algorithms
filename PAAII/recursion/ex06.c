#include <stdio.h>

int greaterElement(int a[], int n, int greater) {
    if (n == 0) {
        if (a[0] > greater) return a[0];
        return greater;
    }

    if (a[n] > greater) greater = a[n];
    return greaterElement(a, n - 1, greater);
}

// professor's code
int ge(int a[], int i) {
    if (i == 0) return a[0];
    else {
        int greater = ge(a, i - 1);
        if (greater > a[i]) return greater;
        else return a[i];
    }
}

int main() {
    int a[] = {7, 3, 6, 8, 4, 7, 3};
    int n = 7;

    printf("Greater element: %d\n", greaterElement(a, n, a[0]));
    return 0;
}