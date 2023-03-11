#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define Atam 5
#define Btam 4


/*
 * Imprime os elementos presentes em um vetor.
 */
void mostrar_vetor(int v[], int n)
{
  int i;
  
  printf("Vetor = [%d", v[0]);
  
  for (i = 1; i < n; i++) {
    printf(", %d", v[i]);
  }
  
  printf("]\n");  
}


/*
 * Imprime os elementos de um conjunto A que não estão no conjunto B.
 */
void diferenca(int va[], int tamA, int vb[], int tamB)
{
  int cont = 0, diferente = 0;
  int ia, ib;

  mostrar_vetor(va, tamA);
  mostrar_vetor(vb, tamB);
  
  printf("Diferença entre os dois vetores = ");
  
  for(ia = 0; ia < tamA; ia++) {
    
    for(ib = 0; ib < tamB; ib++) {
      
      if (va[ia] != vb[ib]) {
        cont++;
      }
    }
    
    if (cont == tamB) {
      diferente ++;

      if (diferente == 1) {
        printf("[%d", va[ia]);
      }
      else {
        printf(", %d", va[ia]);
      }
    }
    cont = 0;
  }
  
  printf("]\n");
}


int main()
{
  srand(time(NULL));

  int a[Atam], b[Btam], i;

  for (i = 0; i < Atam; i++) {
    a[i] = rand() % 10 + 1;
  }

  for (i =  0; i < Btam; i++) {
    b[i] = rand() % 10 + 1;
  }
  
  diferenca(a, Atam, b, Btam);
  
  return 0;
}
