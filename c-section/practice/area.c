#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main() {
  float raio, area;

  printf("Digite o raio do circulo: ");
  scanf("%f", &raio);

  area = M_PI * (raio * raio);

  printf("O um círculo com raio %.2f tem área igual a %.2f.\n", raio, area);

  return 0;
}
