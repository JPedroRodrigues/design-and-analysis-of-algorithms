#include <stdio.h>

int sumDigits(int n, int sum) {
    
    if (n == 0) return sum;

    sum += n % 10;

    return sumDigits(n / 10 , sum);
}


int main() {

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    int sumDig = sumDigits(n, 0); 
    printf("%d\n", sumDig);

    return 0;
}


