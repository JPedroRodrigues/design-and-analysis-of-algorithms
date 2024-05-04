#include <stdio.h>
#include <stdlib.h>

int max(int x, int y) {
    return x > y ? x : y;
}


int lis(int *a, int n) {
    int *l = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) l[i] = 1;
    
    int longest = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) l[i] = max(l[i], l[j] + 1);
        }
        longest = max(longest, l[i]);
    }
    free(l);
    return longest;
}


int main() {
    int a[] = {8, 7, 11, 4, 5, 1, 9, 10, 6, 3};
    int n = 10;

    printf("Longest Increasing Sequence: %d\n", lis(a, n));

    return 0;
}