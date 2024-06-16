/*
* Projeto e Análise de Algoritmos II: Mini-lista 01
* Nome: João Pedro Rodrigues Vieira
* RA: 10403595
* Turma: 04G
*/

#include <stdio.h>

int mdc(int x, int y) {
    if (x == y) return x;
    if (x % 2 == 0 && y % 2 == 0) return 2 * mdc(x/2, y/2);
    if (x % 2 == 0 && y % 2 == 1) return mdc(x/2, y);
    if (x % 2 == 1 && y % 2 == 0) return mdc(x, y/2);
    if (x % 2 == 1 && y % 2 == 1 && x > y) return mdc((x - y) / 2, y);
    if (x % 2 == 1 && y % 2 == 1 && y > x) return mdc(x, (y - x) / 2);
}

int main() {
    printf("Resultado %d\n", mdc(270, 192));  // Resultado: 6
    printf("Resultado %d\n", mdc(35, 10));  // Resultado: 5
    printf("Resultado %d\n", mdc(10, 15));  // Resultado: 5
    printf("Resultado %d\n", mdc(31, 2));  // Resultado: 1
    return 0;
}