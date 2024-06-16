#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void recursiveSelection(int a[], int n, int i) {
    if (i == n - 1) return;

    int min = i;

    for (int j = i + 1; j < n; ++j) {
        if (a[j] < a[min]) {
            min = j;
        }
    }
    swap(&a[i], &a[min]);

    recursiveSelection(a, n, i + 1);
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
        printf("%d. value: ", i+1);
        scanf("%d", &a[i]);
    }
    
    recursiveSelection(a, n, 0);
    printArray(a, n);
    free(a);

    return 0;
}
