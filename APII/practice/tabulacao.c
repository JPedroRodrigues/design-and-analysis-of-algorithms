/* Refinamentos sucessivos top-down
topo: gerar uma tabela multiplicativa

imprimir as leis gerais de multiplicação tabuladas
imprirmir abaixo destas leis as multiplicações até certo ponto

inicializo a variável i
imprimir 1 * N\t\t10 * N\t\t100 * N
para i começando em 1 e terminando em 10, sendo icrementado 1 à variável
    imprimo as multiplicações espaçadas por \t\t
*/

#include <stdio.h>

int main()
{
    int i = 1;

    printf("1 * N\t\t10 * N\t\t100 * N\n");
    for(i; i <= 10; i++){
        printf("%d\t\t%d\t\t%d\n", i * 1, i * 10, i * 100);
    }

    return 0;
}
