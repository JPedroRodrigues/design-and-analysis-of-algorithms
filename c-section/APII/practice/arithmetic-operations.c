/*  Segundo exemplo dado em aula
    Operações aritméticas na linguagem C
*/

#include <stdio.h>

int main()
{
    // É necessário declarar o tipo e o nome das variáveis anteriormente
    int a;
    int b;
    int div;
    int resto;

    printf("Digite o primeiro número: ");
    scanf("%d", &a);

    printf("Digite o segundo número: ");
    scanf("%d", &b);

    div = a / b;
    resto = a % b;

    printf("Divisão = %d; Resto = %d\n", div, resto);

    return 0;
}
