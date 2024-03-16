#include <stdio.h>
#include <stdlib.h>

void print(int *a, int n) {
    printf("[", a[0]);
    for (int i = 0; i < n; i++) {
        if (i == 0) printf("%d", a[0]);
        else printf(", %d", a[i]);
    }
    printf("]");
}


void getSubset(int *set, int n, int *subset, int i, int *used) {
    if (i == n) return;
    else if (i == 0) printf("[]");

    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            used[j] = 1;
            if (i == 0) {
                subset[i] = set[j];

                printf(", ");
                print(subset, i + 1);
            }
            else if (set[j] > subset[i - 1]) {
                subset[i] = set[j];

                printf(", ");
                print(subset, i + 1);
            }

            getSubset(set, n, subset, i + 1, used);
            used[j] = 0;
        }
    }
}


int main() {
    int n = 3;

    int *set = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) set[i] = i + 1;

    int *subset = (int *) calloc(n, sizeof(int));
    int *used = (int *) calloc(n, sizeof(int));

    printf("Subsets of A = ");
    print(set, n);
    printf(": ");
    getSubset(set, n, subset, 0, used);
    printf("\n");

    free(set);
    free(subset);
    free(used);

    return 0;
}