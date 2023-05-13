#include <stdio.h>
#include <stdbool.h>


bool primo_recursivo(int n, int divisor, int v[])
{
  if (divisor > n) {
    return false;
  }
  
  if (n % divisor == 0) {
    v[0] += 1;
  }

  primo_recursivo(n, divisor + 1, v);
  
  if (v[0] == 2) {
    return true;
  }

  return false;
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

  int v[] = {0};
  if (primo_recursivo(n, 1, v)) {
    printf("Função Recursiva: O número %d é primo.\n", n);
  } 
  else {
    printf("Função Recursiva: %d não é primo.\n", n);
  }  

  
  return 0;
}