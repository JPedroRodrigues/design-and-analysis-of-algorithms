#include <stdio.h>
#include <stdbool.h>

bool subsequence(int s[], int k, int a[], int n) {
    int i = 0;
    int j = 0;

    while (i < k && j < n) {
        if (s[i] == a[j]) {
            i++;
            j++;
        } else j++;
    }

    if (i != k) return false;
    else return true;
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
    
    if (subsequence(s, k, a, n)) printf("s[] is a subsequence of a[]\n");
    else printf("s[] is not a subequence of a[].\n");
    
    return 0;
}