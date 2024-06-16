/*
This program calculates the minimum number of K factorials whose sum corresponds to a number N.
Example:
Input: 10
Output: 3
Explanation: 10 = 3! + 2! + 2!
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int* candidates;

void print(int *a, int n) {
    printf("%d!", a[0]);
    for (int i = 1; i < n; i++) printf(" + %d!", a[i]);
    printf("\n");
}


int fat(int n) {
    int ans = 1;
    for (int i = n; i > 0; --i) ans *= i;
    return ans;
}


int fatSum(int n) {
    int candidate = n / 2;
    int sum, i, ans;
    sum = i = ans = 0;
    
    candidates = (int *) calloc((n / 2) + 1, sizeof(int));

    while (sum < n) {
        if (sum + fat(candidate) <= n) {
            sum += fat(candidate);
            candidates[i++] = candidate;
        }
        else candidate--;        
    }
    // return the number of factorials used to calculate the sum
    return i;
}


int main() {
    // First test
    int x = 5;  // 5 = 2! + 2! + 1!

    printf("=== PROBLEM 1 ===\n");

    int ans1 = fatSum(x);
    printf("%d = ", x);
    print(candidates, ans1);

    // Second test
    int y = 10;  // 10 = 3! + 2! + 2!
    int ans2 = fatSum(y);
    printf("%d = ", y);
    print(candidates, ans2);

    return 0;
}
