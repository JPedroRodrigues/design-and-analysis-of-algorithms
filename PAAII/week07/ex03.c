#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


int findGreater(int *a, int l, int r) {
    if (l == r) return a[l];

    int m = (l + r) / 2;
    int left = findGreater(a, l, m);
    int right = findGreater(a, m + 1, r);

    if (left > right) return left;
    else return right;
}


int elegantSum(int *values, int *permutation, int n, int i, int *used, int sum) {
    if (i == n) {
        int fineSum = 0;
        for (int j = 0; j < n - 1; j++) 
            fineSum += abs(permutation[j] - permutation[j + 1]);

        printf("Sum = %d\n\n", fineSum);
        if (fineSum > sum) return fineSum;
        else return sum;
    }
    int fine = 0;
    for (int j = 0; j < n; j++) {
        if (!used[values[j]]) {
            ++used[values[j]];
            
            permutation[i] = values[j];

            sum = elegantSum(values, permutation, n, i + 1, used, sum);
            
            --used[values[j]];
        }
    }
    return sum;
}


int main() {
    int n = 4;

    int values[] = {4, 2, 1, 5};

    int *used = (int *) calloc(findGreater(values, 0, n) + 1, sizeof(int));

    int *permutation = (int *) calloc(n, sizeof(int));

    int elegant = elegantSum(values, permutation, n, 0, used, 0);
    printf("Elegant permutation sum = %d\n", elegant);

    free(permutation);
    return 0;
}