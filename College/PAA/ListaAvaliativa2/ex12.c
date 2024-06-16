#include <stdio.h>


int merge(int a[], int l, int m, int r) {
    int b[r];
    int c = 0;
    
    for (int i = l; i <= m; ++i) b[i] = a[i];
    for (int j = m + 1; j <= r; ++j) b[r + m + 1 - j] = a[j];

    int i = l;
    int j = r;
    
    for (int k = l; k <= r; ++k) {
        if (b[i] <= b[j]) {
            a[k] = b[i];
            ++i; 
        } else {
            a[k] = b[j];
            --j;
            printf("Os elementos %d e %d, com índices %d e %d, formam uma inversão......\n", a[i], b[j], i, j);
            c += (m - i + 1);
        }
    }  

    return c;
}


int mergeSort(int a[], int l, int r, int c) {

    if (l < r) {
        int m = (r + l) / 2;
        mergeSort(a, l, m, c);
        mergeSort(a, m + 1, r, c);
        c += merge(a, l, m, r);
    }
    return c;
}


int main () {

    int a[] = {1, 3, 5, 2, 4, 6};
    int n = 6;
    int c = 0;

    c = mergeSort(a, 0, n, c);
    printf("Count = %d\n", c);

    return 0;
}
