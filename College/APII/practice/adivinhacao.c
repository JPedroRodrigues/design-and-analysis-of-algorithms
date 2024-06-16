#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int numero_aleatorio, palpite;

  // Gerador de número aleatório
  srand(time(NULL));
  numero_aleatorio = 1 + (rand() % 100);

  // Entrada
  printf("Tente adivinhar qual número entre 1 e 100 estou pensando.\n");
  printf("Seu palpite: "); scanf("%d", &palpite);

  // Validação da entrada
  while (palpite < 1 || palpite > 100)
  {
    printf("Ops! O número precisa estar entre 1 e 100: ");
    scanf("%d", &palpite);
  }

  // Resultado
  if (palpite < numero_aleatorio)
  {
    printf("Você chutou muito baixo! O valor correto é %d.\n", numero_aleatorio);
  }
  else if (palpite > numero_aleatorio)
  {
    printf("Você chutou muito alto! O valor correto é %d.\n", numero_aleatorio);
  }
  else {
    printf("Parabéns!!! Você acertou!\n");
  }

  return 0;
}