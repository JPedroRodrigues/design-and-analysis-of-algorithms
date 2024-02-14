#include <stdio.h>

int countDigits(int n, int c) {
    
    if (n == 0) return c;

    ++c;
    return countDigits(n / 10, c);
}


int main() {

    int n; 

    printf("Enter a number: "); 
    scanf("%d", &n);
    
    if (n == 0) printf("1\n");
    else {
        int numDigits = countDigits(n, 0);
        printf("%d\n", numDigits);
    }
    
    return 0;
}
