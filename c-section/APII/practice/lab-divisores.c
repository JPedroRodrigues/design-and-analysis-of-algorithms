#include <stdio.h>
#include <stdbool.h>

/**
  * Retorna true se um número n for divisível pelo número d e false caso contrário.
  */
bool divisor(int n, int d)
{
  return n % d == 0;
}

/**
  * Retorna a quantidade de divisores que um número m possui.
  */
int quantidade_divisores(int m)
{
  int quantidade = 0;

  for(int i = 1; i <= m; i++)
  {
    if (divisor(m, i))
    {
      quantidade++;
    }
  }

  return quantidade;
}


int main()
{
  int numero;
  printf("Digite o número: "); scanf("%d", &numero);

  int numero_divisores = quantidade_divisores(numero);
  printf("O número %d possui %d divisores.\n", numero, numero_divisores);
  
  return 0;
}
