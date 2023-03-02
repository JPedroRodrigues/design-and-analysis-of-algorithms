#include <stdio.h>
#include <stdbool.h>


bool primo(int n)
{
  int quantidade = 0;

  for (int i = 1; i <= n; i++)
  {
    if (n % i == 0)
    {
      quantidade++;
    }
  }

  if (quantidade == 2)
  {
    return true;
  } 
  return false;
}


int main()
{
  int n1, n2;

  printf("N1: "); scanf("%d", &n1);
  printf("N2: "); scanf("%d", &n2);

  printf("Lista dos números entre %d e %d (inclusive):", n1, n2);
  for (int i = n1; i <= n2; i++){
    if (primo(i))
    {
      printf(" %d", i);
    }
  }

  return 0;
}
