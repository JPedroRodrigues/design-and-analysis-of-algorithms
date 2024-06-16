#include <stdio.h>

int lexicographicSequence(int r[], int j, int s[], int k) {
    int n = j > k ? k : j;

    for (int i = 0; i < n; i++) {
        if (r[i] < s[i]) return 1;
        else if (r[i] > s[i]) return -1;
    }

    if (j == k) return 0;
    else if (j > k) return -1;
    else return 1;
}

int main() {
    int r[] = {1, 2, 3, 4, 5, 6, 7};
    int j = 7;

    int s[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 7;

    int n = lexicographicSequence(r, j, s, k);

    if (n == 1) printf("r[] < s[]\n");
    else if (n == 0) printf("r[] = s[]\n");
    else printf("r[] > s[]\n");
    
    return 0;
}