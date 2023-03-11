#include <stdio.h>
#include <stdbool.h>

#define tamanho 5


bool crescente(int vetor[])
{
  for(int i = 1; i < tamanho; i++){
    if(vetor[i] <= vetor[i - 1]){
      return false;
    }
  }

  return true;
}


int main()
{
  int numeros[tamanho];

  for(int i = 0; i < tamanho; i++){
    printf("Digite um número inteiro: ");
    scanf("%d", &numeros[i]);
  }

  if(crescente(numeros)){
    printf("Os números foram digitados em ordem crescente!\n");
  }
  else{
    printf("Os números inseridos não estão em ordem crescente.\n");
  }
  
  return 0;
}
