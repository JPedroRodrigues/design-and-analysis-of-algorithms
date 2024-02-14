#include <stdio.h>
#include <stdlib.h>


void recursiveInsertion(int a[], int n) {
    if (n < 0) return;

    recursiveInsertion(a, n - 1);
    
    int key = a[n];
    int j = n - 1;

    while (j >= 0 && a[j] > key) {
        a[j + 1] = a[j];
        --j;
    }
    a[j + 1] = key;
}


void printArray(int a[], int n) {
    printf("Array = [ %d", a[0]);
    for (int i = 1; i < n; ++i) printf(", %d ", a[i]);
    printf("]\n");
}


int main() {

    int n;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *a = (int*) calloc(n, sizeof(int));
   
    for (int i = 0; i < n; ++i) {
        printf("%dº value: ", i+1);
        scanf("%d", &a[i]);
    }
    
    recursiveInsertion(a, n - 1);
    printArray(a, n);
    free(a);
    
    return 0;
}