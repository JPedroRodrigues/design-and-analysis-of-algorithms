#include <stdio.h>

/**
  * Retorna a soma dos valores de a, b, c.
  */
float soma(float a, float b, float c)
{  
  return a + b + c;
}


int main(void)
{
  float n1, n2, n3, s;

  printf("Insira o primeiro número: "); scanf("%f", &n1);
  printf("Agora o segundo número: "); scanf("%f", &n2);
  printf("Por fim, o terceiro: "); scanf("%f", &n3);

  s = soma(n1, n2, n3);
  
  printf("A soma dos três números é %.2f.\n", s);
  
  return 0;
}
