#include <stdio.h>
#include <stdbool.h>


bool lexicographicSequence(int r[], int j, int s[], int k) {
    int n = j > k ? k : j;

    for (int i = 0; i < n; i++) {
        if (r[i] < s[i]) return true;
        else if (r[i] > s[i]) return false;
    }

    if (j >= r) return false;
    else return true;
}


void printArray(int a[], int n) {
    printf("[%d", a[0]);
    for (int i = 1; i < n; i++) printf(", %d", a[i]);
    printf("]\n");
}


int main(void) {
    int r[] = {1, 2, 8, 4, 5, 6};
    int j = 6;
    
    int s[] = {1, 2, 3};
    int k = 3;

    printf("r = ");
    printArray(r, j);

    printf("s = ");
    printArray(s, k);
    
    if (lexicographicSequence(r, j, s, k)) printf("r < s");
    else printf("\nr[] is not less than s[]\n");
        
    return 0;
}