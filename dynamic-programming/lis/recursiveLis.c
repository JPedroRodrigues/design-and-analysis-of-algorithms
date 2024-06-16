#include <stdio.h>


int max(int x, int y) {
    return x > y ? x : y; 
}


int lis(int *a, int i, int longest) {
    if (i == 0) return 1;

    longest = 1;
    for (int j = 0; j <= i; j++) {
        if (a[j] < a[i]) longest = max(longest, lis(a, j - 1, longest) + 1);
    }
    return longest;
}

int main() {
    int a[] = {8, 7, 11, 4, 5, 1, 9, 10, 6, 3};
    int n = 10;
    printf("Longest Increasing Sequence: %d\n", lis(a, n - 1, 1));
    return 0;
}