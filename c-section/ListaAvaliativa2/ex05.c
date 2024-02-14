#include <stdio.h>
#include <stdlib.h>

int arraySum(int a[], int n, int sum) {
    
    if (n == 0) return sum;

    sum += a[n - 1];

    return arraySum(a, n - 1, sum);
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

    int sumArray = arraySum(a, n, 0);
    printf("%d\n", sumArray);
    
    free(a);
    return 0;
}
