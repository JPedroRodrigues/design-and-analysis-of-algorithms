#include <stdio.h>
#include <stdlib.h>


void print(int *a, int n) {
    printf("[%d", a[0]);
    for (int i = 1; i < n; i++) printf(", %d", a[i]);
    printf("]\n");
}


void change(int *c, int lenC, int n) {
    int *s = (int *) calloc(n, sizeof(int));
    int lenS = 0;

    int sum = 0, coin;

    while (lenC != 0 && sum < n) {
        coin = c[lenC - 1];

        if (sum + coin <= n) {
            sum += coin;
            s[lenS++] = coin;
        } else --lenC;
    }

    if (sum == n) print(s, lenS);
    else printf("Impossible to solve\n");
}


int main(void) {
    int n = 8;
    int c[] = {1, 4, 6};
    int lenC = sizeof(c) / sizeof(int);

    change(c, lenC, n); 
    
    return 0;
}