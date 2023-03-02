#include <stdio.h>
#include <math.h>


float somatorio(int n)
{
  float total = 0.0;
  for (int k = 1; k <= n; k++){
    total += (k / pow(k, 2)) * (pow(-1, k + 1));
  }

  return total;
}


int main()
{
  printf("Digite um número inteiro: ");
  int numero;
  scanf("%d", &numero);

  printf("Aplicando uma função, obtemos o número %f.\n", somatorio(numero));
}
