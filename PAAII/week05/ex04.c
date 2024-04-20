#include <stdio.h>
#include <stdbool.h>


bool isSegment(int s[], int k, int a[], int n) {
    int j = 0;
    bool flag = false;

    for (int i = 0; i < n; i++) {
        if (s[j] == a[i] && j < k) {
            j++;
            flag = true;
        } else if (flag && s[j] != a[i] && j < k) return false;
    }
    return true;
}


void printArray(int a[], int n) {
    printf("[%d", a[0]);
    for (int i = 1; i < n; i++) printf(", %d", a[i]);
    printf("]\n");
}


int main() {
    int s[] = {1, 5, 7};
    int k = 3;

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;

    printf("s = ");
    printArray(s, k);

    printf("a = ");
    printArray(a, n);

    if (isSegment(s, k, a, n)) printf("s[] is segment of a[]\n");
    else printf("s[] is not segment of a[].\n");

    return 0;
    return 0;
}