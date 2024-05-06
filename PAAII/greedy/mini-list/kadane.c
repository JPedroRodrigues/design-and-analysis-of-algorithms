// This program calculates the maximum subarray sum in a given array
// Using Kadane's Algorithm - Time Complexity: O(n)

#include <stdio.h>
#define MAXN 50000


int max(int x, int y) { return x > y ? x : y; }


int kadane(int *a, int n) {
    int maximum = a[0];

    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0) {
            a[i] = max(a[i], a[i] + a[i - 1]); 
            maximum = max(maximum, a[i]);
        }
    }
    return maximum;
}


int main() {
    
    // Test 1
    // int a[] = {-2, 5, -1, 8, -11, 7, 3};
    // int n = 7;
    // Output = 12 (5 + (-1) + 8)

    // Test 2
    // int a[] = {50, 42, -35, 2, -60, 5, 30, -1, 40, 31};
    // int n = 10;
    // Output = 105 (5 + 30 + (-1) + 40 + 31)

    int n;
    scanf("%d", &n);

    int a[MAXN];
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int ans = maxLives(a, n);
    printf("=== PROBLEM 3 ===\n");
    printf("%d\n", ans);
    
    return 0;
}
