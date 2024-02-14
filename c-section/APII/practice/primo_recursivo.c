#include <stdio.h>
#include <stdbool.h>


bool primo_recursivo(int n, int divisor)
{
  if (divisor > n) return false;

  if (n == divisor) return true;

  else if (n % divisor == 0) return false;

  return primo_recursivo(n, divisor + 1);
}


bool primo(int n)
{
  if (n == 1) {
    return false;
  }
  
  int c = 0;
  
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      c++;
    }
  }

  if (c == 2) {
    return true;
  }
  
  return false;
}


int main()
{
  int n;
  
  printf("Digite um inteiro positivo: ");
  scanf("%d", &n);

  if (primo(n)) {
    printf("Função Iterativa: O número %d é primo.\n", n);
  } 
  else {
    printf("Função Iterativa: %d não é primo.\n", n);
  }

  if (primo_recursivo(n, 2)) {
    printf("Função Recursiva: O número %d é primo.\n", n);
  } 
  else {
    printf("Função Recursiva: %d não é primo.\n", n);
  }  

  
  return 0;
}