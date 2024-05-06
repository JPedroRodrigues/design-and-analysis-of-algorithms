#include <stdio.h>

typedef struct {
    char c;
    int freq;
} Data;

int minimum(int *frequency, int l, int r) {
    if (l >= r) return frequency[l];
    int m = (l + r) / 2;
    int x = minimum(frequency, l, m);
    int y = minimum(frequency, m + 1, r);

    return x < y ? x : y;
}


int main() {
    Data c[] = {{'a', 45}, {'b', 13}, {'c', 12}, {'d', 16}, {'e', 9}, {'f', 5}};

    // char alph[] = "abcdef";
    // int frequency[] = {45, 13, 12, 16, 9, 5};


    return 0;
}