#include <stdio.h>


/*
  * Imprime os elementos da intersecção entre dois vetores.
  */
void interseccao(int va[], int vb[], int tam_a, int tam_b)
{
  int i, j, intersec[10];

  printf("Intersecção: ");
  
  for(i = 0; i < tam_a; i++) {
    for(j = 0; j < tam_b; j++) {
      if (va[i] == vb[j]) {
        printf("%d ", va[i]);
      }
    }
  }
  printf("\n");
}


int main()
{
  int a[] = {7, 2, 5, 8, 4};
  int b[] = {4, 2, 9, 5};

  interseccao(a, b, sizeof(a) / sizeof(int), sizeof(b) / sizeof(int));

  return 0;
}