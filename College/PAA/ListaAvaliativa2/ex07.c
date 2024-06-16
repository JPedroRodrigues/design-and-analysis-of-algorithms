#include <stdio.h>
#include <stdlib.h>

int arrayGreater(int a[], int n, int greater) {

    if (n == 0) return greater;

    if (a[n - 1] > greater) greater = a[n - 1];    

    arrayGreater(a, n - 1, greater);
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

    int greater = arrayGreater(a, n, a[0]);
    printf("%d\n", greater);
    
    free(a);
    return 0;
}
