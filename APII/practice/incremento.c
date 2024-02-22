// Uso do operador de incremento, ++

#include <stdio.h>

int main(){
    int a = 0;
    a++;
    printf("O valor de a: %d\n", a);
    ++a;
    printf("O valor de a, novamente: %d\n", a);

    int b;
    b = 10 + a++;
    printf("Operação b = 10 + a++\n");
    printf("O valor de b: %d\n", b);
    
    int c;
    c = 10 + ++a;
    printf("Operação c = 10 + ++a\n");
    printf("O valor de c: %d\n", c);

    return 0;
}
