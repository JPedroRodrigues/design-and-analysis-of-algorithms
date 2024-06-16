#include <stdio.h>
#include <stdlib.h>

int **c;
char **b;


void printIntArr(int *a, int n) {
    printf("[%d", a[0]);
    for (int i = 1; i < n; i++) printf(", %d", a[i]);
    printf("]\n");
}


void printCharArr(char *a, int n) {
    printf("[%c", a[0]);
    for (int i = 1; i < n; i++) printf(", %c", a[i]);
    printf("]\n");
}


void printIntMatrix(int **m, int r, int c) {
    for (int i = 0; i < r; i++) {
        printIntArr(m[i], c);
    }
}

void printCharMatrix(char **m, int r, int c) {
    for (int i = 0; i < r; i++) {
        printCharArr(m[i], c);
    }
}


int max(int x, int y) { return x > y ? x : y; }


int lcs(char *x, char *y, int i, int j, int **c, char **b) {
    if (i == 0 || j == 0) return 0;
    else if (x[i - 1] == y[j - 1]) return c[i][j] = lcs(x, y, i - 1, j - 1, c, b) + 1;
    else return c[i][j] = max(lcs(x, y, i - 1, j, c, b), lcs(x, y, i, j - 1, c, b));
}


void printLcs(char **b, char *x, char *y, int i, int j) {
    if (i == 0 || j == 0) return;
    if (b[i][j] == 'd') {
        printLcs(b, x, y, i - 1, j - 1);
        printf("%c", x[i - 1]);
    } else if (b[i][j] == 'u') printLcs(b, x, y, i - 1, j);
    else printLcs(b, x, y, i, j - 1);
}


int main() {
    char *x = "ABCBDAB";
    char *y = "BDCABA";

    int lx = 8, ly = 7;

    c = (int **) calloc(lx, sizeof(int *));
    b = (char **) malloc(lx * sizeof(char *));

    for (int i = 0; i < lx; i++) {
        b[i] = (char *) malloc(ly * sizeof(char));
        c[i] = (int *) calloc(ly, sizeof(int));
    }

    lcs(x, y, lx - 1, ly - 1, c, b);

    printf("Backtracking:\n");
    printf("- Lenght of the sequence: %d\n", c[lx - 1][ly - 1]);
    // printf("Longest Common Sequence: ");
    // printLcs(b, x, y, lx - 1, ly - 1);
    // printf("\n");

    for (int i = 0; i < lx; i++) {
        free(b[i]);
        free(c[i]);
    }

    free(b); free(c);
    return 0;
}