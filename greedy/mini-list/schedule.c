/*
This program calculates the maximum number of reservations that can be made in a restaurant within certain intervals. Only one reservation can be made per interval.
Example:
Input:
5
1 2
2 3
3 4
4 5
5 6
Output: 3
*/

#include <stdio.h>
#include <stdlib.h>


int maxOrders(int n, int *s, int *f) {
    // Number of orders
    int orders = 1;
    // Index of check-out time
    int i = 0;
    // Index of check-in time
    int j = 1;

    while (i <= n) {
        if (s[i] > f[j]) {
            ++orders;
            j = i;
        }
        ++i;
    }
    return orders;
}


int main() {
    
    // Number of reservations
    int n;
    scanf("%d", &n);

    // Arrays that contain the check-in and check-out time of each reservation
    int *start = (int *) malloc(n * sizeof(int));
    int *finish = (int *) malloc(n * sizeof(int));

    // Read and store the check-in and check-out time of each reservation
    for (int i = 0; i < n; ++i) scanf("%d %d", &start[i], &finish[i]);
    
    // Function to calculate the maximum number of reservations that can be made
    int ans = maxOrders(n, start, finish);

    printf("=== PROBLEM 2 ===\n");
    printf("%d\n", ans);

    // Free dynamically allocated memory
    free(start); free(finish);

    return 0;
}
