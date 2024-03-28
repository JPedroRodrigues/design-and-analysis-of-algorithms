#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void backSort(int sort[], int i, int n, int a[], int used[]) {
    if (i == n) print(sort, n);
    else {
        for (int j = 0; j < n; j++) {
            if (!used[j] && (i == 0 || i > 0 && a[j] > sort[i - 1])) {
                used[j] = 1;

                sort[i] = a[j];
                backSort(sort, i + 1, n, a, used);

                used[j] = 0;
            }
        }
    }
}


int main() {
    int n = 5;
    
    int a[] = {5, 2, 1, 3, 4};
    int *sort = (int *) calloc(n, sizeof(int));
    int *used = (int *) calloc(n, sizeof(int));

    backSort(sort, 0, n, a, used);

    return 0;
}