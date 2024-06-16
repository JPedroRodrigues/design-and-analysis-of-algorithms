#include <stdio.h>

int main(){
    int x = 2;
    int y = 4;

    x *= ++x;
    printf("Valor de X = %d\n", x);

    y *= 10 + y--;
    printf("Valor de Y = %d\n", y);

    return 0;
}
