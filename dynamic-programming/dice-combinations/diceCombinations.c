#include <stdio.h>
#include <limits.h>

int diceCombinations(int number, int *diceNumbers, int n) {
    if (number == 0) return 1;

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (number - diceNumbers[i] >= 0) {
            count += diceCombinations(number - diceNumbers[i], diceNumbers, n);
        }
    }
    return count;
}


int main() {
    int diceNumbers[] = {1, 2, 3, 4, 5, 6};
    int n; scanf("%d", &n);
    
    printf("%d\n", diceCombinations(n, diceNumbers, 6));

    return 0;
}