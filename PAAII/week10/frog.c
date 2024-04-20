#include <stdio.h>
#include <stdlib.h>

void print(int *a, int n) {
    printf("[%d", a[0]);
    for (int i = 1; i < n; i++) printf(", %d", a[i]);
    printf("]\n");
}


int *frog (int *rocks, int n, int delta, int *ls) {
    int *s = (int *) malloc(n * sizeof(int));

    int rock = rocks[0];
    s[0] = rock;
    *ls = *ls + 1;

    // 1 2 3 5 6 7
    // rock: 1
    // rocks[i] = 2, 3, 5 (5 - 1 > 2) -> rock = rocks[i - 1]
    // s = {1, 3}

    // rock: 3
    // rocks[i] = 6 (6 - 3 > 2) -> rock = rocks[i - 1]
    // rocks s[] = {1, 3, 5}

    // rock: 5
    // rocks[i] = 7, end -> s[] = rocks[n - 1]
    // s[] = {1, 3, 5, 7}

    for (int i = 1; i < n; i++) {
        if (rocks[i] - rock > delta) {
            rock = rocks[i - 1];
            s[*ls] = rock;
            *ls = *ls + 1;
        }
    }
    if (rocks[n - 1] - rock <= delta ) {
        s[*ls] = rocks[n - 1];
        *ls = *ls + 1;
    } else printf("This frog will never reach the end.\n");
    return s;
}


int main() {
    int n = 6;
    int rocks[] = {1, 2, 3, 5, 6, 7};
    int delta = 2;
    
    printf("Number of rocks: %d\n", n);
    printf("Distance between rocks: ");
    print(rocks, n);
    printf("Maximum distance a frog can jump: %d\n", delta);

    int ls = 0;
    int *s = frog(rocks, n, delta, &ls);

    printf("Result: ");
    print(s, ls);

    return 0;
}