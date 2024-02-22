#include <stdio.h>


int fibonacci(int n)
{
  int resposta;

  if (n <= 1) {
    return 1;
  }
  
  resposta = fibonacci(n - 1) + fibonacci(n - 2);

  return resposta;
  
}


int fibo(int n)
{
  int resposta, atual = 1, anterior = 0;

  for(int i = 0; i < n; i++) {
    resposta = atual + anterior;
    anterior = atual;
    atual = resposta;
  }

  return resposta;
}


int main0() 
{
  printf("Posição na sequência: ");
  int pos;
  scanf("%d", &pos);
  
  printf("Fibonacci iterativo na posição %d: %d\n", pos, fibo(pos));
  printf("Fibonacci recursivo na posição %d: %d\n", pos, fibonacci(pos));
  
  return 0;
}