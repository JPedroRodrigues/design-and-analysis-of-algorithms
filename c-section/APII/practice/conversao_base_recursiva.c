#include <stdio.h>

/* 
   Podemos usar a função strcpy()
   que está na biblioteca <string.h>
   para transferir para um vetor uma string

   Ou mesmo strcat() pode ajudar. Ela concateca
   caracteres.

   itoa() transforma um inteiro em string.
   Necessita da <stdlib.h>
*/

/*
  * Forma recursiva da conversão de número decimal em binário.
  */
void decimal_binario(int n)
{
  if (n <= 0) {
    return;
  }

  int resto = n % 2;
  decimal_binario(n / 2);

  printf("%d", resto);
}

/*
  * Forma iterativa da conversão de número decimal em binário.
  */
void d_b(int n)
{
  int v[33];
  int bit = 0;
  int resto;
  
  while (n > 0) {
    resto = n % 2;
    n = n / 2;

    v[bit] = resto;
    bit++;
  }

  for(int i = bit - 1; i >= 0; i--) {
    printf("%d", v[i]);
  }
  
}


int main1() 
{
  int decimal;
  printf("Número decimal: ");
  scanf("%d", &decimal);

  printf("Conversão iterativa: ");
  d_b(decimal);
  printf("\n");

  printf("Conversão recursiva: ");
  decimal_binario(decimal);
  printf("\n");
  
  return 0;
}
