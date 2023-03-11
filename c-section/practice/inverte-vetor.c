#include <stdio.h>
#define TAM 5


void inverter(int vetor[])
{
  int i;
  
  printf("\nVetor recebido: v = [%d", vetor[0]);
  
  for(i = 1; i < TAM; i++) {
    printf(", %d", vetor[i]);
  }
  
  printf("]\n");

  for(i = 0; i < TAM / 2; i++) {
    int temp = vetor[i];
    
    vetor[i] = vetor[TAM - 1 - i];
    vetor[TAM - 1 - i] = temp;
    
    if (i == 0) {
      printf("Vetor invertido: v = [%d", vetor[0]);
    }
    else {
      for(i = 1; i < TAM; i++) {
      printf(", %d", vetor[i]);
      }
      
      printf("]\n");
    }
  }
}


int main()
{
  int numeros[TAM], i;

  for(i = 0; i < TAM; i++){
    printf("Digite um número inteiro: ");
    scanf("%d", &numeros[i]);
  }

  inverter(numeros);
  
  return 0;
}
