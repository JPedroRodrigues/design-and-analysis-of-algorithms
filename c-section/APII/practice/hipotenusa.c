#include <stdio.h>
#include <math.h>

int main() {
  float cat1, cat2, hip;

  printf("Calculo da Hipotenusa\n");

  printf("Digite o valor do primeiro cateto: ");
  scanf("%f", &cat1);
  printf("Agora o segundo cateto: ");
  scanf("%f", &cat2);

  hip = sqrtf((cat1 * cat1 ) + (cat2 * cat2));

  printf("Um triângulo retângulo com lados %.0f e %.0f tem uma hipotenusa igual a %.2f.\n", cat1, cat2, hip);

return 0;
}
