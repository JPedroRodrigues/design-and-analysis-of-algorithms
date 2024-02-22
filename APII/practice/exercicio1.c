#include <stdio.h>

int main() {
  int n1, n2;

  printf("Digite um número: ");
  scanf("%d", &n1);
  printf("Agora digite outro número: ");
  scanf("%d", &n2);

  int soma = n1 + n2;
  int subtr = n1 - n2;
  int mult = n1 * n2;
  int div = n1 / n2;

  printf("Soma = %d; Subtração = %d\n", soma, subtr);
  printf("Multiplicação = %d; Divisão inteira = %d\n", mult, div);

  return 0;
}
