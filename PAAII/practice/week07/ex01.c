#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


void binaryNumber(int binary[], int i, int n1, int values[], int n2) {
    if (i == n1) print(binary, n1);
    else {
        for (int j = 0; j < n2; j++) {
            binary[i] = values[j];

            binaryNumber(binary, i + 1, n1, values, n2);
        }
    }
}


int main(void) {
    int n = 3;
    int n2 = 2;
    int *binary = (int *)calloc(n, sizeof(n));
    int values[] = {0, 1};

    binaryNumber(binary, 0, n, values, n2);

    free(binary);
    
    return 0;
}