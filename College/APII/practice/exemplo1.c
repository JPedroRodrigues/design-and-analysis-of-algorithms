#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main1()
{
  int dado;
  int palpite;
  srand(time(NULL));

  dado = 1 + (rand() % 6);

  printf("Lancei o dado! Tente advinhar o seu valor...\n");
  printf("Seu palpite: "); scanf("%d", &palpite);

  if (palpite == dado)
  {
    printf("Você advinhou!\n");
  }
  else
  {
    printf("Não foi desta vez...\n");
  }
  printf("Valor do dado lançado: %d\n", dado);

  return 0;
}