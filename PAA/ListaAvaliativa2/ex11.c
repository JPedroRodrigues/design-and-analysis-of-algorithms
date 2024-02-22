#include <stdio.h>
#include <stdlib.h>


int findLargest(int a[], int l, int r) {

    int m = (l + r) / 2;

    if (l == r) return a[m];   

    int x = findLargest(a, l, m);      // 1st half
    int y = findLargest(a, m + 1, r);  // 2nd half
    
    return (x >= y) ? x : y;
}


int main() {

    int n;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *a = (int*)calloc(n, sizeof(int));
   
    for (int i = 0; i < n; ++i) {
        printf("%d. value: ", i+1);
        scanf("%d", &a[i]);
    }

    int largest = findLargest(a, 0, n - 1);
    printf("Largest number: %d\n\n", largest);
    free(a);

    return 0;
}
