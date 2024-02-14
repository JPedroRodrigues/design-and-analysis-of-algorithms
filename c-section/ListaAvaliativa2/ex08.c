#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void recursiveBubble(int a[], int n) {

    if (n == 0) return;

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) swap(&a[i], &a[i + 1]);
        recursiveBubble(a, n - 1);
    }
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

    int *a = (int *)calloc(n, sizeof(int));
   
    for (int i = 0; i < n; ++i) {
        printf("%dº value: ", i+1);
        scanf("%d", &a[i]);
    }
    
    recursiveBubble(a, n);
    
    printArray(a, n);

    free(a);
    return 0;
}
